/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/27 18:15:48 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_error	error;
	
	data = (t_data){0};
	error = (t_error){0};

	data.error = &error;
	
	if (parsing(argc, argv, &data))
		return (free_all(&data), 1);
	// if (init_data(&data))
	// 	return (free_all(&data), parsing_msg_error(data.error), 1);
	if (game_management(&data))
		return (free_all(&data), parsing_msg_error(data.error), 1);
	return (free_all(&data), 0);
}
