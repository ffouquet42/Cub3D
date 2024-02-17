/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:52:26 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/17 22:30:55 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	print_scene(char **scene)  
{
	int i;
	i = 0;
	while (scene[i])
	{
		printf("scene[%i] = [%s]", i, scene[i]);
		i++;
	}
	printf("\nscene[%i] = [%s]\n", i, scene[i]);
}

void	print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		printf("map[%i] = [%s]", i, map[i]);
		i++;
	}
	printf("\nmap[%i] = [%s]\n", i, map[i]);
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
	// fct init strcut ?
	t_error	error;
	t_data	data;

	error = (t_error){0};
	data = (t_data){0};
	data.error = &error;
	
	if (parsing(argc, argv, &data))
		return (free_map_scene(&data), 1);
	if (init_data(&data))
	{
		printf("Error Thread");
		free_map_scene(&data);
		free_mlx(&data);
	 	return(parsing_msg_error(data.error), 1);
	}
	// if (init_game(&data))
	// {
	// 	free_map_scene(&data);
	// 	//free_mlx(&data);
	//  	return(parsing_msg_error(data.error), 1);
	// }

	if ()
	printf("Main Thread");
	// free_mlx(&data);
	return (free_map_scene(&data), 0);
}
