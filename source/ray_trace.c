/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:46:14 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 13:48:59 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ray_trace(t_rt *rt)
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
			vector = canvas_to_viewport(img.curnt_x, img.curnt_y, rt);
			color = ray_trace(point, vector, 1, INFINITY, rt);
			put_pixel(img.curnt_x + img.half_width,
				img.curnt_y + img.half_height, color, rt->sdl->sur);
		}
	}
}

