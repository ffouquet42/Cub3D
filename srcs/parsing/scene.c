/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:07:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/29 04:34:55 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	remove_map_from_scene(t_data *data)
{
	int		i;

	data->f_scene = malloc(sizeof(char *) * (7));
	if (!data->f_scene)
		return (data->error->error_g |= ERROR_MALLOC, 1);
	i = 0;
	while (i < 6)
	{	
		data->f_scene[i] = data->scene[i];
		i++;
	}
	data->f_scene[i] = NULL;
	if (!data->f_scene)
		return (data->error->error_g |= ERROR_RM_MAP, 1);
	return (0);
}

void	clean_scene(t_data *data)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 6)
	{
		j = 0;
		k = 0;
		tmp = data->scene[i];
		while (tmp[j])
		{
			if (tmp[j] != ' ')
				data->scene[i][k++] = tmp[j++];
			else
				j++;
		}
		data->scene[i][k] = '\0';
		i++;
	}
}

bool	get_scene(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (data->error->error_g |= ERROR_MALLOC, 1);
	while (line)
	{
		if (!line_is_empty(line))
			data->scene[i++] = line;
		else
		{
			if (i > 6 && i < data->scene_height)
			{
				free(line);
				data->scene[i] = NULL;
				return (data->error->error_g |= ERROR_EMPTY_LINE, 1);
			}
			free(line);
		}
		line = get_next_line(fd);
	}
	data->scene[i] = NULL;
	return (0);
}

int	scene_len(char *scene_path, t_data *data)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(scene_path, O_RDONLY);
	if (fd < 0 || fd > 1024)
		return (data->error->error_g |= ERROR_FILE, close (fd), -1); //check close
	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (data->error->error_g |= ERROR_MALLOC, close (fd), -1); // change error
	while (line)
	{		
		if (!(line_is_empty(line)))
			len++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (close(fd), len);
}

bool	get_data_scene(char **scene_path, t_data *data)
{
	int		fd;

	data->scene_height = scene_len(scene_path[1], data);
	if (data->scene_height < 9)
		return (data->error->error_g |= ERROR_EMPTY, 1);
	fd = open(scene_path[1], O_RDONLY);
	if (fd < 0 || fd > 1024)
		return (data->error->error_g |= ERROR_FILE, close (fd), 1); // verif close
	data->scene = malloc(sizeof(char *) * (data->scene_height + 1));
	if (!data->scene)
		return (data->error->error_g |= ERROR_MALLOC, close(fd), 1);
	if (get_scene(fd, data))
		return (1);
	if (!data->scene)
		return (data->error->error_g |= ERROR_SCENE, 1);
	clean_scene(data);
	if (!data->scene)
		return (data->error->error_g |= ERROR_SCENE, 1);
	return (0);
}
