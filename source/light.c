/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 23:46:04 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/13 17:58:17 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		closest_object_light(t_vector vec_l, int type, t_rt *rt)
{
	t_root		root;
	t_obj		*tmp;

	tmp = rt->obj;
	rt->math->closest_obj_2 = NULL;
	if (type == Directional)
		rt->math->closest_t_2 = MAX;
	else
		rt->math->closest_t_2 = 1;
	while (tmp)
	{
		root = hit_obj(vec_l, rt->math->point, tmp);
		if (root.a > MIN && root.a < MAX && root.a < rt->math->closest_t_2)
		{
			rt->math->closest_t_2 = root.a;
			rt->math->closest_obj_2 = tmp;
		}
		if (root.b > MIN && root.b < MAX && root.b < rt->math->closest_t_2)
		{
			rt->math->closest_t_2 = root.b;
			rt->math->closest_obj_2 = tmp;
		}
		tmp = tmp->next;
	}
}

static void		point_direct_light_math(double *intensive, t_lights *tmp,
										t_vector view, t_rt *rt)
{
	double		r_dot_v;
	double		n_dot_l;
	t_vector	vec_l;
	t_vector	vec_r;

	if (tmp->type == Point)
		vec_l = ft_vec_subtract(tmp->point, rt->math->point);
	else
		vec_l = tmp->point;
	closest_object_light(vec_l, tmp->type, rt);
	if (rt->math->closest_obj_2)
		return ;
	n_dot_l = ft_vec_dot(rt->math->normal, vec_l);
	if (n_dot_l > 0)
		*intensive += tmp->intensive * n_dot_l
				/ (ft_vec_length(rt->math->normal) * ft_vec_length(vec_l));
	if (rt->math->closest_obj->specular != -1)
	{
		vec_r = ft_vec_subtract(ft_vec_multiplication_num(rt->math->normal, 2
								* ft_vec_dot(rt->math->normal, vec_l)), vec_l);
		r_dot_v = ft_vec_dot(vec_r, view);
		if (r_dot_v > 0)
			*intensive += tmp->intensive * pow(r_dot_v / (ft_vec_length(vec_r)
					* ft_vec_length(view)), rt->math->closest_obj->specular);
	}
}

double			compute_light(t_vector view, t_rt *rt)
{
	t_lights	*tmp;
	double		intensive;

	intensive = 0;
	tmp = rt->light;
	while (tmp)
	{
		if (tmp->type == Ambient)
			intensive += tmp->intensive;
		else
			point_direct_light_math(&intensive, tmp, view, rt);
		tmp = tmp->next;
	}
	intensive > 1.0 ? intensive = 1.0f : 0;
	return (intensive);
}
