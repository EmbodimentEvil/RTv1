/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:46:14 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 21:50:40 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	Calculate FOV to fullscreen image
*/

t_vector		canvas_to_viewport(int x, int y, t_rt *rt)
{
	t_vector		vector;

	vector.x = (double)x * 1.15 / rt->sdl.sur->w;
	vector.y = (double)y * 0.62 / rt->sdl.sur->h;
	vector.z = 1;
	return (vector);
}

void			intersect_ray(t_rt *rt, t_vector o, t_vector d, t_figures figure)
{
	t_vector	oc;
	double		k1;
	double		k2;
	double		k3;
	double		discriminant;

	oc.x = o.x - figure.point.x;
	oc.y = o.y - figure.point.y;
	oc.z = o.z - figure.point.z;
	k1 = ft_vec_dot(d, d);
	k2 = 2 * ft_vec_dot(oc, d);
	k3 = ft_vec_dot(oc, oc) - figure.radius * figure.radius;
	discriminant = k2 * k2 - 4 * k1 * k3;
	if (discriminant < 0)
	{
		rt->calculate.t1 = INFINITY;
		rt->calculate.t2 = INFINITY;
	}
	rt->calculate.t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
	rt->calculate.t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
}

void			init_figure(t_figures *figure)
{
	figure->radius = 0;
	figure->color.x = 0;
	figure->color.y = 0;
	figure->color.z = 0;
	figure->radius = 0;
	figure->point.x = 0;
	figure->point.y = 0;
	figure->point.z = 0;
}


int				ray_trace(t_vector point, t_vector vector, double min,
					double max, t_rt *rt)
{
	double		closest_t;
	t_figures	figure;
	t_figures	*tmp = rt->figure;

	closest_t = INFINITY;
	init_figure(&figure);
	while (tmp)
	{
		intersect_ray(rt, point, vector, *tmp);
		if (rt->calculate.t1 >= min && rt->calculate.t1 <= max
			&& rt->calculate.t1 < closest_t)
		{
			closest_t = rt->calculate.t1;
			figure = *tmp;
		}
		if (rt->calculate.t2 >= min && rt->calculate.t2 <= max
			&& rt->calculate.t2 < closest_t)
		{
			closest_t = rt->calculate.t2;
			figure = *tmp;
		}
		tmp = tmp->next;
	}
	return (figure.radius == 0 ? rgb(0, 0, 0) : rgb((int)figure.color.x, (int)figure.color.y, (int)figure.color.z));
	// return (figure.radius == 0 ? rgb(255, 255, 255) : figure.color);
}

// int				ray_trace(t_vector point, t_vector vector, double min,
// 					double max, t_rt *rt)
// {
// 	double		closest_t;
// 	t_figures	figure;
// 	t_vector	point;
// 	t_figures	*tmp = rt->figure;
// 	t_vector	normal;


// 	closest_t = INFINITY;
// 	init_figure(&figure);
// 	while (tmp)
// 	{
// 		intersect_ray(rt, point, vector, *tmp);
// 		if (rt->calculate.t1 >= min && rt->calculate.t1 <= max
// 			&& rt->calculate.t1 < closest_t)
// 		{
// 			closest_t = rt->calculate.t1;
// 			figure = *tmp;
// 		}
// 		if (rt->calculate.t2 >= min && rt->calculate.t2 <= max
// 			&& rt->calculate.t2 < closest_t)
// 		{
// 			closest_t = rt->calculate.t2;
// 			figure = *tmp;
// 		}
// 		tmp = tmp->next;
// 	}
// 	if (figure.radius == 0)
// 		return (rgb(0, 0, 0));
// 	return (figure.radius == 0 ? rgb(0, 0, 0) : figure.color);
	// point = ft_vec_multiplication_num(vector, closest_t);
	// point.x = vector.x + point.x;
	// point.y = vector.y + point.y;
	// point.z = vector.z + point.z;
	// normal.x = point.x - figure.point.x;
	// normal.y = point.y - figure.point.y;
	// normal.z = point.z - figure.point.z;
	// normal = ft_vec_multiplication_num(normal, (double)(1.0 / vec_length(normal)));
	// color.x = figure.color & 0xFF;
	// color.y = (figure.color >> 8) & 0xFF;
	// color.z = (figure.color >> 16) & 0xFF;
	// color = (ft_vec_multiplication_num(color, compute_light(point, normal, rtv->lights, figure.specular, vec_multiple_num(d, -3))));
	// if (color.x > 255)
	// 	color.x = 255;
	// if (color.y > 255)
	// 	color.y = 255;
	// if (color.z > 255)
	// 	color.z = 255;
	// int rgb = (((int)color.x&0xff)<<16)|(((int)color.y&0xff)<<8)|((int)color.z&0xff);
	// return (rgb);
// }
