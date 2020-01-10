/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:50:09 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/10 19:28:22 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			put_pixel(int x, int y, int color, SDL_Surface *sur)
{
	int			*pixels;

	pixels = (int *)sur->pixels;
	pixels[sur->w * y + x] = color;
}

int				ray_trace(t_vector dir, t_rt *rt)
{
	t_math		*math;
	t_vector	normal;
	double		closest_t;

	math = ft_safe_malloc(sizeof(t_math));
	init_obj(&(math->closest_obj));
	closest_object(&(math->closest_obj), dir, &closest_t, rt);
	if (closest_t == MAX)
		return (0);
	math->point = ft_vec_sum(rt->camera,
				ft_vec_multiplication_num(dir, closest_t));
	math->normal = get_normal(&(math->closest_obj), math->point);
	return (color_parse(math, rt->light));
}

void			render(t_rt *rt)
{
	t_img		img;
	t_vector	dir;
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
			dir = calculate_direction(img.curnt_x, img.curnt_y,
				rt->sdl->sur->w, rt->sdl->sur->h);
			color = ray_trace(dir, rt);
			put_pixel(img.curnt_x + img.half_width,
				img.curnt_y + img.half_height, color, rt->sdl->sur);
		}
	}
}
