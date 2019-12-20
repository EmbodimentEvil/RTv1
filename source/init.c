/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:22:47 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 13:49:21 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			init_figure(t_figures *figure)
{
	figure->color.x = 0;
	figure->color.y = 0;
	figure->color.z = 0;
	figure->specular = -1;
	figure->point.x = 0;
	figure->point.y = 0;
	figure->point.z = 0;
	figure->radius = 0;
}

void			init_sdl(t_rt *rt)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_exit("SDL_Init");
	if (!(rt->sdl->win = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP)))
		ft_exit("SDL_CreateWindow");
	if (!(rt->sdl->sur = SDL_GetWindowSurface(rt->sdl->win)))
		ft_exit("SDL_GetWindowSurface");
}

t_rt			*init_rt(void)
{
	t_rt		*rt;

	if (!(rt = (t_rt *)malloc(sizeof(t_rt))))
		ft_exit(ERROR_MALLOC);
	if (!(rt->sdl = (t_sdl *)malloc(sizeof(t_sdl))))
		ft_exit(ERROR_MALLOC);
	if (!(rt->figure = new_figure()))
		ft_exit(ERROR_MALLOC);
	if (!(rt->light = new_light()))
		ft_exit(ERROR_MALLOC);
	rt->height = HEIGHT;
	rt->width = WIDTH;
	return (rt);
}
