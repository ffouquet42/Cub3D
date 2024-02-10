/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:53:22 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/10 14:16:13 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_args(int argc, char **argv)
{
	int	i;
	
	i = 0;
	if (argc != 2)
		return (1);
	if (ft_strlen(argv[1]) < 5)
		return (1);
	while (argv[1][i])
		i++;
	i -= 4;
	if (argv[1][i] != '.' || argv[1][i + 1] != 'c' ||
		argv[1][i + 2] != 'u' || argv[1][i + 3] != 'b')
		return (1);
	return (0);
}

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
	printf("* map_height = %i\n", data->map_height); // dev
	printf("* map_width  = %i\n", data->map_width); // dev

	data->scene = remove_map_from_scene(data);
	if (!data->scene)
		return (ft_putstr(E_RM_MAP, 2), 1);
	print_scene(data->scene); // dev
	
	data->scene = sort_scene(data);
	if (!data->scene)
		return (ft_putstr(E_SORT_SCE, 2), 1);
	print_scene(data->scene); // dev
	
	if (parse_scene(data) || parse_map(data))
		return (1);
	print_rgb(data);

	// check path img and init img ?
	
	return (0);
}