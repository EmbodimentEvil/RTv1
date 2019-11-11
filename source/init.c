/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:22:47 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/11 03:23:27 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rt				*init_rt(void)
{
	t_rt			*rt;

	if (!(rt = (t_rt *)malloc(sizeof(t_rt))))
		return (NULL);
	if (!(rt->light = (t_lights *)malloc(sizeof(t_lights))))
		return (NULL);
	rt->light->next = NULL;
	rt->height = HEIGHT;
	rt->width = WIDTH;
	return (rt);
}
