/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:27:19 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/11 16:19:04 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			closest_object(t_vector dir, double *closest_t, t_rt *rt)
{
	t_root		root;
	t_obj		*tmp;

	tmp = rt->obj;
	rt->math->closest_obj = NULL;
	*closest_t = MAX;
	while (tmp)
	{
		root = hit_obj(dir, rt->camera, tmp);
		if (root.a > MIN && root.a < MAX && root.a < *closest_t)
		{
			*closest_t = root.a;
			rt->math->closest_obj = tmp;
		}
		if (root.b > MIN && root.b < MAX && root.b < *closest_t)
		{
			*closest_t = root.b;
			rt->math->closest_obj = tmp;
		}
		tmp = tmp->next;
	}
}
