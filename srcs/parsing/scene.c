/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:07:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/10 21:40:04 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

char	**remove_map_from_scene(t_data *data)
{
	char	**new_scene;
	int		i;
	
	new_scene = ft_calloc(sizeof(char *), 7);
	if (!new_scene)
		return (NULL);
	i = -1;
	while (i++ < 5)
		new_scene[i] = data->scene[i]; // strdup ?
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

int		scene_len(char *scene_path)
{
	int		len;
	char	*line;
	int		fd;

	fd = open(scene_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr(E_OPEN_FAIL, 2), -1);
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
	printf("scene_len len = %i\n", len); // dev
	return (close(fd), len);
}

char	**get_scene(char *scene_path)
{
	char	**scene;
	int		fd;
	int		i;
	int		len;

	i = 0;
	fd = open(scene_path, O_RDONLY); // close ?
	if (fd < 0)
		return (ft_putstr(E_OPEN_FAIL, 2), NULL);
	len = scene_len(scene_path);
	if (len == -1)
		return (NULL);
	scene = ft_calloc(sizeof(char *), len + 1);
	scene[i] = get_next_line(fd);
	while (scene[i])
	{
		if (line_is_empty(scene[i]))
			scene[i] = get_next_line(fd);
		else
			scene[++i] = get_next_line(fd);
	}
	scene[i] = NULL;
	print_scene(scene); // dev
	return (clean_scene(scene));
}