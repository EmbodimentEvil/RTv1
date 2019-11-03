/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:14:52 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/03 19:57:07 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"








t_figures	*new_figure(char *name, double radius, int color, t_point point)
{
	t_figures	*figure;

	if (!(figure = (t_figures *)malloc(sizeof(t_figures))))
		ft_exit("Malloc error");
	figure->name = name;
	figure->radius = radius;
	figure->color = color;
	figure->point.x = point.x;
	figure->point.y = point.y;
	figure->point.z = point.z;
	figure->next = NULL;
	return (figure);
}

void		validation(t_rt *rt)
{
	t_point	point;

	point.x = 0;
	point.y = 1;
	point.z = 4;
	rt->figure = new_figure("sphere", 1, rgb(255, 0, 0), point);

	point.x = 2;
	point.y = 0;
	point.z = 4;
	rt->figure->next = new_figure("sphere1", 1, rgb(0, 0, 255), point);

	point.x = -2;
	point.y = 0;
	point.z = 4;
	rt->figure->next->next = new_figure("sphere2", 1, rgb(0, 255, 0), point);
}
