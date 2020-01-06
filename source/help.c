/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:40:25 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/06 14:08:23 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	Calculate FOV to fullscreen image
*/

t_vector		calculate_fov(int x, int y, int width, int height)
{
	t_vector	vector;

	vector.x = (double)x * 1.15 / width;
	vector.y = (double)y * 0.64 / height;
	vector.z = 1;
	return (vector);
}
