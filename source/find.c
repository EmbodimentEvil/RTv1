/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:27:19 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/06 15:12:23 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				closest_object(t_vector fov, double min, double max, t_rt *rt)
{
	t_root		root;
	double		closest_t;
	t_obj		obj;
	t_obj		*tmp = rt->obj;

	tmp = rt->obj;
	closest_t = INFINITY;
	while (tmp)
	{
		root = hit_obj(fov, rt->camera, tmp);
		if (root.a >= min && root.a <= max && root.a < closest_t)
		{
			closest_t = root.a;
			obj = *tmp;
		}
		if (root.b >= min && root.b <= max && root.b < closest_t)
		{
			closest_t = root.b;
			obj = *tmp;
		}
		tmp = tmp->next;
	}
	// compute_light();
	return (obj.radius == 0 ? set_color_rgb(0, 0, 0)
	: (set_color_rgb((int)obj.color.x, (int)obj.color.y, (int)obj.color.z)));
}
