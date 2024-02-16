/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:53:22 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/16 05:37:48 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_cub(char **argv)
{
	uint16_t len;

	len = ft_strlen(argv[1]);
	if (argv[1][len - 4] != '.' || argv[1][len -  3] != 'c' ||
		argv[1][len - 2] != 'u' || argv[1][len - 1] != 'b')
		return (1); 
	return (0);
}

bool	check_args(int argc, char **argv, t_data *data)
{	
	int	fd;

	if (argc != 2)
		return (data->error->error_g |= ERROR_ARG, 1);
	fd = open(argv[1], O_RDONLY);
	if (ft_strlen(argv[1]) < 10 || fd < 0 || fd > 1024) 
		return (data->error->error_g |= ERROR_FILE, 1);
	close (fd);
	if (is_cub(argv))
		return (data->error->error_g |= ERROR_CUB, 1);
	return (0);
}

bool	parsing(int argc, char **argv, t_data *data)
{
	if (check_args(argc, argv, data))
		return (parsing_msg_error(data->error), 1);
	if (get_data_scene(argv[1], data))
		return (parsing_msg_error(data->error), 1);
	if (get_map(data))
		return (parsing_msg_error(data->error), 1);
	if (remove_map_from_scene(data))
		return (parsing_msg_error(data->error), 1);
	if (sort_scene(data))
		return (parsing_msg_error(data->error), 1);
	if (parse_scene(data) || parse_map(data))
	 	return (parsing_msg_error(data->error), 1);
	return (0);
}