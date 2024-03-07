/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/08 00:52:43 by mfeldman         ###   ########.fr       */
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
	
	data = (t_data){0};
	error = (t_error){0};
	data.error = &error;
	write(1, "Loading...",10);
	//init_struct
	if (parsing(argc, argv, &data))
		return (msg_error(data.error), free_all(&data), EXIT_FAILURE);
	// if (game_management(&data))
	// 	return (free_all(&data), parsing_msg_error(data.error), EXIT_FAILURE);
	return (free_all(&data), EXIT_SUCCESS);
}
