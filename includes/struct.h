/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:34:48 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/11 10:23:45 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "rt.h"

// typedef enum 					e_lights
// {
	// POINT,
	// AMBIENT,
	// DIRECTIONAL
// }								t_lights;

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

typedef struct					s_camera
{
	t_point						position;
}								t_camera;

// typedef struct					s_lights
// {
// 	char						*type;
// 	double						intensive;
// 	t_point					direction;
// 	struct s_lights				*next;
// }								t_lights;
typedef struct					s_lights
{
	int							type;
	double						intensive;
	t_point						point;
	struct s_lights				*next;
}								t_lights;

typedef struct					s_figures
{
	char						*name;
	int							color;
	int							specular;
	t_point						point;
	double						radius;
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
	t_figures					*figure;
	t_camera					camera;
	t_lights					*light;
	t_calculate					calculate;
}								t_rt;

#endif
