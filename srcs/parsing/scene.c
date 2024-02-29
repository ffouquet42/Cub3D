/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:07:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/29 08:10:13 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	get_info_from_scene(t_data *data)
{
	int		i;

	data->infos = malloc(sizeof(char *) * (7));
	if (!data->infos)
		return (data->error->error_g |= ERROR_MALLOC, EXIT_FAILURE);
	i = 0;
	while (i < SCENE_LEN)
	{	
		data->infos[i] = data->scene[i];
		i++;
	}
	data->infos[i] = NULL;
	return (EXIT_SUCCESS);
}

static	void	clean_scene(t_data *data)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < SCENE_LEN)
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

static	bool	get_infos(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (data->error->error_g |= ERROR_EMPTY_S, 1);
	while (line)
	{
		if (!is_line_empty(line))
			data->scene[i++] = line;
		else
		{
			if (i > SCENE_LEN && i < data->scene_height) //elsif
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

bool	parse_scene(char **scene_path, t_data *data)
{
	int		fd;

	data->scene_height = scene_len(scene_path[1], data);
	if (data->scene_height < 9)
		return (data->error->error_g |= ERROR_EMPTY_S, EXIT_FAILURE);
	fd = open(scene_path[1], O_RDONLY);
	if (fd < FD_MIN || fd > FD_MAX)
		return (data->error->error_g |= ERROR_FILE, close (fd), EXIT_FAILURE); // verif close
	data->scene = malloc(sizeof(char *) * (data->scene_height + 1));
	if (!data->scene)
		return (data->error->error_g |= ERROR_MALLOC, close(fd), EXIT_FAILURE);
	if (get_infos(fd, data))
		return (EXIT_FAILURE);
	if (!data->scene)
		return (data->error->error_g |= ERROR_SCENE, EXIT_FAILURE);
	clean_scene(data);
	if (get_info_from_scene(data))
		return (EXIT_FAILURE);
	return (close(fd),0);
}
