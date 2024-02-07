/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:36:06 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/07 12:51:55 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

// 	printf("#####\n"); // dev
// 	print_map(map);
// 	printf("#####\n"); // dev

int	test_around(char **map, int y, int x)
{
	printf("tested char = map[%i][%i] = [%c]\n", y, x, map[y][x]); // dev
	if (map[y - 1][x - 1] != '1' && map[y - 1][x - 1] != '-')
		return (1);
	if (map[y - 1][x] != '1' && map[y - 1][x] != '-')
		return (1);
	if (map[y - 1][x + 1] != '1' && map[y - 1][x + 1] != '-')
		return (1);
	if (map[y][x - 1] != '1' && map[y][x - 1] != '-')
		return (1);
	if (map[y][x + 1] != '1' && map[y][x + 1] != '-')
		return (1);
	if (map[y + 1][x - 1] != '1' && map[y + 1][x - 1] != '-')
		return (1);
	if (map[y + 1][x] != '1' && map[y + 1][x] != '-')
		return (1);
	if (map[y + 1][x + 1] != '1' && map[y + 1][x + 1] != '-')
		return (1);
	return (0);
}

int	no_void_around(t_data *data, char **map)
{
	int	y;
	int	x;

	y = 1;
	while (y < data->map_height - 1)
	{
		x = 1;
		while (x < data->map_width - 1)
		{
			if (map[y][x] == '-')
			{
				if (test_around(map, y, x))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	fill_map(t_data *data, char **map, char *to_replace)
{
	int	y;
	int	x;

	y = 1;
	while (y < data->map_height - 1)
	{
		x = 1;
		while (x < data->map_width - 1)
		{
			if (char_is_in_set(map[y][x], to_replace))
				map[y][x] = '-';
			x++;
		}
		y++;
	}
	printf("#####\n"); // dev
	print_map(map); // dev
	printf("#####\n"); // dev
	if (no_void_around(data, map))
		return (1);
	return (0);
}

char	**copy_map(t_data *data)
{
	char	**map_cpy;
	int		i;

	map_cpy = malloc(sizeof(char *) * (data->map_height + 1));
	if (!map_cpy)
		return (NULL);
	i = 0;
	while (i < data->map_height)
	{
		map_cpy[i] = ft_strdup(data->map[i]);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int	closed_by_wall(t_data *data)
{
	int		i;
	char	**map_cpy;

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
	map_cpy = copy_map(data);
	if (!map_cpy)
		return (1);
	if (fill_map(data, map_cpy, "0NSEW"))
		return (1);
	return (0);
}

/*
ca fait quoi si ya deja des '-' dans la map ? sur les bords ou autres
*/
