/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/26 18:04:18 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_error	error;
	// t_game	game;
	// t_key	key;
	// t_raycast ray;
	// t_image image;
	
	// t_data data = {0};
	ft_memset(&data, 0, sizeof(t_data));
	ft_memset(&error, 0, sizeof(t_error));
	// ft_memset(&key, 0, sizeof(t_key));
	// ft_memset(&game, 0, sizeof(t_game));
	// ft_memset(&ray, 0, sizeof(t_raycast));
	// ft_memset(&image, 0, sizeof(t_image));
	data.error = &error;
	// data.game = &game;
	// data.key = &key;
	// data.ray = &ray;
	// data.img = &image;
	
	if (parsing(argc, argv, &data))
		return (free_all(&data), 1);
	if (init_data(&data))
		return (free_all(&data), parsing_msg_error(data.error), 1);
	// if (game_management(&data))
	// 	return (free_all(&data), parsing_msg_error(data.error), 1);
	return (free_all(&data), 0);
}
