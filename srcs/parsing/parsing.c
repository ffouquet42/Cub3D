/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:53:22 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/14 09:23:02 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	parsing(int argc, char **argv, t_data *data)
{
	if (parse_arg(argc, argv, data))
		return (EXIT_FAILURE);
	if (parse_scene(argv, data))
		return (EXIT_FAILURE);
	// print_map(data->scene->scene, 1);
	if (parse_infos(data))
		return (EXIT_FAILURE);
	// print_map(data->scene->scene, 2);
	if (parse_map(data))
		return (EXIT_FAILURE);
	print_map(data->scene->scene, 3);
	return (EXIT_SUCCESS);
}
