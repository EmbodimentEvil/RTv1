/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:14:52 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/11 18:42:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// void		validation(t_rt *rt)
// {
// 	t_point	point;

// 	point.x = 0;
// 	point.y = 1;
// 	point.z = 4;
// 	rt->figure = new_figure("sphere", 1, rgb(255, 0, 0), point);

// 	point.x = 2;
// 	point.y = 0;
// 	point.z = 4;
// 	rt->figure->next = new_figure("sphere1", 1, rgb(0, 0, 255), point);

// 	point.x = -2;
// 	point.y = 0;
// 	point.z = 4;
// 	rt->figure->next->next = new_figure("sphere2", 1, rgb(0, 255, 0), point);

// 	point.x = 0;
// 	point.y = 0;
// 	point.z = 0;
// 	rt->light = new_light("ambient", 0.2, point);

// 	point.x = 2;
// 	point.y = 1;
// 	point.z = 0;
// 	rt->light = new_light("point", 0.6, point);

// 	point.x = 1;
// 	point.y = 4;
// 	point.z = 4;
// 	rt->light = new_light("direction", 0.2, point);	
// }

t_lights	*new_light()
{
	t_lights		*light;

	if (!(light = (t_lights *)malloc(sizeof(t_lights))))
		ft_exit(ERROR_MALLOC);
	light->type = KO_CODE;
	light->intensive = KO_CODE;
	light->next = NULL;
	return (light);
}

t_lights	*find_light(t_lights **light)
{
	t_lights		*tmp;
	t_lights		*new_elem;

	tmp = *light;
	if (!tmp)
		return (new_light());
	while (tmp->next)
	{
		tmp = (tmp)->next;
	}
	new_elem = new_light();
	tmp->next = new_elem;
	return (new_elem);
}

t_figures	*new_figure()
{
	t_figures	*figure;

	if (!(figure = (t_figures *)malloc(sizeof(t_figures))))
		ft_exit(ERROR_MALLOC);
	figure->name = NULL;
	figure->color = KO_CODE;
	figure->specular = KO_CODE;
	figure->next = NULL;
	return (figure);
}

t_figures	*find_figure(t_figures **figure)
{
	t_figures		*tmp;
	t_figures		*new_elem;

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

char		*check_argument(char *arg)
{
	if (ft_strcmp(arg, SCENE_1_CODE) == 0)
		return (SCENE_1);
	else if (ft_strcmp(arg, SCENE_2_CODE) == 0)
		return (SCENE_2);
	else if (ft_strcmp(arg, SCENE_3_CODE) == 0)
		return (SCENE_3);
	else if (ft_strcmp(arg, SCENE_4_CODE) == 0)
		return (SCENE_4);
	else
		return (NULL);
}

t_point		get_array(char *str)
{
	int		i;
	t_point	point;
	char	**str_split;

	i = 0;
	while (*str && !ft_isdigit(*str))
		str++;
	if (!(str_split = ft_strsplit(str, ',')))
		ft_exit(ERROR_STRSPLIT);
	if (ft_len_arr(str_split) > 3)
			ft_exit(ERROR_INPUT);
	point.x = ft_atof(str_split[0]);
	point.y = ft_atof(str_split[1]);
	point.z = ft_atof(str_split[2]);
	return (point);
}

float		get_number_value(char *str)
{
	float	value;
	char	**str_split;

	while (*str && !ft_isdigit(*str))
		str++;
	value = ft_atof(str);
	return (value);
}

float		get_number_value1(char *str)
{
	int		value;
	char	**str_split;

	while (*str && !ft_isdigit(*str))
		str++;
	value = ft_atoi(str);
	return (value);
}

int			find_camera(int i, char **file_split, t_camera *camera)
{
	if (ft_strcmp("-", file_split[++i]) == 0)
	{	
		if (ft_strcmp(CAMERA, file_split[++i]) == 0)
		{
			if (ft_strcmp("-", file_split[i + 1]) == 0)
			{
				if (ft_strstr(file_split[i], CAMERA_CENTER))
					camera->position = get_array(file_split[i]);
				else
					ft_exit(ERROR_INPUT);
			}
		}
		else
			ft_exit(ERROR_INPUT);		
	}
	else
		ft_exit(ERROR_INPUT);
	return (i + 3);
}

int			find_lights(int i, char **file_split, t_lights **light)
{
	t_lights	*tmp = *light;

	while (file_split[i] && (ft_strcmp(LIGHT, file_split[i]) == 0
		&& ft_strcmp("-", file_split[i - 1]) == 0))
	{
		if (!tmp)
			(tmp) = find_light(light);
		if (ft_strcmp(LIGHT_TYPE_POINT, file_split[++i]) == 0)
			(tmp)->type = POINT;
		else if (ft_strcmp(LIGHT_TYPE_AMBIENT, file_split[i]))
			(tmp)->type = AMBIENT;
		else if (ft_strcmp(LIGHT_TYPE_DIRECTIONAL, file_split[i]))
			(tmp)->type = DIRECTIONAL;
		else
			ft_exit(ERROR_LIGHTS);
		if (ft_strcmp(LIGHT_INTENSIVE, file_split[++i]))
			(tmp)->intensive = get_number_value(file_split[i]);
		else
			ft_exit(ERROR_LIGHTS);
		if (ft_strstr(file_split[++i], LIGHT_POINT))
			(tmp)->point = get_array(file_split[i]);
		else
			ft_exit(ERROR_LIGHTS);
		i += 2;
		tmp = (tmp)->next;
	}
	if (ft_strcmp(FIGURES_TYPE_CONE, file_split[i]) == 0
		|| ft_strcmp(FIGURES_TYPE_CYLINDER, file_split[i]) == 0
		|| ft_strcmp(FIGURES_TYPE_SPHERE, file_split[i]) == 0
		|| ft_strcmp(FIGURES_TYPE_PLANE, file_split[i]) == 0)
		return (i);
	else
		ft_exit(ERROR_LIGHTS);
	return (i);
}

int			find_figures(int i, char **file_split, t_figures **figure)
{
	t_figures	*tmp = *figure;

	while (file_split[i] && ft_strcmp("-", file_split[i - 1]) == 0)
	{
		if (!tmp)
			(tmp) = find_figure(figure);
		if (ft_strcmp(FIGURES_TYPE_CONE, file_split[i]) == 0)
			(tmp)->name = "cone:";
		else if (ft_strcmp(FIGURES_TYPE_CYLINDER, file_split[i]) == 0)
			(tmp)->name = "cylinder:";
		else if (ft_strcmp(FIGURES_TYPE_SPHERE, file_split[i]) == 0)
			(tmp)->name = "sphere:";
		else if (ft_strcmp(FIGURES_TYPE_PLANE, file_split[i]) == 0)
			(tmp)->name = "plane:";
		else
			ft_exit(ERROR_FIGURES);
		if (ft_strcmp(FIGURES_COLOR, file_split[++i]))
			(tmp)->color = get_number_value(file_split[i]);
		else
			ft_exit(ERROR_FIGURES);
		if (ft_strstr(file_split[++i], FIGURES_SPECULAR))
			(tmp)->specular = get_number_value1(file_split[i]);
		else
			ft_exit(ERROR_FIGURES);
		if (ft_strstr(file_split[++i], FIGURES_CENTER))
			(tmp)->point = get_array(file_split[i]);
		else
			ft_exit(ERROR_FIGURES);
		if (ft_strstr(file_split[++i], FIGURES_RADIUS))
			(tmp)->radius = get_number_value(file_split[i]);
		else
			ft_exit(ERROR_FIGURES);
		i += 2;
		tmp = (tmp)->next;
	}
	return (i);
}

void		validation(char *arg, t_rt *rt)
{
	int		i;
	char	*file;
	char	*filename;
	char	**file_split;

	i = -1;
	if (!(filename = check_argument(arg)))
		ft_exit(ERROR_INPUT);
	if (!(file = read_big_file(file, filename)))
		ft_exit(ERROR_READ_BIG_FILE);
	if (!(file_split = ft_strsplit(file, '\n')))
		ft_exit(ERROR_STRSPLIT);
	i = (find_camera(i, file_split, &(rt->camera)));
	i = (find_lights(i, file_split, &rt->light));
	i = (find_figures(i, file_split, &rt->figure));
	if (file_split[i])
		ft_exit(ERROR_INPUT);
	free(file);
	ft_destroy_string_arr(file_split);
}

