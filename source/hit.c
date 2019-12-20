/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:32:27 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 19:15:55 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_root			hit_cone(t_vector o, t_vector d, t_obj sphere)
{
	t_root		root;

	return (root);	
}

t_root			hit_cylinder(t_vector o, t_vector d, t_obj sphere)
{
	t_root		root;

	return (root);
}

t_root			hit_sphere(t_vector o, t_vector d, t_obj sphere)
{
	t_root		root;
	t_vector	oc;
	t_vector	res;
	double		discriminant;

	oc = ft_vec_subtract(o, sphere.pos);
	res.x = ft_vec_dot(d, d);
	res.y = 2 * ft_vec_dot(oc, d);
	res.z = ft_vec_dot(oc, oc) - sphere.radius * sphere.radius;
	discriminant = res.y * res.y - 4 * res.x * res.z; //mb change * to <<
	if (discriminant < 0)
		return ((t_root){INFINITY, INFINITY});
	root.a = (-res.y + sqrt(discriminant)) / (2 * res.x); //mb change * to <<
	root.b = (-res.y - sqrt(discriminant)) / (2 * res.x); //mb change * to <<
	return (root);
}

t_root			hit_plane(t_vector o, t_vector d, t_obj sphere)
{
	t_root		root;

	return (root);
}
