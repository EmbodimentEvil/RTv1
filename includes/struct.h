/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:34:48 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/14 14:50:19 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "rt.h"

typedef enum					e_type_lights
{
	Point,
	Ambient,
	Directional
}								t_type_lights;

typedef enum					e_type_figures
{
	Cone,
	Cylinder,
	Sphere,
	Plane
}								t_type_figures;

typedef struct					s_camera
{
	t_vector					position;
}								t_camera;

typedef struct					s_lights
{
	t_type_lights				type;
	double						intensive;
	t_vector					point;
	struct s_lights				*next;
}								t_lights;

typedef struct					s_figures
{
	t_type_figures				type;
	t_vector					color;
	int							specular;
	t_vector					point;
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
