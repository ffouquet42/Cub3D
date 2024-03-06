/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:35 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/07 00:26:22 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	bool	are_chars_valid(t_map *map)
{
	int	y;
	int	x;
	int	pos;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (!is_char_in_set(map->map[y][x], "01NSEW "))
				return (false);
			else if (is_char_in_set(map->map[y][x], "NSEW"))  //get_player_pos
			{
				pos++;
				map->p_pos_x = (double)x + 0.5;
				map->p_pos_y = (double)y + 0.5;
			}
			x++;
		}
		y++;
	}
	if (pos != 1)
		return (false);
	return (true);
}

bool	parse_map(t_data *data)
{
	// data->error->error_g |= ERROR_START,
	if (!is_char_valid(data->scene->map))
		return (data->error->error_g |= ERROR_CHAR, EXIT_FAILURE);
	if (closed_by_wall(data))
		return (data->error->error_g |= ERROR_WALL, EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
