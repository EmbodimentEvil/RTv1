/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:34:51 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 13:50:38 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "rt.h"

/*
**	init.c
*/
void			init_figure(t_figures *figure);
void			init_sdl(t_rt *rt);
t_rt			*init_rt(void);

/*
**	help.c
*/
int				set_color_rgb(int red, int green, int blue);
t_vector		calculate_fov(int x, int y, int width, int height);


/*
**
*/

/*
**
*/

/*
**
*/

/*
**
*/

/*
**	light.c
*/

/*
**  main.c
*/
void			show_correct_input(void);
int				main(int ac, char **av);

/*
**	ray_trace.c
*/
void			ray_trace(t_rt *rt);

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
t_figures		*new_figure(void);
t_figures		*find_figure(t_figures **figure);
int				figures_processing(int i, char **file_split,
					t_figures **figure);

#endif
