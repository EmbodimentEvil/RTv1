/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:27:19 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/06 17:37:37 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				closest_object(t_obj *cur_obj, t_vector dir, double *closest_t, t_rt *rt)
{
	t_root		root;
	t_obj		*tmp;

	tmp = rt->obj;
	*closest_t = INFINITY;
	while (tmp)
	{
		root = hit_obj(dir, rt->camera, tmp);
		if (root.a >= MIN && root.a <= MAX && root.a < *closest_t)
		{
			*closest_t = root.a;
			*cur_obj = *tmp;
		}
		if (root.b >= MIN && root.b <= MAX && root.b < *closest_t)
		{
			*closest_t = root.b;
			*cur_obj = *tmp;
		}
		tmp = tmp->next;
	}
	return (cur_obj->radius == 0 ? set_color_rgb(0, 0, 0)
	: (set_color_rgb((int)cur_obj->color.x,
					(int)cur_obj->color.y,
					(int)cur_obj->color.z)));
}
