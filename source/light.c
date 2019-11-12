/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 23:46:04 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 21:41:11 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		compute_light(t_vector point, t_vector normal, t_lights *lights, int specular, t_vector view)
{
	// double	intensity;
	// double	len_n;
	// t_vector	vec_l;
	// double		n_dot_l;
	// t_vector	vec_r;
	// double		r_dot_v;
	// t_light		*light;

	// intensity = 0;
	// len_n = vec_length(normal);
	// while (lights)
	// {
	// 	light = (t_light *)(lights->content);
	// 	if (light->type == AMBIENT)
	// 		intensity += light->intensity;
	// 	else
	// 	{
	// 		if (light->type == POINT)
	// 			vec_l = vec_subtract(light->position, point);
	// 		else
	// 		{
	// 			vec_l = light->position;
	// 		}
	// 		n_dot_l = vec_dot(normal, vec_l);
	// 		if (n_dot_l > 0)
	// 			intensity += light->intensity * n_dot_l / (len_n * vec_length(vec_l));
	// 		if (specular != -1)
	// 		{
	// 			vec_r = vec_subtract(vec_multiple_num(normal, 2 * vec_dot(normal, vec_l)), vec_l);
	// 			r_dot_v = vec_dot(vec_r, view);
	// 			if (r_dot_v > 0)
	// 				intensity += light->intensity * pow(r_dot_v / (vec_length(vec_r) * vec_length(view)), specular);
	// 		}
	// 	}
	// 	lights = lights->next;
	// }
	// return (intensity);
    return (0);//delete
}
