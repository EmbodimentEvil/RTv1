/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_figures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:33:42 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 22:39:03 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_figures		*new_figure(void)
{
	t_figures	*figure;

	if (!(figure = (t_figures *)malloc(sizeof(t_figures))))
		ft_exit(ERROR_MALLOC);
	figure->type = KO_CODE;
	figure->color.x = KO_CODE;
	figure->color.y = KO_CODE;
	figure->color.z = KO_CODE;
	figure->specular = KO_CODE;
	figure->next = NULL;
	return (figure);
}

t_figures		*find_figure(t_figures **figure)
{
	t_figures	*tmp;
	t_figures	*new_elem;

	tmp = *figure;
	if (!tmp)
		return (new_figure());
	while (tmp->next)
	{
		tmp = (tmp)->next;
	}
	new_elem = new_figure();
	tmp->next = new_elem;
	return (new_elem);
}

static void		check_type_figures(int i, char **file_split, t_figures *tmp)
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

static void		check_color_and_specular_figures(int i, char **file_split,
					t_figures *tmp)
{
	if (ft_strcmp(FIGURES_COLOR, file_split[i]))
		tmp->color = get_array_value(file_split[i]);
	else
		ft_exit(ERROR_FIGURES);
	if (ft_strstr(file_split[++i], FIGURES_SPECULAR))
		tmp->specular = get_float_value(file_split[i]);
	else
		ft_exit(ERROR_FIGURES);
}

int				figures_processing(int i, char **file_split, t_figures **figure)
{
	t_figures	*tmp;

	tmp = *figure;
	while (file_split[i] && ft_strcmp("-", file_split[i - 1]) == 0)
	{
		if (!tmp)
			tmp = find_figure(figure);
		check_type_figures(i, file_split, tmp);
		check_color_and_specular_figures(++i, file_split, tmp);
		++i;
		if (ft_strstr(file_split[++i], FIGURES_CENTER))
			tmp->point = get_array_value(file_split[i]);
		else
			ft_exit(ERROR_FIGURES);
		if (ft_strstr(file_split[++i], FIGURES_RADIUS))
			tmp->radius = get_int_value(file_split[i]);
		else
			ft_exit(ERROR_FIGURES);
		i += 2;
		tmp = tmp->next;
	}
	return (i);
}
