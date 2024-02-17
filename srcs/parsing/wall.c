/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:36:06 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/17 16:42:18 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	test_around(char **map, int y, int x, char *charset)
{
	if (map[y - 1][x - 1] != '1' && !char_is_in_set(map[y - 1][x - 1], charset))
		return (1);
	if (map[y - 1][x] != '1' && !char_is_in_set(map[y - 1][x], charset))
		return (1);
	if (map[y - 1][x + 1] != '1' && !char_is_in_set(map[y - 1][x + 1], charset))
		return (1);
	if (map[y][x - 1] != '1' && !char_is_in_set(map[y][x - 1], charset))
		return (1);
	if (map[y][x + 1] != '1' && !char_is_in_set(map[y][x + 1], charset))
		return (1);
	if (map[y + 1][x - 1] != '1' && !char_is_in_set(map[y + 1][x - 1], charset))
		return (1);
	if (map[y + 1][x] != '1' && !char_is_in_set(map[y + 1][x], charset))
		return (1);
	if (map[y + 1][x + 1] != '1' && !char_is_in_set(map[y + 1][x + 1], charset))
		return (1);
	return (0);
}

bool	no_void_around(t_data *data, char *charset)
{
	int	y;
	int	x;

	y = 1;
	while (y < data->map_height - 1)
	{
		x = 1;
		while (x < data->map_width - 1)
		{
			if (char_is_in_set(data->map[y][x], charset))
			{
				if (test_around(data->map, y, x, charset))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

bool	closed_by_wall(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->map_width)
	{
		if ((data->map[0][i] != '1' && data->map[0][i] != ' ')
			|| (data->map[data->map_height - 1][i] != '1'
			&& data->map[data->map_height - 1][i] != ' '))
			return (1);
		i++;
	}
	i = 0;
	while (i < data->map_height)
	{
		if ((data->map[i][0] != '1' && data->map[i][0] != ' ')
			|| (data->map[i][data->map_width - 1] != '1'
			&& data->map[i][data->map_width - 1] != ' '))
			return (1);
		i++;
	}
	if (no_void_around(data, "0NSEW"))
		return (1);
	return (0);
}
