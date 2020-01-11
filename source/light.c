/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 23:46:04 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/11 16:58:12 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			point_direct_light_math(double *intensive, t_lights *tmp,
										t_math *math, t_vector view)
{
	t_vector	vec_l;
	double		r_dot_v;
	double		n_dot_l;
	double		len_n;
	t_vector	vec_r;

	len_n = ft_vec_length(math->normal);
	if (tmp->type == Point)
		vec_l = ft_vec_subtract(tmp->point, math->point);
	else
		vec_l = tmp->point;
	// 
	n_dot_l = ft_vec_dot(math->normal, vec_l);
	if (n_dot_l > 0)
		*intensive += tmp->intensive * n_dot_l
						/ (len_n * ft_vec_length(vec_l));
	if (math->closest_obj->specular != -1)
	{
		vec_r = ft_vec_subtract(ft_vec_multiplication_num(math->normal, 2
									* ft_vec_dot(math->normal, vec_l)), vec_l);
		r_dot_v = ft_vec_dot(vec_r, view);
		if (r_dot_v > 0)
			*intensive += tmp->intensive * pow(r_dot_v / (ft_vec_length(vec_r)
						* ft_vec_length(view)), math->closest_obj->specular);
	}
}

double			compute_light(t_math *math, t_lights *lights, t_vector view)
{
	t_lights	*tmp;
	double		intensive;

	intensive = 0;
	tmp = lights;
	while (tmp)
	{
		if (tmp->type == Ambient)
			intensive += tmp->intensive;
		else
			point_direct_light_math(&intensive, tmp, math, view);
		tmp = tmp->next;
	}
	return (intensive);
}
