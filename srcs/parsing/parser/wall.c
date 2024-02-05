/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:36:06 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/05 18:56:11 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

// 	printf("#####\n"); // dev
// 	print_map(map);
// 	printf("#####\n"); // dev

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
remplir de A
check autour des A
reprendre celui de so long du coup ?
verif les espaces en pleins milieu de la map bien entourer par des murs
*/

// printf("+++\n"); // dev
// print_map(map_cpy);
// printf("+++\n"); // dev