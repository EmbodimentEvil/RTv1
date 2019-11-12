/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:34:51 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:28:48 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "rt.h"

/*
**  main.c
*/
int				main(int ac, char **av);

/*
**  init.c
*/
t_rt			*init_rt(void);

/*
**  rgb.c
*/
int				rgb(int r, int g, int b);

/*
**  sdl.c
*/
void			put_pixel(int x, int y, int color, SDL_Surface *sur);
void			cycle_sdl(SDL_Window *win);
void			for_each(t_rt *rt);
void			init_sdl(t_rt *rt);

/*
**  ray_trace.c
*/
double			vec_dot(t_vector a, t_vector b);
t_vector		canvas_to_viewport(int x, int y, t_rt *rt);
void			intersect_ray(t_rt *rt, t_vector o, t_vector d,
						t_figures figure);
void			init_figure(t_figures *figure);
int				ray_trace(t_vector point, t_vector vector,
						double min, double max, t_rt *rt);

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
static void		check_type_lights(int i, char **file_split, t_lights *tmp);
static void		check_color_and_specular_figures(int i, char **file_split,
					t_figures *tmp);
int				lights_processing(int i, char **file_split, t_lights **light);

/*
**  validation_light.c
*/
t_figures		*new_figure(void);
t_figures		*find_figure(t_figures **figure);
static void		check_type_figures(int i, char **file_split, t_figures *tmp);
int				figures_processing(int i, char **file_split,
					t_figures **figure);

#endif
