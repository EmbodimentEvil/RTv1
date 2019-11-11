/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:22:47 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/11 07:04:31 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rt				*init_rt(void)
{
	t_rt			*rt;

	if (!(rt = (t_rt *)malloc(sizeof(t_rt))))
		ft_exit(ERROR_MALLOC);
	if (!(rt->figure = new_figure()))
		ft_exit(ERROR_MALLOC);
	if (!(rt->light = new_light()))
		ft_exit(ERROR_MALLOC);
	rt->height = HEIGHT;
	rt->width = WIDTH;
	return (rt);
}
