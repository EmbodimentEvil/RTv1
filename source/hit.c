/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:32:27 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/23 03:06:38 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_root			hit_cone(t_vector vec, t_obj *cone)
{
	t_root		root;

	return (root);	
}

t_root			hit_cylinder(t_vector vec, t_obj *cylinder)
{
	t_root		root;

	return (root);
}

t_root			hit_sphere(t_vector vec, t_obj *sphere)
{
	t_root		root;
	t_vector	oc;
	t_vector	res;
	double		discriminant;

	oc = ft_vec_subtract((t_vector){0, 0, 0}, sphere->pos);
	res.x = ft_vec_dot(vec, vec);
	res.y = 2 * ft_vec_dot(oc, vec);
	res.z = ft_vec_dot(oc, oc) - sphere->radius * sphere->radius;
	// discriminant = res.y * res.y - ((int)(res.x * res.z) << 2);
	discriminant = res.y * res.y - 4 * res.x * res.z; //mb change * to <<
	if (discriminant < 0)
		return ((t_root){INFINITY, INFINITY});
	root.a = (-res.y + sqrt(discriminant)) / (res.x * 2); //mb change * to <<
	root.b = (-res.y - sqrt(discriminant)) / (res.x * 2);
	// root.a = (-res.y + sqrt(discriminant)) / ((int)res.x << 1);
	// root.b = (-res.y - sqrt(discriminant)) / ((int)res.x << 1);
	return (root);
}

t_root			hit_plane(t_vector vec, t_obj *sphere)
{
	t_root		root;

	return (root);
}

t_root			hit_obj(t_vector vec, t_obj *obj)
{
	if (obj->type == Sphere)
		return (hit_sphere(vec, obj));
	else if (obj->type == Plane)
		return (hit_plane(vec, obj));
	else if (obj->type == Cone)
		return (hit_cone(vec, obj));
	else if (obj->type == Cylinder)
		return (hit_cylinder(vec, obj));
	return ((t_root){-1.0, -1.0});
}
