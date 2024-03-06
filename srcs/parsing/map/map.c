/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:50:42 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/06 03:21:59 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static		void resize_map(t_map *map) //merge in cpy_map
{
	char	*tmp;
	int		y;
	int		x;

	y = -1;
	while (map->map[++y])
	{
		x = 0;
		tmp = map->map[y];
		while (map->map[y][x] && map->map[y][x] != '\n') 
			x++;
		while (x < map->map_width)
		{
			map->map[y][x] = ' ';
			x++;
		}
		map->map[y][x] = '\0';
	}
}

static	void	get_map_size(t_scene *scene) // merge in cpy_map
{
	int	x;
	int	y;
	int	z;

	y = 0;
	z = 0;
	while (scene->map->map[y])
	{
		x = ft_strlen(scene->map->map[y]);
		if (x > z)
			z = x;
		y++;
	}
	scene->map->map_height = scene->height - INFOS_LEN;
	scene->map->map_width = z - 1;
}

static void cpy_map(t_scene *scene)
{
	int 	i;
	int 	y;
	int 	len;
	
	i = INFOS_LEN;
	y = 0;
	while (scene->scene[i] && scene->scene[i] != '\n')
	{
		scene->map->map[y++] = scene->scene[i++];
		
	}
	scene->map->map[y] = NULL;
}

bool	get_map(t_data *data)
{
	t_map	map;
	int		fd;
	
	map = (t_map){0};
	data->scene->map = &map;
	map.map = malloc(sizeof(char *) * (data->scene->height - 5)); //-INFOS_LEN + 1
	if (!map.map)
		return (data->error->error_g |= ERROR_MALLOC, EXIT_FAILURE);
	cpy_map(data->scene);
	get_map_size(data);
	if (resize_map(&map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
