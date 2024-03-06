/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:07:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/06 21:51:43 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

// void	clean_nl_scene(t_data *data)
// {
// 	uint8_t		i;
// 	int			j;

// 	i = 0;
// 	while (data->infos[i])
// 	{
// 		j = 0;
// 		while (data->infos[i][j])
// 		{
// 			if (data->infos[i][j] == '\n' || data->infos[i][j] == '\r')
// 				data->infos[i][j] = '\0';
// 			j++;
// 		}
// 		i++;
// 	}
// }

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
			data->scene->scene[i++] = line;
		else
		{
			if (i > INFOS_LEN && i < data->scene->height) 
			{
				free(line);
				data->scene->scene[i] = NULL;
				return (data->error->error_g |= ERROR_EMPTY_LINE, EXIT_FAILURE);
			}
			free(line);
		}
		line = get_next_line(fd);
	}
	data->scene->scene[i] = NULL;
	return (EXIT_SUCCESS);
}

bool		parse_scene(char **scene_path, t_data *data)
{
	t_scene	scene;
	int		fd;
	
	scene = (t_scene){0};
	data->scene = &scene;
	scene.height = scene_len(scene_path[1], data);
	if (scene.height < 9)
		return (data->error->error_g |= ERROR_EMPTY_S, EXIT_FAILURE);
	fd = open(scene_path[1], O_RDONLY);
	if (fd < FD_MIN || fd > FD_MAX)
		return (data->error->error_g |= ERROR_FILE, close (fd), EXIT_FAILURE); // verif close
	scene.scene = malloc(sizeof(char *) * (scene.height + 1));
	if (!scene.scene)
		return (data->error->error_g |= ERROR_MALLOC, close(fd), EXIT_FAILURE);
	if (get_scene(fd, data))
		return (EXIT_FAILURE);
	// clean_nl_scene(data); 
	return (close(fd), 0);
}
