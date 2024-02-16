/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:36:06 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/16 05:47:31 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	test_around(char **map, int y, int x, char *to_replace)
{
	if (map[y - 1][x - 1] != '1' && !is_start_pos(map[y - 1][x - 1], to_replace))
		return (1);
	if (map[y - 1][x] != '1' && !is_start_pos(map[y - 1][x], to_replace))
		return (1);
	if (map[y - 1][x + 1] != '1' && !is_start_pos(map[y - 1][x + 1], to_replace))
		return (1);
	if (map[y][x - 1] != '1' && !is_start_pos(map[y][x - 1], to_replace))
		return (1);
	if (map[y][x + 1] != '1' && !is_start_pos(map[y][x + 1], to_replace))
		return (1);
	if (map[y + 1][x - 1] != '1' && !is_start_pos(map[y + 1][x - 1], to_replace))
		return (1);
	if (map[y + 1][x] != '1' && !is_start_pos(map[y + 1][x], to_replace))
		return (1);
	if (map[y + 1][x + 1] != '1' && !is_start_pos(map[y + 1][x + 1], to_replace))
		return (1);
	return (0);
}

bool	is_start_pos(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

bool	no_void_around(t_data *data, char *to_replace)
{
	int	y;
	int	x;

	y = 1;
	while (y < data->map_height - 1)
	{
		x = 1;
		while (x < data->map_width - 1)
		{
			if (is_start_pos(data->map[y][x], to_replace))
			{
				if (test_around(data->map, y, x, to_replace))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

bool	fill_map(t_data *data, char *to_replace)
{
	if (no_void_around(data, to_replace))
		return (1);
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
	if (fill_map(data, "0NSEW"))
		return (1);
	return (0);
}

