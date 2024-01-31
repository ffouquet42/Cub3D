/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:53:22 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/31 11:57:21 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	parsing(int argc, char **argv, t_data *data)
{
	if (check_args(argc, argv))
		return (ft_putstr(E_PARS_ARGS, 2), 1);
	data->scene = get_scene(argv[1]);
	if (!data->scene)
		return (ft_putstr(E_GET_SCENE, 2), 1);
	print_scene(data->scene); // dev
	
	data->map = get_map(data->scene);
	if (!data->map)
		return (ft_putstr(E_GET_MAP, 2), 1);
	print_map(data->map); // dev
	
	return (0);
}