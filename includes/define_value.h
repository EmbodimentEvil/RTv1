/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_value.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 01:31:34 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/06 18:43:15 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_VALUE_H
# define DEFINE_VALUE_H

# include "rt.h"

# define HEIGHT						1080
# define WIDTH						1920
# define FOV						M_PI / 2.0

# define MIN						0.0001f
# define MAX						1000000.0

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
# define LIGHT_POS					"\tpos:"

/*
**	Pattern for scene: figures
*/
# define FIGURES_TYPE_CONE			"cone:"
# define FIGURES_TYPE_CYLINDER		"cylinder:"
# define FIGURES_TYPE_SPHERE		"sphere:"
# define FIGURES_TYPE_PLANE			"plane:"
# define FIGURES_COLOR				"\tcolor:"
# define FIGURES_SPECULAR			"\tspecular:"
# define FIGURES_CENTER				"\tcenter:"
# define FIGURES_RADIUS				"\tradius:"
# define FIGURES_DIRECTIONAL		"\tdirection:"
#endif
