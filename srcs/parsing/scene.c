/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:07:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/29 11:17:26 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void print_map(char **map)
{
	int i = 0;
	int j = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
	}
	printf("%s", "\n");
}

static	bool	sort_infos(char **infos)
{
	char		*tmp;
	uint8_t		i;

	i = 0;
	while (i < INFOS_LEN)
	{
		tmp = infos[i];
		if (tmp[0] == 'N' && tmp[1] == 'O')
			infos[0] = tmp;
		else if (tmp[0] == 'S' && tmp[1] == 'O')
			infos[1] = tmp;
		else if (tmp[0] == 'E' && tmp[1] == 'A')
			infos[2] = tmp;
		else if (tmp[0] == 'W' && tmp[1] == 'E')
			infos[3]= tmp;
		else if (tmp[0] == 'F')
			infos[4]= tmp;
		else if (tmp[0] == 'C')
			infos[5] = tmp;
		i++;
	}
	infos[6] = NULL;
	return (EXIT_SUCCESS);
}

static	void	clean_infos(t_data *data)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < INFOS_LEN)
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

static	bool	get_infos(t_data *data)
{
	int		i;

	clean_infos(data);
	data->infos = malloc(sizeof(char *) * (7));
	if (!data->infos)
		return (data->error->error_g |= ERROR_MALLOC, EXIT_FAILURE);
	i = 0;
	while (i < INFOS_LEN)
	{	
		data->infos[i] = data->scene[i]; // one line
		i++;
	}
	data->infos[i] = NULL;
	return (EXIT_SUCCESS);
}

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
	print_map(data->scene);
	if (get_infos(data))
		return (EXIT_FAILURE);
	print_map(data->infos);
	if (sort_infos(data->infos))
		return (EXIT_FAILURE);
	print_map(data->infos);
	return (close(fd),0);
}
