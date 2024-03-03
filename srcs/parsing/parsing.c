/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:53:22 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/03 01:16:26 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static	bool	is_cub(char *argv) 
{
	uint16_t	len;

	len = ft_strlen(argv);
	return (argv[len - 4] == '.' && argv[len - 3] == 'c' &&
		argv[len - 2] == 'u' && argv[len - 1] == 'b');
}

static	bool	is_valid_arg(int argc, char **argv, t_data *data)
{	
	int	fd;

	if (argc != 2)
		data->error->error_g |= ERROR_ARG;
	if (argv[1])
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < FD_MIN || fd > FD_MAX) 
			data->error->error_g |= ERROR_FILE;
		if (!is_cub(argv[1]))
			data->error->error_g |= ERROR_CUB;
		close (fd);
	}
	if (data->error->error_g)
		return (false);
	return (true);
}

bool	parsing(int argc, char **argv, t_data *data)
{
	if (!is_valid_arg(argc, argv, data))
		return (EXIT_FAILURE);
	if (parse_scene(argv, data))
		return (EXIT_FAILURE);
	if (get_infos(data) || parse_infos(data))
		return (EXIT_FAILURE);
	// if (get_map(data) || parse_map(data))
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
