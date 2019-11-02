/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:14:52 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/03 02:09:37 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


void		validation(t_rt *rt)
{
	t_figures	figure1;
	t_figures	figure2;
	t_figures	figure3;


	figure1.name = "sphere";
	figure1.radius = 0.5;
	figure1.color = rgb(255, 0, 0);
	figure1.point.x = 0;
	figure1.point.y = -1;
	figure1.point.z = 3;

	figure2.name = "sphere";
	figure2.radius = 1;
	figure2.color = rgb(0, 255, 0);
	figure2.point.x = 2;
	figure2.point.y = 0;
	figure2.point.z = 4;

	figure3.name = "sphere";
	figure3.radius = 1.5;
	figure3.color = rgb(0, 0, 255);
	figure3.point.x = -2;
	figure3.point.y = 0;
	figure3.point.z = 4;

	figure1.next = &figure2;
	figure2.next = &figure3;
	figure3.next = NULL;
	rt->figure = figure1;
}