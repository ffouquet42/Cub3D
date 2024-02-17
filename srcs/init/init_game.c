/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:57:27 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/17 22:31:18 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// void	get_first_orientation_two(t_data *data, char c) //
// {
// 	if (c == 'S')
// 	{
// 		data->game->player_ori_x = 0;
// 		data->game->player_ori_y = 1;
// 		data->game->plane_x = -0.66;
// 		data->game->plane_y = 0;
// 	}
// 	if (c == 'W')
// 	{
// 		data->game->player_ori_x = -1;
// 		data->game->player_ori_y = 0;
// 		data->game->plane_x = 0;
// 		data->game->plane_y = -0.66;
// 	}
// }

// void	get_first_orientation(t_data *data, char c) //
// {
// 	if (c == 'N')
// 	{
// 		data->game->player_ori_x = 0;
// 		data->game->player_ori_y = -1;
// 		data->game->plane_x = 0.66;
// 		data->game->plane_y = 0;
// 	}
// 	if (c == 'E')
// 	{
// 		data->game->player_ori_x = 1;
// 		data->game->player_ori_y = 0;
// 		data->game->plane_x = 0;
// 		data->game->plane_y = 0.66;
// 	}
// 	get_first_orientation_two(data, c);
// }

// bool	get_player_pos(t_data *data) 
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (data->map[y])
// 	{
// 		x = 0;
// 		while (data->map[y][x])
// 		{
// 			if (data->map[y][x] == 'N' || data->map[y][x] == 'E'
// 				|| data->map[y][x] == 'S' || data->map[y][x] == 'W')
// 			{
// 				data->game->player_pos_x = x + 0.5; //
// 				data->game->player_pos_y = y + 0.5; //
// 				get_first_orientation(data, data->map[y][x]);
// 				return (0);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (1);
// }

bool	init_game(t_data *data)
{
	data->win = mlx_new_window(data->mlx, 
		data->images[0].img_width * data->map_width, 
		data->images[0].img_height * data->map_height, "Cub3D");
	if (!data->win)
		return (data->error->error_g |= ERROR_MLX_WIN, 1);
	if (get_player_pos(data))
		return (data->error->error_g |= ERROR_POS, 1);
	print_map(data);
	mlx_key_hook(data->win, (void *)move_player, data);
	mlx_hook(data->win, 17, 0, (void *)free_mlx, data);
	mlx_loop(data->mlx);

	return (0);
}