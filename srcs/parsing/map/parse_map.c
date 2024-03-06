/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:35 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/06 03:09:46 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	bool	is_char_valid(t_data *data)
{
	int	y;
	int	x;
	int	pos;

	y = 0;
	while (data->scene->map->map[y])
	{
		x = 0;
		while (data->scene->map->map[y][x])
		{
			if (!char_is_in_set(data->scene->map->map[y][x], "01NSEW ")) //get_player_pos
				return (false);
			else if (char_is_in_set(data->scene->map->map[y][x], "NSEW"))
			{
				pos++;
				data->game->player_pos_x = (double)x;
				data->game->player_pos_y = (double)y;
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
	t_game	game;
	
	game = (t_game){0};
	data->game = &game;
	if (!is_char_valid(data))
		return (data->error->error_g |= ERROR_CHAR, 1);
//	if (one_start_pos(data))
//		return (data->error->error_g |= ERROR_START, 1);
	if (closed_by_wall(data))
		return (data->error->error_g |= ERROR_WALL, 1);
	return (0);
}
