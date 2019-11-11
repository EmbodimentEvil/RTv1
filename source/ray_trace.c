/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:46:14 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/11 19:01:44 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double			vec_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector		canvas_to_viewport(int x, int y, t_rt *rt)
{
	t_vector		vector;

	vector.x = (double)x * 1.15 / rt->sdl.sur->w;
	vector.y = (double)y * 0.62 / rt->sdl.sur->h;
	vector.z = 1;
	return (vector);
}

void			intersect_ray(t_rt *rt, t_point o, t_vector d, t_figures figure)
{
	t_vector	oc;
	double		k1;
	double		k2;
	double		k3;
	double		discriminant;

	oc.x = o.x - figure.point.x;
	oc.y = o.y - figure.point.y;
	oc.z = o.z - figure.point.z;
	k1 = vec_dot(d, d);
	k2 = 2 * vec_dot(oc, d);
	k3 = vec_dot(oc, oc) - figure.radius * figure.radius;
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
	figure->color = rgb(0, 0, 0);
	figure->radius = 0;
	figure->point.x = 0;
	figure->point.y = 0;
	figure->point.z = 0;
}

int				ray_trace(t_point point, t_vector vector, double min,
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
	return (figure.radius == 0 ? rgb(0, 0, 0) : figure.color);
	// return (figure.radius == 0 ? rgb(255, 255, 255) : figure.color);
}
