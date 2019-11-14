/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 23:53:55 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/14 19:22:35 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// void				color(int Color)
// {
	// int R = Color&0xFF;
// int G = (Color>>8)&0xFF;
// int B = (Color>>16)&0xFF;
	// printf("%d\n%d\n%d\n", R, G, B);
// }

int					main(int ac, char **av)
{
	t_rt			*rt;

	if (ac != 2)
		ft_exit("Error input");
	// color(0xFF0000);
	rt = init_rt();
	validation(av[1], rt);
	init_sdl(rt);
	return (OK_CODE);
}
