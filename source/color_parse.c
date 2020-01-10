/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:32:44 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/10 13:05:43 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				set_color_rgb(int red, int green, int blue)
{
	return ((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF);
}

int				color_parse(t_vector point, t_vector normal,
							t_lights *light, t_obj obj, t_vector dir)
{
	t_vector	rgb;

	rgb = ft_vec_multiplication_num(obj.color,
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
