/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:07:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/29 13:11:36 by mfeldman         ###   ########.fr       */
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

static	bool	sort_infos(t_data *data)
{
	uint8_t i; 
	 
	while (data->sort_index < INFOS_LEN) //infos[i]
	{
		i = data->sort_index;	
		if (data->infos[i][0] == 'N' && data->infos[i][1] == 'O')
			ft_swap(data, 0);
		else if (data->infos[i][0] == 'S' && data->infos[i][1] == 'O')
			ft_swap(data, 1);
		else if (data->infos[i][0] == 'E' && data->infos[i][1] == 'A')
			ft_swap(data, 2);
		else if (data->infos[i][0] == 'W' && data->infos[i][1] == 'E')
			ft_swap(data, 3);
		else if (data->infos[i][0] == 'F')
			ft_swap(data, 4);
		else if (data->infos[i][0] == 'C')
			ft_swap(data, 5);
		data->sort_index++;
	}
	data->infos[6] = NULL;
	return (EXIT_SUCCESS);
}

static	void	clean_infos(t_data *data) //merge with get_info
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
	if (get_scene(fd, data) || get_infos(data))
		return (EXIT_FAILURE);
	print_map(data->infos);
	if (sort_infos(data))
		return (EXIT_FAILURE);
	print_map(data->infos);
	return (close(fd),0);
}
