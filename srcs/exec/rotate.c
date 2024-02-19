/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:13:19 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/19 18:23:46 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_rotate_speed(t_data *data)
{
	if (data->mouse)
		data->rotation_speed = (double)ROTSPEED
			* (double)((double)1 + 20 // Mouse Ratio
				* (double)((double)((int)fabs((double)data->mouse_x
							- (double)(WIN_WIDTH / 2))
						/ (double)(WIN_WIDTH / 2))));
	else
		data->rotation_speed = ROTSPEED;
}

void	rotate_right(t_data *data)
{
	double		old_dir_x;
	double		old_plane_x;

	get_rotate_speed(data);
	old_dir_x = data->game->player_or_x;
	data->game->player_or_x = data->game->player_or_x
		* cos(data->rotation_speed)
		- data->game->player_or_y * sin(data->rotation_speed);
	data->game->player_or_y = old_dir_x * sin(data->rotation_speed)
		+ data->game->player_or_y * cos(data->rotation_speed);
	old_plane_x = data->game->plane_x;
	data->game->plane_x = data->game->plane_x * cos(data->rotation_speed) - \
		data->game->plane_y * sin(data->rotation_speed);
	data->game->plane_y = old_plane_x * sin(data->rotation_speed)
		+ data->game->plane_y * cos(data->rotation_speed);
}

void	rotate_left(t_data *data)
{
	double		old_dir_x;
	double		old_plane_x;

	get_rotate_speed(data);
	old_dir_x = data->game->player_or_x;
	data->game->player_or_x = data->game->player_or_x
		* cos(-data->rotation_speed)
		- data->game->player_or_y * sin(-data->rotation_speed);
	data->game->player_or_y = old_dir_x * sin(-data->rotation_speed)
		+ data->game->player_or_y * cos(-data->rotation_speed);
	old_plane_x = data->game->plane_x;
	data->game->plane_x = data->game->plane_x * cos(-data->rotation_speed)
		- data->game->plane_y * sin(-data->rotation_speed);
	data->game->plane_y = old_plane_x * sin(-data->rotation_speed)
		+ data->game->plane_y * cos(-data->rotation_speed);
}
