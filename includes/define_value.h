/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_value.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 01:31:34 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/10 13:01:58 by sleonia          ###   ########.fr       */
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

# define SCENE_1					"./scene/scene_1.rt"
# define SCENE_2					"./scene/scene_2.rt"
# define SCENE_3					"./scene/scene_3.rt"
# define SCENE_4					"./scene/scene_4.rt"
# define SCENE_5					"./scene/scene_5.rt"
# define SCENE_6					"./scene/scene_6.rt"
# define SCENE_7					"./scene/scene_7.rt"
# define SCENE_8					"./scene/scene_8.rt"
# define SCENE_9					"./scene/scene_9.rt"

/*
**	Pattern for scene: camera
*/
# define CAMERA						"camera:"
# define CAMERA_POS					"\tpos:"

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
# define FIGURES_POS				"\tpos:"
# define FIGURES_RADIUS				"\tradius:"
# define FIGURES_DIRECTIONAL		"\tdirection:"
#endif
