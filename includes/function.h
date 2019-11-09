/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:34:51 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/09 09:40:06 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "rt.h"

/*
**  main.c
*/
int					main(int ac, char **av);

/*
**  init.c
*/
t_rt				*init_rt(void);

/*
**  rgb.c
*/
int					rgb(int r, int g, int b);

/*
**  validation.c
*/
t_lights			*new_light();
t_figures			*new_figure(char *name, double radius, int color,
						t_point point);
void				validation(char *arg, t_rt *rt);

/*
**  sdl.c
*/
void				put_pixel(int x, int y, int color, SDL_Surface *sur);
void				cycle_sdl(SDL_Window *win);
void				for_each(t_rt *rt);
void				init_sdl(t_rt *rt);

/*
**  ray_trace.c
*/
double				vec_dot(t_vector a, t_vector b);
t_vector			canvas_to_viewport(int x, int y, t_rt *rt);
void				intersect_ray(t_rt *rt, t_point o, t_vector d,
						t_figures figure);
void				init_figure(t_figures *figure);
int					ray_trace(t_point point, t_vector vector,
						double min, double max, t_rt *rt);

#endif
