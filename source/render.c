/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:50:09 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/11 17:28:58 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			put_pixel(int x, int y, int color, SDL_Surface *sur)
{
	int			*pixels;

	pixels = (int *)sur->pixels;
	pixels[sur->w * y + x] = color;
}

int				ray_trace(t_rt *rt)
{
	closest_object(rt);
	if (rt->math->closest_t == MAX || !rt->math->closest_obj)
		return (0);
	rt->math->point = ft_vec_sum(rt->camera,
				ft_vec_multiplication_num(rt->math->dir, rt->math->closest_t));
	rt->math->normal = get_normal(rt->math->closest_obj, rt->math->point);
	return (color_parse(rt));
}

void			render(t_rt *rt)
{
	t_img		img;
	int			color;

	img.curnt_y = -(rt->sdl->sur->h >> 1) - 1;
	img.finish_y = rt->sdl->sur->h >> 1;
	img.half_width = rt->sdl->sur->w >> 1;
	img.half_height = rt->sdl->sur->h >> 1;
	while (++img.curnt_y < img.finish_y)
	{
		img.curnt_x = -(rt->sdl->sur->w >> 1) - 1;
		img.finish_x = (rt->sdl->sur->w >> 1);
		while (++img.curnt_x < img.finish_x)
		{
			rt->math->dir = calculate_direction(img.curnt_x, img.curnt_y,
				rt->sdl->sur->w, rt->sdl->sur->h);
			color = ray_trace(rt);
			put_pixel(img.curnt_x + img.half_width,
				img.curnt_y + img.half_height, color, rt->sdl->sur);
		}
	}
}
