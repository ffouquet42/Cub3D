/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/19 16:46:02 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_data *data;
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_memset(data, 0, sizeof(t_data));
	
	init_struct(data);
	if (parsing(argc, argv, data))
		return (free_all(data), 1);
	if (init_data(data))
	 	return(free_all(data), parsing_msg_error(data->error), 1);
	if (game_management(data))
	 	return(free_all(data), parsing_msg_error(data->error), 1);
	return (free_all(data), 0);
}
