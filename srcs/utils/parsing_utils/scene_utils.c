/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 06:18:53 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/06 02:15:56 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

bool	is_line_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (str[i] == '\n' || str[i] == '\0' || str[i] == '\r');
}

int	scene_len(char *scene_path, t_data *data)
{
	int		fd;
	int		len;
	char	*line;

	fd = open(scene_path, O_RDONLY);
	if (fd < FD_MIN || fd > FD_MAX)
		return (data->error->error_g |= ERROR_FILE, close (fd), EXIT_FAILURE); //check close
	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (data->error->error_g |= ERROR_EMPTY_S, EXIT_FAILURE);
	while (line)
	{		
		if (!is_line_empty(line))
			len++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (close(fd), len);
}
