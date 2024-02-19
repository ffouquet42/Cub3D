/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:37:11 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/19 18:37:53 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	check_hit_2(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->ray_length = data->ray->side_dist_x
			- data->ray->delta_dist_x;
	else
		data->ray->ray_length = data-> ray->side_dist_y
			- data->ray->delta_dist_y;
	if (data->ray->ray_length < 0.005)
		data->ray->ray_length = 0.005;
	data->ray->line_height = WIN_HEIGHT / (data->ray->ray_length);
}

void	check_hit(t_data *data)
{
	data->ray->hit = 0;
	while (data->ray->hit == 0)
	{
		if (data->ray->side_dist_x < data->ray->side_dist_y)
		{
			data->ray->side_dist_x += data->ray->delta_dist_x;
			data->ray->map_x += data->ray->step_x;
			data->ray->side = 0;
		}
		else
		{
			data->ray->side_dist_y += data->ray->delta_dist_y;
			data->ray->map_y += data->ray->step_y;
			data->ray->side = 1;
		}
		if (data->map[data->ray->map_y][data->ray->map_x] == '1')
			data->ray->hit = 1;
	}
	check_hit_2(data);
}
