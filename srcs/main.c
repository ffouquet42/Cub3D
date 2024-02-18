/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/18 19:42:47 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	// fct init strcut ?
	t_error	error;
	t_data	data;

	error = (t_error){0};
	data = (t_data){0};
	data.error = &error;
	
	if (parsing(argc, argv, &data))
		return (free_all(&data), 1);
	if (init_data(&data))
	{
		free_all(&data);
	 	return(parsing_msg_error(data.error), 1);
	}
	if (game_management(&data))
	{
		printf("Error Thread");
		free_all(&data);
	 	return(parsing_msg_error(data.error), 1);
	}
	printf("Main Thread");
	return (free_all(&data), 0);
}
