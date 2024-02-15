/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:50:42 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/15 14:23:19 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	resize_map(t_data *data)
{
	int		y;
	int		x;
	char	*dest;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		dest = ft_calloc(sizeof(char), data->map_width);
		// dest = malloc(sizeof(char ) * (data->map_width ));
		while (data->map[y][x] && data->map[y][x] != '\n')
		{
			dest[x] = data->map[y][x];
			x++;
		}
		while (x < data->map_width)
		{
			dest[x] = ' ';
			x++;
		}
		dest[x] = '\0';
		data->map[y] = dest;
		y++;
	}
}

void	get_map_size(char **map, t_data *data) // map pas droite? plusieurs longueurs?
{
	int	x;
	int	y;
	int	z;

	y = 0;
	z = 0;
	while (map[y])
	{
		x = ft_strlen(map[y]);
		if (x > z)
			z = x;
		y++;
	}
	data->map_height = data->scene_height - 6;
	data->map_width = z - 1; // test voir si -1
}

bool	get_map(t_data *data)
{
	char	**map;
	int		i;
	int		y;

	y = 0;
	map = malloc(sizeof(char *) * (data->scene_height - 5)); 
	if (!map)
		return (data->error->error_g |= ERROR_MALLOC, 1);
	i = 6;
	printf("%d", data->scene_height);
	while (y < data->scene_height)
		map[y++] = data->scene[i++];
	map[y] = NULL;
	print_map(map);
	get_map_size(map, data);
	resize_map(data);
	if (!data->map) 
		return (data->error->error_g |= ERROR_MAP, 1);
	// print_map(data->scene);
	return(0);
}