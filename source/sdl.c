/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:25:10 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 18:05:14 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				put_pixel(int x, int y, int color, SDL_Surface *sur)
{
	int				*pixels;

	pixels = (int *)sur->pixels;
	pixels[sur->w * y + x] = color;
}

void				cycle_sdl(SDL_Window *win)
{
	SDL_Event		event;

	while (1)
	{
		if (SDL_PollEvent(&(event)))
		{
			if (SDL_QUIT == event.type)
				break ;
			if (SDLK_ESCAPE == event.key.keysym.sym)
				break ;
			SDL_UpdateWindowSurface(win);
		}
	}
}

void				for_each(t_rt *rt)
{
	int				x;
	int				y;
	t_vector		vector;
	t_vector		point;
	int				color;

	y = -rt->sdl.sur->h / 2 - 1;
	while (++y < rt->sdl.sur->h / 2)
	{
		x = -rt->sdl.sur->w / 2 - 1;
		while (++x < rt->sdl.sur->w / 2)
		{
			vector = canvas_to_viewport(x, y, rt);
			color = ray_trace(point, vector, 1, INFINITY, rt);
			put_pixel(x + rt->sdl.sur->w / 2,
				y + rt->sdl.sur->h / 2, color, rt->sdl.sur);
		}
	}
}

void				init_sdl(t_rt *rt)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_exit("SDL_Init");
	if (!(rt->sdl.win = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP)))
		ft_exit("SDL_CreateWindow");
	if (!(rt->sdl.sur = SDL_GetWindowSurface(rt->sdl.win)))
		ft_exit("SDL_GetWindowSurface");
	for_each(rt);
	cycle_sdl(rt->sdl.win);
	SDL_DestroyWindow(rt->sdl.win);
	SDL_Quit();
}
