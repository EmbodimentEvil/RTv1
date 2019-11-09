/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_value.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 01:31:34 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/09 11:10:27 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_VALUE_H
# define DEFINE_VALUE_H

# include "rt.h"

# define HEIGHT						1000
# define WIDTH						1000
# define FOV						M_PI / 2.0

# define KO_CODE				    -1
# define OK_CODE					0

/*
**	Argument`s
*/
# define SCENE_1_CODE				"1"
# define SCENE_2_CODE				"2"
# define SCENE_3_CODE				"3"
# define SCENE_4_CODE				"4"

# define SCENE_1					"./scene/scene_1.rt"
# define SCENE_2					"./scene/scene_2.rt"
# define SCENE_3					"./scene/scene_3.rt"
# define SCENE_4					"./scene/scene_4.rt"

/*
**	Light`s
*/
# define AMBIENT					1
# define POINT						2
# define DIRECTIONAL				3

/*
**	Pattern for scene: camera
*/
# define CAMERA						"camera:"
# define CAMERA_CENTER				"\tcenter:"

/*
**	Pattern for scene: light
*/
# define LIGHT						"light:"
# define LIGHT_TYPE_POINT			"\ttype: point"
# define LIGHT_TYPE_AMBIENT			"\ttype: ambient"
# define LIGHT_TYPE_DIRECTIONAL		"\ttype: directional"
# define LIGHT_INTENSIVE			"\tintensive"
# define LIGHT_POINT				"\tpoint:"

/*
**	Pattern for scene: figures
*/
# define FIGURES_1					"cone:"
# define FIGURES_2					"cylinder:"
# define FIGURES_3					"sphere:"
# define FIGURES_4					"plane:"
# define COLOR					    "\tcolor:"
#endif
