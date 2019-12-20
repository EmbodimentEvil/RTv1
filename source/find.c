/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:27:19 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 19:32:50 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			closest_object(t_vector fov, double min, double max, t_rt *rt)
{
	t_root		root;
	double		closest_t;
	t_obj		*tmp = rt->obj;

	closest_t = INFINITY;
	while (tmp)
	{
		if (root.a >= min && root.a <= max && root.a < closest_t)
			closest_t = root.a;
		if (root.b >= min && root.b <= max && root.b < closest_t)
			closest_t = root.b;
		tmp = tmp->next;
	}
}
