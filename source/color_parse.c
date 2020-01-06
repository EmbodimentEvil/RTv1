/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:32:44 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/06 17:34:39 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				set_color_rgb(int red, int green, int blue)
{
	return ((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF);
}

int				color_parse(int color, t_vector point, t_vector normal,
							t_lights *light, t_obj obj, t_vector dir)
{
	t_vector	rgb;

	rgb.x = color & 0xFF;
	rgb.y = (color >> 8) & 0xFF;
	rgb.z = (color >> 16) & 0xFF;
	rgb = ft_vec_multiplication_num(rgb,
			compute_light(point, normal, light, obj.specular,
			ft_vec_multiplication_num(dir, -3)));
	if (rgb.x > 255)
		rgb.x = 255;
	if (rgb.y > 255)
		rgb.y = 255;
	if (rgb.z > 255)
		rgb.z = 255;
	return (set_color_rgb((int)rgb.x, (int)rgb.y, (int)rgb.z));
}
