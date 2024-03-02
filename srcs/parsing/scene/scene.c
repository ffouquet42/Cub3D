/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:07:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/02 22:57:53 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	bool	get_scene(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (data->error->error_g |= ERROR_EMPTY_S, EXIT_FAILURE);
	while (line)
	{
		if (!is_line_empty(line))
			data->scene[i++] = line;
		else
		{
			if (i > INFOS_LEN && i < data->scene_height) 
			{
				free(line);
				data->scene[i] = NULL;
				return (data->error->error_g |= ERROR_EMPTY_LINE, EXIT_FAILURE);
			}
			free(line);
		}
		line = get_next_line(fd);
	}
	data->scene[i] = NULL;
	return (EXIT_SUCCESS);
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
	if (get_scene(fd, data))
		return (EXIT_FAILURE);
	return (close(fd), 0);
}
