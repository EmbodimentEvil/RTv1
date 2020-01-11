/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:22:47 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/11 16:33:17 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			init_obj(t_obj *obj)
{
	obj->type = 0;
	ft_vec_init(obj->color);
	obj->specular = 0;
	ft_vec_init(obj->pos);
	obj->radius = 0;
	ft_vec_init(obj->dir);
	obj->next = NULL;
}

void			init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_exit("SDL_Init");
	if (!(sdl->win = SDL_CreateWindow("RT",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									WIDTH, HEIGHT,
									SDL_WINDOW_SHOWN)))
		ft_exit("SDL_CreateWindow");
	if (!(sdl->sur = SDL_GetWindowSurface(sdl->win)))
		ft_exit("SDL_GetWindowSurface");
}

t_rt			*init_rt(void)
{
	t_rt		*rt;

	if (!(rt = (t_rt *)malloc(sizeof(t_rt))))
		ft_exit(ERROR_MALLOC);
	if (!(rt->sdl = (t_sdl *)malloc(sizeof(t_sdl))))
		ft_exit(ERROR_MALLOC);
	if (!(rt->obj = new_obj()))
		ft_exit(ERROR_MALLOC);
	if (!(rt->light = new_light()))
		ft_exit(ERROR_MALLOC);
	rt->math = ft_safe_malloc(sizeof(t_math));
	return (rt);
}
