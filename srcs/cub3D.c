/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/07 13:05:40 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (init_data(&data))
		return (ft_putstr(E_INIT_DATA, 2), 1);
	if (parsing(argc, argv, &data))
		return (1); // + free all (end of prog)
	if (init_game(&data))
		return (1); // + free ...
	return (0);
}

/*
finir les structs
finir les frees pour les structs
parsing
free mlx
strchr utiliser ?
trouver textures
*/

// dev
void	print_scene(char **scene)
{
	int i = 0;
	while (scene[i])
	{
		printf("scene[%i] = %s", i, scene[i]);
		i++;
	}
	printf("\nscene[%i] = %s\n", i, scene[i]);
}

void	print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		printf("map[%i] = [%s]\n", i, map[i]);
		i++;
	}
	printf("map[%i] = [%s]\n", i, map[i]);
}

void	print_rgb(t_data *data)
{
	printf("floor[0] = %i\n", data->rgb_floor[0]);
	printf("floor[1] = %i\n", data->rgb_floor[1]);
	printf("floor[2] = %i\n", data->rgb_floor[2]);

	printf("ceiling[0] = %i\n", data->rgb_ceiling[0]);
	printf("ceiling[1] = %i\n", data->rgb_ceiling[1]);
	printf("ceiling[2] = %i\n", data->rgb_ceiling[2]);
}
// dev