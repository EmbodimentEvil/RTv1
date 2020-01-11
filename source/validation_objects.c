/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_objects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:33:42 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/11 16:12:40 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj			*new_obj(void)
{
	t_obj		*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		ft_exit(ERROR_MALLOC);
	obj->type = 0;
	ft_vec_init(obj->color);
	obj->specular = 0;
	ft_vec_init(obj->pos);
	obj->radius = 0;
	ft_vec_init(obj->dir);
	obj->next = NULL;
	return (obj);
}

t_obj			*find_obj(t_obj **obj)
{
	t_obj		*tmp;
	t_obj		*new_elem;

	tmp = *obj;
	if (!tmp)
		return (new_obj());
	while (tmp->next)
		tmp = (tmp)->next;
	new_elem = new_obj();
	tmp->next = new_elem;
	return (new_elem);
}

static void		check_type_objects(int i, char **split, t_obj *tmp)
{
	if (ft_strcmp(FIGURES_TYPE_CONE, split[i]) == 0)
		tmp->type = Cone;
	else if (ft_strcmp(FIGURES_TYPE_CYLINDER, split[i]) == 0)
		tmp->type = Cylinder;
	else if (ft_strcmp(FIGURES_TYPE_SPHERE, split[i]) == 0)
		tmp->type = Sphere;
	else if (ft_strcmp(FIGURES_TYPE_PLANE, split[i]) == 0)
		tmp->type = Plane;
	else
		ft_exit(ERROR_FIGURES);
}

static void		check_color_and_specular_obj(int i, char **split,
					t_obj *tmp)
{
	if (ft_strstr(split[i], FIGURES_COLOR))
		tmp->color = get_array_value(split[i]);
	else
		ft_exit("LOX");
	if ((tmp->color.x < 0 || tmp->color.x > 255) &&
		(tmp->color.y < 0 || tmp->color.y > 255)
			&& (tmp->color.z < 0 || tmp->color.z > 255))
		ft_exit(ERROR_FIGURES);
	if (ft_strstr(split[++i], FIGURES_SPECULAR))
		tmp->specular = get_float_value(split[i]);
	else
		ft_exit(ERROR_FIGURES);
}

int				objects_processing(int i, char **split, t_obj **obj)
{
	t_obj	*tmp;

	tmp = *obj;
	while (split[i] && (split[i - 1] && ft_strcmp("-", split[i - 1]) == 0))
	{
		if (!tmp)
			tmp = find_obj(obj);
		check_type_objects(i++, split, tmp);
		check_color_and_specular_obj(i++, split, tmp);
		if (ft_strstr(split[++i], FIGURES_POS))
			tmp->pos = get_array_value(split[i]);
		else
			ft_exit(ERROR_FIGURES);
		if (ft_strstr(split[++i], FIGURES_RADIUS))
			tmp->radius = get_float_value(split[i]);
		else
			ft_exit(ERROR_FIGURES);
		if (ft_strstr(split[++i], FIGURES_DIRECTIONAL))
			tmp->dir = get_array_value(split[i]);
		else
			ft_exit(ERROR_FIGURES);
		i += 2;
		tmp = tmp->next;
	}
	return (i);
}
