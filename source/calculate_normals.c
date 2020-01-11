/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_normals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:53:37 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/11 16:06:56 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		cone_normal(t_obj *obj, t_vector point)
{
	t_vector	normal;
	double		m;
	double		k;

	k = (1 + obj->radius * obj->radius);
	m = ft_vec_dot(ft_vec_subtract(point, obj->pos), obj->dir);
	normal = ft_vec_multiplication_num((obj->dir), (float)(m * k));
	normal = ft_vec_subtract(ft_vec_subtract(point, obj->pos), normal);
	normal = ft_vec_multiplication_num(normal,
		(double)(1.f / ft_vec_length(normal)));
	return (normal);
}

t_vector		cylinder_normal(t_obj *obj, t_vector point)
{
	t_vector	normal;
	double		m;

	m = ft_vec_dot(ft_vec_subtract(point, obj->pos), obj->dir);
	obj->dir = ft_vec_multiplication_num(obj->dir,
		(double)(1.f / ft_vec_length(obj->dir)));
	normal = ft_vec_multiplication_num(obj->dir, m);
	normal = ft_vec_subtract(ft_vec_subtract(point, obj->pos), normal);
	normal = ft_vec_multiplication_num(normal,
		(double)(1.f / ft_vec_length(normal)));
	return (normal);
}

t_vector		sphere_normal(t_obj *obj, t_vector point)
{
	t_vector	normal;

	normal = ft_vec_subtract(point, obj->pos);
	normal = ft_vec_multiplication_num(normal,
		(double)(1.f / ft_vec_length(normal)));
	return (normal);
}

t_vector		plane_normal(t_obj *obj, t_vector point)
{
	t_vector	normal;

	normal = obj->dir;
	return (normal);
}

t_vector		get_normal(t_obj *obj, t_vector point)
{
	if (obj->type == Cone)
		return (cone_normal(obj, point));
	if (obj->type == Cylinder)
		return (cylinder_normal(obj, point));
	if (obj->type == Sphere)
		return (sphere_normal(obj, point));
	if (obj->type == Plane)
		return (plane_normal(obj, point));
	return ((t_vector){0, 0, 0});
}
