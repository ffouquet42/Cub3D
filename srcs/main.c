/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/19 02:43:14 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

#include <string.h>
int	main(int argc, char **argv)
{
	t_data *data = (t_data *)malloc(sizeof(t_data));
	memset(data, 0, sizeof(t_data));
	data->error = (t_error *)malloc(sizeof(t_error));
	memset(data->error, 0, sizeof(t_error));
	data->game = (t_game *)malloc(sizeof(t_game));
	memset(data->game, 0, sizeof(t_game));
	data->ray = (t_raycast *)malloc(sizeof(t_raycast));
	memset(data->ray, 0, sizeof(t_raycast));
	data->img = (t_image *)malloc(sizeof(t_image));
	memset(data->img, 0, sizeof(t_image));

	if (parsing(argc, argv, data))
		return (free_all(data), 1);
	if (init_data(data))
	{
		free_all(data);
	 	return(parsing_msg_error(data->error), 1);
	}
	if (game_management(data))
	{
		free_all(data);
	 	return(parsing_msg_error(data->error), 1);
	}
	return (free_all(data), 0);
}
