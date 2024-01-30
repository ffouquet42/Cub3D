/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:07:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/30 11:03:35 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int		scene_len(char *scene_path)
{
	int		len;    
	int		map;  // $
	char	*line;
	int		fd;

	fd = open(scene_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr(E_OPEN_FAIL, 2), -1);
	len = 0;
	map = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!line_is_empty(line) && !ft_strchr(scene_path, ',')
			&& !ft_strchr(scene_path, '.'))
			map = 1; //
		if (line_is_empty(scene_path) && !map)
		{
			line = get_next_line(fd);
			continue ; //
		}
		len++;
		line = get_next_line(fd);
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
	fd = open(scene_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr(E_OPEN_FAIL, 2), NULL);
	len = scene_len(scene_path);
	if (len == -1)
		return (NULL);
	scene = ft_calloc(sizeof(char *), len + 1);
	scene[i] = get_next_line(fd);
	while (scene[i])
		scene[++i] = get_next_line(fd);
	scene[i] = NULL;
	print_scene(scene); // dev
	return (scene);
}

// dev
void	print_scene(char **scene)
{
	int i = 0;
	while (scene[i])
	{
		printf("scene[%i] = %s", i, scene[i]);
		i++;
	}
	printf("\nscene[%i] = %s\n", i, scene[i]);
}