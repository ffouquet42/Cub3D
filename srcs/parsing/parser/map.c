/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:50:42 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/04 16:54:52 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

char	**resize_map(char **map, t_data *data) // char de trop
{
	int		y;
	int		x;
	char	*dest;

	y = 0;
	while (map[y])
	{
		x = 0;
		dest = ft_calloc(sizeof(char), data->map_width);
		while (map[y][x] && map[y][x] != '\n')
		{
			dest[x] = map[y][x];
			x++;
		}
		while (x < data->map_width)
		{
			dest[x] = ' ';
			x++;
		}
		dest[x] = '\0';
		map[y] = dest;
		y++;
	}
	return (map);
}

void	get_map_size(char **map, t_data *data)
{
	int	y;
	int	x;
	int	z;

	y = 0;
	z = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x > z)
			z = x;
		y++;
	}
	data->map_height = y;
	data->map_width = z - 1;
	return ;
}

char	**get_map(char **scene, t_data *data)
{
	char	**map;
	int		i;
	int		j;
	int		x;

	i = 6;
	j = 0;
	x = 0;
	while (scene[i++])
		j++;
	map = malloc(sizeof(char *) * (j + 1));
	if (!map)
		return (NULL);
	i = 6;
	while (scene[i])
		map[x++] = ft_strdup(scene[i++]);
	map[x] = NULL;
	get_map_size(map, data);
	return (resize_map(map, data));
}