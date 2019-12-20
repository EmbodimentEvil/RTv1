/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:52:14 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 20:13:37 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				sdl_loop(SDL_Window *win)
{
	SDL_Event		event;

	while (1)
	{
		if (SDL_PollEvent(&(event)))
		{
			if (SDL_QUIT == event.type || SDLK_ESCAPE == event.key.keysym.sym)
				break ;
			SDL_UpdateWindowSurface(win);
		}
	}
	SDL_DestroyWindow(win);
	SDL_Quit();	
}
