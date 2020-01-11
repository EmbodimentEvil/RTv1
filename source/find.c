/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:27:19 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/11 17:31:07 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			closest_object(t_rt *rt)
{
	t_root		root;
	t_obj		*tmp;

	tmp = rt->obj;
	rt->math->closest_obj = NULL;
	rt->math->closest_t = MAX;
	while (tmp)
	{
		root = hit_obj(rt->math->dir, rt->camera, tmp);
		if (root.a > MIN && root.a < MAX && root.a < rt->math->closest_t)
		{
			rt->math->closest_t = root.a;
			rt->math->closest_obj = tmp;
		}
		if (root.b > MIN && root.b < MAX && root.b < rt->math->closest_t)
		{
			rt->math->closest_t = root.b;
			rt->math->closest_obj = tmp;
		}
		tmp = tmp->next;
	}
}
