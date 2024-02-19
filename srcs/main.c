/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/19 15:18:28 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

#include <string.h>
int	main(int argc, char **argv)
{
	t_data *data;
	data = malloc(sizeof(t_data));
	memset(data, 0, sizeof(t_data));
	init_struct(data);

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
