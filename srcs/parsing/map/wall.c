/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:36:06 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/06 22:55:21 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

bool	test_around(char **map, int y, int x, char *charset)
{
	if (map[y - 1][x] != '1' && !char_is_in_set(map[y - 1][x], charset))
		return (1);
	if (map[y][x - 1] != '1' && !char_is_in_set(map[y][x - 1], charset))
		return (1);
	if (map[y][x + 1] != '1' && !char_is_in_set(map[y][x + 1], charset))
		return (1);
	if (map[y + 1][x] != '1' && !char_is_in_set(map[y + 1][x], charset))
		return (1);
	return (0);
}

bool	is_void_around(t_map *map, char *charset)
{
	int	y;
	int	x;

	y = 1;
	while (y < map->height - 1)
	{
		x = 1;
		while (x < map->width - 1)
		{
			if (is_char_in_set(map->map[y][x], charset))
			{
				if (test_around(map->map, y, x, charset))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

bool	is_closed_by_wall(t_map *map)
{
	int		i;

	i = 0;

	// 2 fct 
	while (i < map->width)
	{
		if ((map->map[0][i] != '1' && map->map[0][i] != ' ')
			|| (map->map[map->height - 1][i] != '1'
			&& map->map[map->height - 1][i] != ' '))
			return (false);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if ((map->map[i][0] != '1' && map->map[i][0] != ' ')
			|| (map->map[i][map->width - 1] != '1'
			&& map->map[i][map->width - 1] != ' '))
			return (false);
		i++;
	}
	if (no_void_around(map, "0NSEW"))
		return (false);
	return (true);
}
