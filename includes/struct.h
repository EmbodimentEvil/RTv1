/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:34:48 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/11 17:26:34 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "rt.h"

typedef enum				e_type_lights
{
	Point = 1,
	Ambient,
	Directional
}							t_type_lights;

typedef enum				e_type_obj
{
	Cone,
	Cylinder,
	Sphere,
	Plane
}							t_type_obj;

typedef struct				s_img
{
	int						curnt_x;
	int						curnt_y;
	int						finish_x;
	int						finish_y;
	int						half_width;
	int						half_height;
}							t_img;

typedef struct				s_lights
{
	t_type_lights			type;
	double					intensive;
	t_vector				point;
	struct s_lights			*next;
}							t_lights;

typedef struct				s_obj
{
	t_type_obj				type;
	t_vector				color;
	int						specular;
	t_vector				pos;
	double					radius;
	t_vector				dir;
	struct s_obj			*next;
}							t_obj;

typedef struct				s_sdl
{
	SDL_Window				*win;
	SDL_Surface				*sur;
	SDL_Event				event;
}							t_sdl;

typedef struct				s_root
{
	double					a;
	double					b;
}							t_root;

typedef struct				s_math
{
	t_vector				dir;
	t_vector				point;
	t_vector				normal;
	t_obj					*closest_obj;
	t_obj					*closest_obj_2;
	double					closest_t;
	double					closest_t_2;
}							t_math;

typedef struct				s_rt
{
	t_sdl					*sdl;
	t_obj					*obj;
	t_vector				camera;
	t_lights				*light;
	t_math					*math;
}							t_rt;

#endif
