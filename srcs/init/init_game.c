/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:57:27 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/09 18:10:45 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_first_orientation_two(t_data *data, char c) //
{
	if (c == 'S')
	{
		data->game->player_ori_x = 0;
		data->game->player_ori_y = 1;
		data->game->plane_x = -0.66;
		data->game->plane_y = 0;
	}
	if (c == 'W')
	{
		data->game->player_ori_x = -1;
		data->game->player_ori_y = 0;
		data->game->plane_x = 0;
		data->game->plane_y = -0.66;
	}
}

void	get_first_orientation(t_data *data, char c) //
{
	if (c == 'N')
	{
		data->game->player_ori_x = 0;
		data->game->player_ori_y = -1;
		data->game->plane_x = 0.66;
		data->game->plane_y = 0;
	}
	if (c == 'E')
	{
		data->game->player_ori_x = 1;
		data->game->player_ori_y = 0;
		data->game->plane_x = 0;
		data->game->plane_y = 0.66;
	}
	get_first_orientation_two(data, c);
}

int	get_player_pos(t_data *data) //
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'S' || data->map[y][x] == 'W')
			{
				data->game->player_pos_x = x + 0.5; //
				data->game->player_pos_y = y + 0.5; //
				get_first_orientation(data, data->map[y][x]);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	init_game(t_data *data)
{
	if (init_images(data)) // bug
		return (ft_putstr(E_INIT_IMG, 2), 1);
	print_img(data); // dev
	data->win = mlx_new_window(data->mlx, data->window_x,
		data->window_y, "Cub3D");
	if (!data->win)
	{
		// mlx_do_key_autorepeaton(data->mlx); //
		// free / exit
		return (ft_putstr(E_MLX_WIN, 2), 1);
	}
	if (get_player_pos(data))
		return (ft_putstr(E_GET_P_POS, 2), 1);
	return (0);
}