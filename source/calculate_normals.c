/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_normals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:53:37 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 19:16:05 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		cone_normal(t_obj *figure, t_vector point)
{
	t_vector	normal;

	return (normal);
}

t_vector		cylinder_normal(t_obj *figure, t_vector point)
{
	t_vector	normal;

	return (normal);
}

t_vector		sphere_normal(t_obj *figure, t_vector point)
{
	t_vector	normal;

	normal = ft_vec_subtract(point, figure->pos);
	normal = ft_vec_multiplication_num(normal,
		(double)(1.f / ft_vec_length(normal)));
	return (normal);
}

t_vector		plane_normal(t_obj *figure, t_vector point)
{
	t_vector	normal;

	return (normal);	
}

		

t_vector		get_normal(t_obj *figure, t_vector point)
{
	if (figure->type == Cone)
		return (cone_normal(figure, point));
	if (figure->type == Cylinder)
		return (cylinder_normal(figure, point));
	if (figure->type == Sphere)
		return (sphere_normal(figure, point));
	if (figure->type == Plane)
		return (plane_normal(figure, point));
	else
		ft_exit("NORMAL NOT FOUND");
}
