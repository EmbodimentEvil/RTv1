/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:40:25 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 13:28:32 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				set_color_rgb(int red, int green, int blue)
{
	return ((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF);
}

/*
**	Calculate FOV to fullscreen image
*/

t_vector		calculate_fov(int x, int y, int width, int height)
{
	t_vector	vector;

	vector.x = (double)x * 1.15 / width;
	vector.y = (double)y * 0.62 / height;
	vector.z = 1;
	return (vector);
}
