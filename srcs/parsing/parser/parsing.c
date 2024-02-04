/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:53:22 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/04 16:48:21 by fllanet          ###   ########.fr       */
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
	
	data->map = get_map(data->scene, data);
	if (!data->map)
		return (ft_putstr(E_GET_MAP, 2), 1);
	printf("----------\n"); // dev
	print_map(data->map); // dev
	printf("----------\n"); // dev
	printf("* map_h = %i\n", data->map_height); // dev
	printf("* map_w = %i\n", data->map_width); // dev

	data->scene = remove_map_from_scene(data);
	if (!data->scene)
		return (ft_putstr(E_RM_MAP, 2), 1);
	print_scene(data->scene); // dev
	
	data->scene = sort_scene(data);
	if (!data->scene)
		return (ft_putstr(E_SORT_SCE, 2), 1);
	print_scene(data->scene); // dev
	
	if (parse_scene(data) || parse_map(data)) // <=
		return (1); // ^^^ msg erreurs dans parse_...
	print_rgb(data);

	// check path img and init img ?
	
	return (0);
}