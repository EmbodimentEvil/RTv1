/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:32:44 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/20 19:17:01 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				set_color_rgb(int red, int green, int blue)
{
	return ((red & 0xFF) << 16) + ((green & 0xFF) << 8) + (blue & 0xFF);
}

int				color_parse(t_obj obj)
{
	int			color;

	if (obj.radius == 0.f)
		return (color = rgb(0, 0, 0));
	else
	{
		color = rgb((int)obj.color.x, (int)obj.color.y, (int)obj.color.z);
		return (color);	
	}
	return (color = rgb(0, 0, 0));
}
