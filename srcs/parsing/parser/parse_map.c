/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:35 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/07 14:21:16 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

// printf("c = %c\n", c); // dev
// printf("y = %i\n", y); // dev

int	char_is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	one_start_pos(t_data *data)
{
	int	pos;
	int	y;
	int	x;
	
	pos = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (char_is_in_set(data->map[y][x], "NSEW"))
				pos++;
			x++;
		}
		y++;
	}
	if (pos != 1)
		return (1);
	return (0);
}

int	is_map_char(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i]) // + \n ?
			return (1);
		i++;
	}
	return (0);
}

int	check_map_char(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (!is_map_char(data->map[y][x], "01NSEW "))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	parse_map(t_data *data)
{
	if (check_map_char(data))
		return (ft_putstr(E_MAP_CHAR, 2), 1);
	if (one_start_pos(data))
		return (ft_putstr(E_ONE_START, 2), 1);
	if (closed_by_wall(data))
		return (ft_putstr(E_CLO_WALL, 2), 1);
	return (0);
}