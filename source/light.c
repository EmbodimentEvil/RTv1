/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 23:46:04 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/04 21:54:12 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// double		compute_lighting(P, N, t_rt *rt)
// {
// 	double		i;
// 	t_lights	*tmp = rt->light;
	
// 	i = 0;
// 	while (tmp)
// 	{
// 		if (ft_strcmp(tmp->type, "ambient") == 0)
// 			i += tmp->intensive;
// 		else
// 		{
// 			if (ft_strcmp(tmp->type, "point") == 0)
// 				l = tmp->direction - P;
//             else
//                 tmp->direction;
//             n_dot_l = vec_dot(N, L);
//             if (n_dot_l > 0)
//                 i += tmp->intensive * n_dot_l / (length(N) * length(L));
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (i);
// }
