/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 23:46:04 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/10 19:32:44 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		compute_light(t_math *math, t_lights *lights, t_vector view)
{
	double	intensive;
	double	len_n;
	t_vector	vec_l;
	double		n_dot_l;
	t_vector	vec_r;
	double		r_dot_v;
	t_lights	*tmp = lights;

	intensive = 0;
	len_n = ft_vec_length(math->normal);
	while (tmp)
	{
		if (tmp->type == Ambient)
			intensive += tmp->intensive;
		else
		{
			if (tmp->type == Point)
				vec_l = ft_vec_subtract(tmp->point, math->point);
			else
				vec_l = tmp->point;
			n_dot_l = ft_vec_dot(math->normal, vec_l);
			if (n_dot_l > 0)
				intensive += tmp->intensive * n_dot_l / (len_n * ft_vec_length(vec_l));
			if (math->closest_obj.specular != -1)
			{
				vec_r = ft_vec_subtract(ft_vec_multiplication_num(math->normal, 2 * ft_vec_dot(math->normal, vec_l)), vec_l);
				r_dot_v = ft_vec_dot(vec_r, view);
				if (r_dot_v > 0)
					intensive += tmp->intensive * pow(r_dot_v / (ft_vec_length(vec_r) * ft_vec_length(view)), math->closest_obj.specular);
			}
		}
		tmp = tmp->next;
	}
	return (intensive);
}
