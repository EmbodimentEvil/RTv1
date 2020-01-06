/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:40:25 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/06 15:41:05 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		calculate_direction(int x, int y, int width, int height)
{
	t_vector	vector;

	vector.x = (double)x * 1.15 / width;
	vector.y = (double)y * 0.64 / height;
	vector.z = 1;
	return (vector);
}
