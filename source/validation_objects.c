/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_objects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:33:42 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/06 18:44:47 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj		*new_obj(void)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		ft_exit(ERROR_MALLOC);
	obj->type = 0;
	obj->color.x = 0;
	obj->color.y = 0;
	obj->color.z = 0;
	obj->specular = 0;
	obj->next = NULL;
	return (obj);
}

t_obj		*find_obj(t_obj **obj)
{
	t_obj	*tmp;
	t_obj	*new_elem;

	tmp = *obj;
	if (!tmp)
		return (new_obj());
	while (tmp->next)
		tmp = (tmp)->next;
	new_elem = new_obj();
	tmp->next = new_elem;
	return (new_elem);
}

static void		check_type_objects(int i, char **file_split, t_obj *tmp)
{
	if (ft_strcmp(FIGURES_TYPE_CONE, file_split[i]) == 0)
		tmp->type = Cone;
	else if (ft_strcmp(FIGURES_TYPE_CYLINDER, file_split[i]) == 0)
		tmp->type = Cylinder;
	else if (ft_strcmp(FIGURES_TYPE_SPHERE, file_split[i]) == 0)
		tmp->type = Sphere;
	else if (ft_strcmp(FIGURES_TYPE_PLANE, file_split[i]) == 0)
		tmp->type = Plane;
	else
		ft_exit(ERROR_FIGURES);
}

static void		check_color_and_specular_obj(int i, char **file_split,
					t_obj *tmp)
{
	if (ft_strcmp(FIGURES_COLOR, file_split[i]))
		tmp->color = get_array_value(file_split[i]);
	else if ((tmp->color.x < 0 || tmp->color.x > 255) &&
		(tmp->color.y < 0 || tmp->color.y > 255)
			&& (tmp->color.z < 0 || tmp->color.z > 255))
		ft_exit(ERROR_FIGURES);
	else
		ft_exit(ERROR_FIGURES);
	if (ft_strstr(file_split[++i], FIGURES_SPECULAR))
		tmp->specular = get_float_value(file_split[i]);
	else
		ft_exit(ERROR_FIGURES);
}

int				objects_processing(int i, char **file_split, t_obj **obj)
{
	t_obj	*tmp;

	tmp = *obj;
	while (file_split[i] && ft_strcmp("-", file_split[i - 1]) == 0)
	{
		if (!tmp)
			tmp = find_obj(obj);
		check_type_objects(i, file_split, tmp);
		check_color_and_specular_obj(++i, file_split, tmp);
		++i;
		if (ft_strstr(file_split[++i], FIGURES_CENTER))
			tmp->pos = get_array_value(file_split[i]);
		else
			ft_exit(ERROR_FIGURES);
		if (ft_strstr(file_split[++i], FIGURES_RADIUS))
			tmp->radius = get_float_value(file_split[i]);
		else
			ft_exit(ERROR_FIGURES);
		if (ft_strstr(file_split[++i], FIGURES_DIRECTIONAL))
			tmp->direction = get_array_value(file_split[i]);
		else
			ft_exit(ERROR_FIGURES);
		i += 2;
		tmp = tmp->next;
	}
	return (i);
}
