/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:33:26 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/11 20:08:57 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_lights		*new_light(void)
{
	t_lights	*light;

	if (!(light = (t_lights *)malloc(sizeof(t_lights))))
		ft_exit(ERROR_MALLOC);
	light->type = KO_CODE;
	light->intensive = KO_CODE;
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

static void		check_type_lights(int i, char **file_split, t_lights *tmp)
{
	if (ft_strcmp(LIGHT_TYPE_POINT, file_split[i]) == 0)
		(tmp)->type = POINT;
	else if (ft_strcmp(LIGHT_TYPE_AMBIENT, file_split[i]))
		(tmp)->type = AMBIENT;
	else if (ft_strcmp(LIGHT_TYPE_DIRECTIONAL, file_split[i]))
		(tmp)->type = DIRECTIONAL;
	else
		ft_exit(ERROR_LIGHTS);
}

int				lights_processing(int i, char **file_split, t_lights **light)
{
	t_lights	*tmp;

	tmp = *light;
	while (file_split[i] && (ft_strcmp(LIGHT, file_split[i]) == 0
		&& ft_strcmp("-", file_split[i - 1]) == 0))
	{
		if (!tmp)
			(tmp) = find_light(light);
		check_type_lights(++i, file_split, tmp);
		if (ft_strcmp(LIGHT_INTENSIVE, file_split[++i]))
			(tmp)->intensive = get_float_value(file_split[i]);
		else
			ft_exit(ERROR_LIGHTS);
		if (ft_strstr(file_split[++i], LIGHT_POINT))
			(tmp)->point = get_array_value(file_split[i]);
		else
			ft_exit(ERROR_LIGHTS);
		i += 2;
		tmp = (tmp)->next;
	}
	return (i);
}
