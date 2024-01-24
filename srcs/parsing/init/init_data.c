/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:49:44 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/24 15:32:10 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	init_data(t_data *data)
{
	data->window_x = 1920;
	data->window_y = 1080;
	data->game = malloc(sizeof(t_game));
	if (!data->game)
		return (1);
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		return (1);
	data->mini = malloc(sizeof(t_mini));
	if (!data->mini)
		return (1);
	// init values
	// init mlx 
	return (0);
}