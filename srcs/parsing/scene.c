/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:07:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/12 13:04:31 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	**remove_map_from_scene(t_data *data)
{
	char	**new_scene;
	int		i;
	
	new_scene = ft_calloc(sizeof(char *), 7);
	if (!new_scene)
		return (NULL);
	i = -1;
	while (i++ < 5)
		new_scene[i] = ft_strdup(data->scene[i]);
	return (new_scene);
}

char	**clean_scene(char **scene)
{
	char	*tmp;
	int 	i;
	int 	j;
	int 	k;

	i = 0;
	while (i < 6)
	{
		j = 0;
		k = 0;
		tmp = scene[i];
		while (tmp[j])
		{
			if (tmp[j] != ' ')
			{
				scene[i][k++] = tmp[j++];
			}
			else
				j++;
		}
		scene[i][k] = '\0';
		i++;
	}
	return (scene);
}

bool	line_is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\n' || str[i] == '\0')
		return (1);
	return (0);
}

int		scene_len(char *scene_path, t_data *data)
{
	int		len;
	char	*line;
	int		fd;

	fd = open(scene_path, O_RDONLY);
	if (fd < 0 || fd > 1024)
		return (data->error->error_g |= ERROR_FILE, close (fd), -1);
	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line_is_empty(line))
			line = get_next_line(fd);
		else
		{
			len++;
			line = get_next_line(fd);
		}
	}
	return (close(fd), len);
}

bool	get_scene(char *scene_path, t_data *data)
{
	char	**scene;
	int		fd;
	int		i;

	data->map_height = scene_len(scene_path, data);
	if (data->map_height < 3)
		return (data->error->error_g |= ERROR_EMPTY, 1);
	i = 0;
	fd = open(scene_path, O_RDONLY); // close à la fin, à test
	if (fd < 0 || fd > 1024)
		return (data->error->error_g |= ERROR_FILE, close (fd), 1);
	scene = malloc(sizeof(char *) * (data->map_height + 1));
	if (!scene)
		return (data->error->error_g |= ERROR_MALLOC, close(fd), 1); // DEFINE ERROR MALLOC
	scene[i] = get_next_line(fd);
	while (scene[i])
	{
		if (line_is_empty(scene[i]))
			scene[i] = get_next_line(fd);
		else
			scene[++i] = get_next_line(fd);
	}
	scene[i] = NULL;
 	close(fd);
	data->scene = clean_scene(scene);
	return (0);
}