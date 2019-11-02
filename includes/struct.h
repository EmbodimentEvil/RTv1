/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:34:48 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/03 01:47:39 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "rt.h"

typedef struct					s_position
{
	double						x;
	double						y;
	double						z;
}								t_position;

typedef struct					s_point
{
	double						x;
	double						y;
	double						z;
}								t_point;

typedef struct					s_vector
{
	double						x;
	double						y;
	double						z;
}								t_vector;

typedef struct					t_camera
{
	t_position					position;
}								t_camera;

typedef struct					s_lights
{
	t_position					position;
	struct s_lights				*prev;
	struct s_lights				*next;
}								t_lights;

typedef struct					s_figures
{
	char						*name;
	double						radius;
	int							color;
	t_position					point;
	struct s_figures			*next;
}								t_figures;

typedef struct					s_sdl
{
	SDL_Window					*win;
	SDL_Surface					*sur;
	SDL_Event					event;
}								t_sdl;

typedef struct					s_calculate
{
	double						t1;
	double						t2;
}								t_calculate;

typedef struct					s_rt
{
	int							height;
	int							width;
	t_sdl						sdl;
	t_figures					figure;
	t_camera					camera;
	t_lights					lights;
	t_calculate					calculate;
}								t_rt;

#endif
