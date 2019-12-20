/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:50:09 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 19:18:29 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			put_pixel(int x, int y, int color, SDL_Surface *sur)
{
	int			*pixels;

	pixels = (int *)sur->pixels;
	pixels[sur->w * y + x] = color;
}

	int			ray_trace(t_vector point, t_vector vector, double min,
					double max, t_rt *rt)
{
	double		closest_t;
	t_obj		obj;
	t_obj		*tmp = rt->obj;

	closest_t = INFINITY;
	init_figure(&obj);
	while (tmp)
	{
		if (rt->calculate.t1 >= min && rt->calculate.t1 <= max
			&& rt->calculate.t1 < closest_t)
		{
			closest_t = rt->calculate.t1;
			obj = *tmp;
		}
		if (rt->calculate.t2 >= min && rt->calculate.t2 <= max
			&& rt->calculate.t2 < closest_t)
		{
			closest_t = rt->calculate.t2;
			obj = *tmp;
		}
		tmp = tmp->next;
	}
	return (obj.radius == 0 ? rgb(0, 0, 0) : rgb((int)obj.color.x, (int)obj.color.y, (int)obj.color.z));
}

void			draw(t_rt *rt)
{
	t_img		img;
	t_vector	vector;
	t_vector	point;
	int			color;

	img.curnt_y = -rt->sdl->sur->h >> 2 - 1;
	img.finish_y = rt->sdl->sur->h >> 2;
	img.half_width = rt->sdl->sur->w >> 2;
	img.half_height = rt->sdl->sur->h >> 2;
	while (++img.curnt_y < img.finish_y)
	{
		img.curnt_x = -rt->sdl->sur->w >> 2 - 1;
		img.finish_x = rt->sdl->sur->w >> 2;
		while (++img.curnt_x < img.finish_x)
		{
			vector = calculate_fov(img.curnt_x, img.curnt_y,
				rt->sdl->sur->w, rt->sdl->sur->h);
			color = ray_trace(point, vector, 1, INFINITY, rt);
			put_pixel(img.curnt_x + img.half_width,
				img.curnt_y + img.half_height, color, rt->sdl->sur);
		}
	}
}
