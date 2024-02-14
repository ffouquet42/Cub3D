/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:07:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/14 07:39:15 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	remove_map_from_scene(t_data *data) // possible sans calloc et strdup?
{
	char	**new_scene;
	int		i;
	
	new_scene = ft_calloc(sizeof(char *), 7);
	if (!new_scene)
		return (NULL);
	i = -1;
	while (i++ < 5)
		new_scene[i] = ft_strdup(data->scene[i]); // strdup oblige?
	data->scene = new_scene;
	if (!data->scene)
		return (data->error->error_g |= ERROR_SCENE	, 1);
	return(0);
}

void	clean_scene(t_data *data)
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
		free(line);
		line = get_next_line(fd);
	}
	data->scene[i] = NULL;
	free(line);
	return (0);
}

int		scene_len(char *scene_path, t_data *data)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(scene_path, O_RDONLY);
	if (fd < 0 || fd > 1024)
		return (data->error->error_g |= ERROR_FILE, close (fd), -1); // close(fd)?
	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (data->error->error_g |= ERROR_MALLOC, close (fd), -1);
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

bool	get_data_scene(char *scene_path, t_data *data)
{
	int		fd;
	
	data->scene_height = scene_len(scene_path, data);
	if (data->scene_height < 9) //6 + 3 lignes de map min
		return (data->error->error_g |= ERROR_EMPTY, 1);
	fd = open(scene_path, O_RDONLY); // close à la fin, à test
	if (fd < 0 || fd > 1024)
		return (data->error->error_g |= ERROR_FILE, close (fd), 1); // close?
	data->scene = malloc(sizeof(char *) * (data->scene_height + 1));
	if (!data->scene)
		return (data->error->error_g |= ERROR_MALLOC, close(fd), 1);
	if(get_scene(fd, data))
		return (1);
	if(!data->scene)
		return (data->error->error_g |= ERROR_SCENE, 1);
	clean_scene(data);
	if(!data->scene)
		return (data->error->error_g |= ERROR_SCENE, 1);
	return (close(fd),0);
}
