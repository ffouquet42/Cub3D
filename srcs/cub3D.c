/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/31 12:43:21 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (init_data(&data))
		return (ft_putstr(E_INIT_DATA, 2), 1);
	if (parsing(argc, argv, &data))
		return (1); // + free all
	//
	return (0);
}

/*
ajouter textures
finir les structs
finir les frees pour les structs
parsing
free mlx
strchr utiliser ?
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
		printf("map[%i] = %s", i, map[i]);
		i++;
	}
	printf("map[%i] = %s\n", i, map[i]);
}