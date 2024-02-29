/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:53:22 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/29 03:52:34 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_cub(char *argv)
{
	uint16_t	len;

	len = ft_strlen(argv[1]);
	if (argv[0] != 'm' || argv[1] != 'a' || argv[2] != 'p'
		|| argv[3] != 's' || argv[4] != '/')
		return (false);
	if (argv[len - 4] != '.' || argv[len - 3] != 'c' ||
		argv[len - 2] != 'u' || argv[len - 1] != 'b')
		return (false);
	return (true);
}

bool	check_args(int argc, char **argv, t_data *data)
{	
	int	fd;

	if (argc != 2)
		data->error->error_g |= ERROR_ARG;
	if (argv[1])
	{
		if (!is_cub(argv[1]))
			data->error->error_g |= ERROR_CUB;
		fd = open(argv[1], O_RDONLY);
		if (ft_strlen(argv[1]) < 10 || fd < 0 || fd > 1024) //to recheck for ./map
			data->error->error_g |= ERROR_FILE;
		close (fd);
	}
	if (data->error->error_g)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	parsing(int argc, char **argv, t_data *data)
{
	if (check_args(argc, argv, data))
		return (EXIT_FAILURE);
	if (get_data_scene(argv[1], data))
		return (EXIT_FAILURE);
	if (get_map(data))
		return (EXIT_FAILURE);
	if (remove_map_from_scene(data))
		return (EXIT_FAILURE);
	if (sort_scene(data))
		return (EXIT_FAILURE);
	if (parse_scene(data) || parse_map(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
