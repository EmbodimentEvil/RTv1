/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 23:53:55 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/06 15:47:10 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				show_example_input(void)
{
	system("osascript -e \'display notification\" \
Error input!\" with title \"Warning!\"\'");
	ft_putstr("You must use only 1-9 for set scene\nExample: ./RT 1\n");
}

int					main(int ac, char **av)
{
	t_rt			*rt;

	if (ac != 2)
	{
		show_example_input();
		ft_exit(ERROR_INPUT);
	}
	rt = init_rt();
	validation(av[1], rt);
	init_sdl(rt->sdl);
	draw(rt);
	sdl_loop(rt->sdl->win);
	return (0);
}
