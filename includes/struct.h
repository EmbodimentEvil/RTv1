/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:34:48 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 20:37:35 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "rt.h"

/*
**	Structure for storing values of ray_trace
*/

typedef struct					s_img
{
	int							curnt_x;
	int							curnt_y;
	int							finish_x;
	int							finish_y;
	int							half_width;
	int							half_height;
}								t_img;

/*
**	Enum for types of lights
*/

typedef enum					e_type_lights
{
	Point,
	Ambient,
	Directional
}								t_type_lights;

/*
**	Enum for types of obj
*/

typedef enum					e_type_obj
{
	Cone,
	Cylinder,
	Sphere,
	Plane
}								t_type_obj;

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

typedef struct					s_obj
{
	t_type_obj					type;
	t_vector					color;
	int							specular;
	t_vector					pos;
	double						radius;
	struct s_obj				*next;
}								t_obj;

/*
**	Struct for storing values of sdl
*/

typedef struct					s_sdl
{
	SDL_Window					*win;
	SDL_Surface					*sur;
	SDL_Event					event;
}								t_sdl;

typedef struct					s_root
{
	double						a;
	double						b;
}								t_root;

/*
**	Struct for storing values for calculating
*/

typedef struct					s_math
{
	
}								t_math;

typedef struct					s_rt
{
	t_sdl						*sdl;
	t_obj						*obj;
	t_camera					camera;
	t_lights					*light;
}								t_rt;

#endif
