/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:14:52 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/09 15:24:08 by sleonia          ###   ########.fr       */
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

t_lights			*new_light()
{
	t_lights		*light;

	if (!(light = (t_lights *)malloc(sizeof(t_lights))))
		ft_exit(ERROR_MALLOC);
	light->next = NULL;
	return (light);
}

t_lights			*find_light(t_rt *rt)
{
	t_lights		*light;

	light = rt->light;
	if (!light)
		return (new_light());
	while (light->next)
		light = light->next;
	light->next = new_light();
	printf("1 %p\n", rt->light);
	printf("2 %p\n", rt->light->next);
	return (light->next);
}

t_figures	*new_figure()
{
	t_figures	*figure;

	if (!(figure = (t_figures *)malloc(sizeof(t_figures))))
		ft_exit(ERROR_MALLOC);
	figure->next = NULL;
	return (figure);
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
	// printf("|%s|\n", str_split[0]);
	// printf("|%s|\n", str_split[1]);
	// printf("|%s|\n", str_split[2]);
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

int			find_camera(int i, char **file_split, t_camera *camera)
{
	if (ft_strcmp(CAMERA, file_split[i]) == 0
		&& ft_strcmp("-", file_split[i - 1]) == 0
		&& ft_strcmp("-", file_split[i + 2]) == 0)
	{
		if (ft_strstr(file_split[i + 1], CAMERA_CENTER))
			camera->position = get_array(file_split[i + 1]);
		else
			return (KO_CODE);
	}
	else
		return (KO_CODE);
	return (i + 3);
}

int			find_lights(int i, char **file_split, t_rt *rt)
{
	if (file_split[i] && (ft_strcmp(LIGHT, file_split[i]) == 0
		&& ft_strcmp("-", file_split[i - 1]) == 0))
	{
		rt->light = find_light(rt);
		printf("3 %p\n", rt->light);
		if (ft_strcmp(LIGHT_TYPE_POINT, file_split[++i]))
			rt->light->type = POINT;
		else if (ft_strcmp(LIGHT_TYPE_AMBIENT, file_split[i]))
			rt->light->type = AMBIENT;
		else if (ft_strcmp(LIGHT_TYPE_DIRECTIONAL, file_split[i]))
			rt->light->type = DIRECTIONAL;
		else
			ft_exit(ERROR_LIGHTS);
		if (ft_strcmp(LIGHT_INTENSIVE, file_split[++i]))
			rt->light->intensive = get_number_value(file_split[i]);
		else
			ft_exit(ERROR_LIGHTS);
		if (ft_strstr(file_split[++i], LIGHT_POINT))
			rt->light->point = get_array(file_split[i]);
		else
			ft_exit(ERROR_LIGHTS);
	}
	else if (ft_strcmp(FIGURES_1, file_split[i]) == 0
		|| ft_strcmp(FIGURES_2, file_split[i]) == 0
		|| ft_strcmp(FIGURES_3, file_split[i]) == 0
		|| ft_strcmp(FIGURES_4, file_split[i]) == 0)
		return (i);
	else
		ft_exit(ERROR_LIGHTS);
	return (find_lights(i + 2, file_split, rt));
}

int			find_figures(int i, char **file_split, t_figures *figure)
{
	return (OK_CODE);
}

void		validation(char *arg, t_rt *rt)
{
	int		i;
	char	*file;
	char	*filename;
	char	**file_split;

	i = 1;
	if (!(filename = check_argument(arg)))
		ft_exit(ERROR_INPUT);
	if (!(file = read_big_file(file, filename)))
		ft_exit(ERROR_READ_BIG_FILE);
	if (!(file_split = ft_strsplit(file, '\n')))
		ft_exit(ERROR_STRSPLIT);
	i = (find_camera(i, file_split, &(rt->camera)));
	// printf("%f  ->%f  ->%f  \n", rt->camera.position.x, rt->camera.position.y, rt->camera.position.y);
	i = (find_lights(i, file_split, rt)); //doesnt work
	// i = (find_lights(i, file_split, rt->light)); //doesnt work
		printf("%p\n", rt->light);
		printf("%p\n", rt->light->next);
	// printf("%d\n", i);
	printf("%d    ->  \n", rt->light->type);
	printf("%d    ->   %d\n", rt->light->type, rt->light->next->type);
	// i = (find_figures(i, file_split, rt->figure));
	free(file);
	ft_destroy_string_arr(file_split);
	printf("LOX\n");
}

