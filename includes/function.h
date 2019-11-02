/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:34:51 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/03 00:51:59 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "rt.h"


t_rt		*init_rt(void);


int			rgb(int r, int g, int b);
void		validation(t_rt *rt);



void		cycle_sdl(SDL_Window *win);
void		put_pixel(int x, int y, int color, SDL_Surface *sur);
void		clear_surface(SDL_Surface *sur);
void				init_sdl(t_rt *rt);


#endif