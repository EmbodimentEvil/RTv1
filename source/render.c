/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:50:09 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/08 20:34:14 by sleonia          ###   ########.fr       */
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
	t_vector	point;
	t_vector	normal;
	t_obj		closest_obj;
	double		closest_t;

	closest_obj.pos.x = 0;
	closest_obj.pos.y = 0;
	closest_obj.pos.z = 0;
	closest_object(&closest_obj, dir, &closest_t, rt);
	point = ft_vec_sum(rt->camera,
				ft_vec_multiplication_num(dir, closest_t));
	normal = get_normal(&closest_obj, point);
	return (color_parse(point, normal, rt->light, closest_obj, dir));
}

void			draw(t_rt *rt)
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
