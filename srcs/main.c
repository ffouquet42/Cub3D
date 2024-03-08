/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/08 15:34:39 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void print_map(char **map)
{
	printf("%s", "map:\n");
	int i = 0;
	while(map[i])
	{
		printf("%s%i%s", "ligne", i, map[i]);
		i++;
	}
	printf("%s", "\n");
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_error	error;
	t_scene	scene;
	t_infos infos;
	t_map 	map;
	
	data = (t_data){0};
	error = (t_error){0};
	data.error = &error;
	scene = (t_scene){0};
	data.scene = &scene;
	infos = (t_infos){0};
	data.scene->infos = &infos;
	map = (t_map){0};
	data.scene->map = &map;
	write(1, "Loading...\n", 11);
	if (parsing(argc, argv, &data))
		return (msg_error(data.error), free_all(&data), EXIT_FAILURE);
	write(1, "Launch game...\n",15);
	// if (game_management(&data))
	// 	return (free_all(&data), parsing_msg_error(data.error), EXIT_FAILURE);
	return (free_all(&data), EXIT_SUCCESS);
}
