/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 23:53:55 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/09 05:52:19 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int					main(int ac, char **av)
{
	t_rt			*rt;

	if (ac != 2)
		ft_exit("Error input");
	rt = init_rt();
	validation(av[1], rt);
	// init_sdl(rt);
	return (OK_CODE);
}
