/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:32:27 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 12:38:01 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			intersect_sphere(t_rt *rt, t_vector point,
					t_vector vector, t_figures figure)
{
	t_vector	oc;
	double		k1;
	double		k2;
	double		k3;
	double		discriminant;

	oc.x = point.x - figure.point.x;
	oc.y = point.y - figure.point.y;
	oc.z = point.z - figure.point.z;
	k1 = ft_vec_dot(vector, vector);
	k2 = 2 * ft_vec_dot(oc, vector);
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