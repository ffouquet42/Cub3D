/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:07:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/29 10:27:45 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

void	*clear_line(void  *line) //
{
	//
}

int		scene_len(char *scene_path, int fd)
{
	int		len;    
	int		map;  // $
	char	*line;

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
			ft_malloc(0, 0, 1, line); // <=
			line = get_next_line(fd);
			continue ; //
		}
		ft_malloc(0, 0, 1, line);
		len++;
		line = get_next_line(fd);
	}
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
	len = scene_len(scene_path, fd);
	
	return (scene);
}