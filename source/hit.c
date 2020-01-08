/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:32:27 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/08 20:19:45 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_root			hit_cone(t_vector dir, t_vector camera, t_obj *cone)
{
	t_vector	res;
	float		discrim;
	t_root		root;
	float		k;

	k = 1 + cone->radius * cone->radius;
	res.x = ft_vec_dot(dir, dir) -
			k * (float)pow(ft_vec_dot(dir, cone->direction), 2.0);
	res.y = 2 * (ft_vec_dot(dir, ft_vec_subtract(camera, cone->pos)) -
			k * ft_vec_dot(dir, cone->direction) *
			ft_vec_dot(ft_vec_subtract(camera, cone->pos), cone->direction));
	res.z = ft_vec_dot(ft_vec_subtract(camera, cone->pos), ft_vec_subtract(camera, cone->pos)) -
			k * (float)pow(ft_vec_dot(ft_vec_subtract(camera, cone->pos), cone->direction), 2);
	discrim = res.y * res.y - (4.0f * res.x * res.z);
	if (discrim < 0)
	{
		return (t_root){-1, -1};
	}
	root.a = ((-res.y + sqrtf(discrim)) / (2.0 * res.x));
	root.b = ((-res.y - sqrtf(discrim)) / (2.0 * res.x));
	return (root);
}

t_root			hit_cylinder(t_vector dir, t_vector camera, t_obj *cylinder)
{
	t_vector	res;
	double		discrim;
	t_root		root;

	res.x = ft_vec_dot(dir, dir) -
			(float)pow(ft_vec_dot(dir, cylinder->direction), 2.0);
	res.y = (ft_vec_dot(dir, ft_vec_subtract(camera, cylinder->pos)) -
			ft_vec_dot(dir, cylinder->direction) *
			ft_vec_dot(ft_vec_subtract(camera, cylinder->pos), cylinder->direction)) * 2.0f;
	res.z = ft_vec_dot(ft_vec_subtract(camera, cylinder->pos), ft_vec_subtract(camera,
			cylinder->pos)) - (float)pow(ft_vec_dot(ft_vec_subtract(camera, cylinder->pos),
					cylinder->direction), 2) -
			(cylinder->radius * cylinder->radius);
	discrim = res.y * res.y - (4.0 * res.x * res.z);
	if (discrim < 0)
		return ((t_root){-1, -1});
	root.a = ((-res.y + sqrt(discrim)) / (2.0 * res.x));
	root.b = ((-res.y - sqrt(discrim)) / (2.0 * res.x));
	return (root);
}

t_root			hit_sphere(t_vector dir, t_vector camera, t_obj *sphere)
{
	t_root		root;
	t_vector	oc;
	t_vector	res;
	double		discriminant;

	oc = ft_vec_subtract(camera, sphere->pos);
	res.x = ft_vec_dot(dir, dir);
	res.y = 2 * ft_vec_dot(oc, dir);
	res.z = ft_vec_dot(oc, oc) - sphere->radius * sphere->radius;
	discriminant = res.y * res.y - 4 * res.x * res.z;
	if (discriminant < 0)
		return ((t_root){INFINITY, INFINITY});
	root.a = (-res.y + sqrt(discriminant)) / ((int)res.x << 1);
	root.b = (-res.y - sqrt(discriminant)) / ((int)res.x << 1);
	return (root);
}

t_root			hit_plane(t_vector dir, t_vector camera, t_obj *plane)
{
	t_root		root;

	root = (t_root){-1, -1};
	if (plane->direction.x != 0 || plane->direction.y != 0 || plane->direction.z != 0)
		root.a = ft_vec_dot(plane->direction, ft_vec_subtract(plane->pos, camera)) /
			ft_vec_dot(plane->direction, dir);
	root.b = -1.0;
	return (root);
}

t_root			hit_obj(t_vector dir, t_vector camera, t_obj *obj)
{
	if (obj->type == Sphere)
		return (hit_sphere(dir, camera, obj));
	else if (obj->type == Plane)
		return (hit_plane(dir, camera, obj));
	else if (obj->type == Cone)
		return (hit_cone(dir, camera, obj));
	else if (obj->type == Cylinder)
		return (hit_cylinder(dir, camera, obj));
	return ((t_root){-1.0, -1.0});
}
