/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:57:27 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/21 19:50:00 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_first_orientation_two(t_data *data, char c)
{
	if (c == 'N')
	{
		data->game->player_or_x = 0;
		data->game->player_or_y = 1;
		data->game->plane_x = -0.66;
		data->game->plane_y = 0;
	}
	if (c == 'W')
	{
		data->game->player_or_x = -1;
		data->game->player_or_y = 0;
		data->game->plane_x = 0;
		data->game->plane_y = -0.66;
	}
}

void	get_first_orientation(t_data *data, char c)
{
	if (c == 'S')
	{
		data->game->player_or_x = 0;
		data->game->player_or_y = -1;
		data->game->plane_x = 0.66;
		data->game->plane_y = 0;
	}
	if (c == 'E')
	{
		data->game->player_or_x = 1;
		data->game->player_or_y = 0;
		data->game->plane_x = 0;
		data->game->plane_y = 0.66;
	}
	get_first_orientation_two(data, c);
}

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'W')
			{
				data->game->player_pos_x = (double)j + 0.5;
				data->game->player_pos_y = (double)i + 0.5;
				get_first_orientation(data, data->map[i][j]);
			}
			j++;
		}
		i++;
	}
}

bool	init_game(t_data *data)
{
	t_game		game;
	
	game = (t_game){0};
	data->game = &game;
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		return (data->error->error_g |= ERROR_MLX_WIN, 1);
	get_player_pos(data);
	return (0);
}
