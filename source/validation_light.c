/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:33:26 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/10 19:41:04 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_lights		*new_light(void)
{
	t_lights	*light;

	if (!(light = (t_lights *)malloc(sizeof(t_lights))))
		ft_exit(ERROR_MALLOC);
	light->type = -1;
	light->intensive = -1;
	light->next = NULL;
	return (light);
}

t_lights		*find_light(t_lights **light)
{
	t_lights	*tmp;
	t_lights	*new_elem;

	tmp = *light;
	if (!tmp)
		return (new_light());
	while (tmp->next)
		tmp = (tmp)->next;
	new_elem = new_light();
	tmp->next = new_elem;
	return (new_elem);
}

static void		check_type_lights(int i, char **split, t_lights *tmp)
{
	if (ft_strcmp(LIGHT_TYPE_POINT, split[i]) == 0)
		tmp->type = Point;
	else if (ft_strcmp(LIGHT_TYPE_AMBIENT, split[i]) == 0)
		tmp->type = Ambient;
	else if (ft_strcmp(LIGHT_TYPE_DIRECTIONAL, split[i]) == 0)
		tmp->type = Directional;
	else
		ft_exit(ERROR_LIGHTS);
}

int				lights_processing(int i, char **split, t_lights **light)
{
	t_lights	*tmp;

	tmp = *light;
	while (split[i] && (ft_strcmp(LIGHT, split[i]) == 0
		&& ft_strcmp("-", split[i - 1]) == 0))
	{
		if (!tmp)
			tmp = find_light(light);
		check_type_lights(++i, split, tmp);
		if (ft_strcmp(LIGHT_INTENSIVE, split[++i]))
			tmp->intensive = get_float_value(split[i]);
		else
			ft_exit(ERROR_LIGHTS);
		if (ft_strstr(split[++i], LIGHT_POS))
			tmp->point = get_array_value(split[i]);
		else
			ft_exit(ERROR_LIGHTS);
		i += 2;
		tmp = (tmp)->next;
	}
	return (i);
}
