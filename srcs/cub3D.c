/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/09 14:20:10 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// Y'a full leaks j'ai pas encore fait les frees ect


// dev (fonctions pour visualiser les structs dans le terminal pendant le dev, a supprimer avant de rendre le projet)
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

void	print_img(t_data *data)
{
	int i = 0;

	while (i < 4)
	{
		printf("img[%i].addr         = %s\n", i, data->images[i].addr);
		printf("img[%i].bpp          = %i\n", i, data->images[i].bpp);
		printf("img[%i].rowlen       = %i\n", i, data->images[i].rowlen);
		printf("img[%i].end          = %i\n", i, data->images[i].end);
		printf("img[%i].image_height = %i\n", i, data->images[i].img_height);
		printf("img[%i].image_width  = %i\n", i, data->images[i].img_width);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data data;

	// PARSING - FLO
	if (init_data(&data))
		return (ft_putstr(E_INIT_DATA, 2), 1);
	if (parsing(argc, argv, &data))
		return (1); // + free all (end of prog)
	if (init_game(&data))
		return (1); // + free ...
		
	// EXEC - MICKA
	
	return (0);
}
// dev