/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:14:52 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/10 19:41:19 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char		*check_argument_name(char *arg)
{
	if (ft_strcmp(arg, "1") == 0)
		return (SCENE_1);
	else if (ft_strcmp(arg, "2") == 0)
		return (SCENE_2);
	else if (ft_strcmp(arg, "3") == 0)
		return (SCENE_3);
	else if (ft_strcmp(arg, "4") == 0)
		return (SCENE_4);
	else if (ft_strcmp(arg, "5") == 0)
		return (SCENE_5);
	else if (ft_strcmp(arg, "6") == 0)
		return (SCENE_6);
	else if (ft_strcmp(arg, "7") == 0)
		return (SCENE_7);
	else if (ft_strcmp(arg, "8") == 0)
		return (SCENE_8);
	else if (ft_strcmp(arg, "9") == 0)
		return (SCENE_9);
	else
		return (NULL);
}

int			find_camera(int i, char **split, t_vector *camera)
{
	if (!split[0])
		ft_exit(ERROR_INPUT);
	if (ft_strcmp("-", split[++i]) == 0)
	{
		if (ft_strcmp(CAMERA, split[++i]) == 0)
		{
			if (ft_strstr(split[++i], CAMERA_POS))
				*camera = get_array_value(split[i]);
			else
				ft_exit(ERROR_INPUT);
		}
		else
			ft_exit(ERROR_INPUT);
	}
	else
		ft_exit(ERROR_INPUT);
	return (i + 2);
}

void		validation(char *arg, t_rt *rt)
{
	int		i;
	char	*file;
	char	*filename;
	char	**split;

	i = -1;
	if (!(filename = check_argument_name(arg)))
	{
		show_example_input();
		ft_exit(ERROR_INPUT);
	}
	if (!(file = read_big_file(file, filename)))
		ft_exit(ERROR_READ_BIG_FILE);
	if (!(split = ft_strsplit(file, '\n')))
		ft_exit(ERROR_STRSPLIT);
	i = (find_camera(i, split, &(rt->camera)));
	i = (lights_processing(i, split, &rt->light));
	i = (objects_processing(i, split, &rt->obj));
	free(file);
	ft_destroy_string_arr(split);
}
