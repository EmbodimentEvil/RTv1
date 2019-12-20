/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:34:51 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 20:09:47 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "rt.h"

/*
**	calculate_normals.c
*/
t_vector		cone_normal(t_obj *figure, t_vector point);
t_vector		cylinder_normal(t_obj *figure, t_vector point);
t_vector		sphere_normal(t_obj *figure, t_vector point);
t_vector		plane_normal(t_obj *figure, t_vector point);
t_vector		get_normal(t_obj *figure, t_vector point);

/*
**	color_parse.c
*/
int				set_color_rgb(int red, int green, int blue);
int				color_parse(t_obj obj);

/*
**	draw.c
*/
void			put_pixel(int x, int y, int color, SDL_Surface *sur);
int				ray_trace(t_vector fov, double min, double max, t_rt *rt);
void			draw(t_rt *rt);

/*
**	help.c
*/
int				set_color_rgb(int red, int green, int blue);
t_vector		calculate_fov(int x, int y, int width, int height);

/*
**	hit.c
*/
t_root			hit_cone(t_vector o, t_vector d, t_obj sphere);
t_root			hit_cylinder(t_vector o, t_vector d, t_obj sphere);
t_root			hit_sphere(t_vector o, t_vector d, t_obj sphere);
t_root			hit_plane(t_vector o, t_vector d, t_obj sphere);

/*
**	init.c
*/
void			init_figure(t_obj *figure);
void			init_sdl(t_sdl *sdl);
t_rt			*init_rt(void);

/*
**	light.c
*/

/*
**  main.c
*/
void			show_example_input(void);
int				main(int ac, char **av);

/*
**	ray_trace.c
*/

/*
**	sdl_loop.c
*/
void			sdl_loop(SDL_Window *win);

/*
**  validation.c
*/
void			validation(char *arg, t_rt *rt);

/*
**  validation_get_value.c
*/
t_vector		get_array_value(char *str);
float			get_float_value(char *str);
float			get_int_value(char *str);

/*
**  validation_figures.c
*/
t_lights		*new_light(void);
t_lights		*find_light(t_lights **light);
int				lights_processing(int i, char **file_split, t_lights **light);

/*
**  validation_light.c
*/
t_obj			*new_obj(void);
t_obj			*find_obj(t_obj **obj);
int				objects_processing(int i, char **file_split,
					t_obj **figure);

#endif
