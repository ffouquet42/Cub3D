/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:53:22 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/13 18:18:14 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	is_cub(char **argv)
{
	uint16_t len;

	len = ft_strlen(argv[1]);
	if (!argv[1][len - 5] || argv[1][len - 4] != '.' || argv[1][len -  3] != 'c' ||
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
	if (fd < 0 || fd > 1024) 
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
	if (get_scene(argv[1], data))
		return (parsing_msg_error(data->error), 1);
	// print_scene(data->scene);
	// if (!data->scene)
	// 	return (ft_putstr(E_GET_SCENE, 2), 1); // a mettre dans get_scene

	// //même chose que pour get_scene
	// data->map = get_map(data->scene, data);
	// if (!data->map)
	// 	return (ft_putstr(E_GET_MAP, 2), 1);

	// data->scene = remove_map_from_scene(data);
	// if (!data->scene)
	// 	return (ft_putstr(E_RM_MAP, 2), 1);
	
	// data->scene = sort_scene(data);
	// if (!data->scene)
	// 	return (ft_putstr(E_SORT_SCE, 2), 1);
	
	// if (parse_scene(data) || parse_map(data))
	// 	return (1);

	// check path img and init img ?
	
	return (0);
}