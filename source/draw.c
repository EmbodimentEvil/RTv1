/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:50:09 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 12:59:03 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				put_pixel(int x, int y, int color, SDL_Surface *sur)
{
	int				*pixels;

	pixels = (int *)sur->pixels;
	pixels[sur->w * y + x] = color;
}
