/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:50:42 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/02 22:58:16 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	bool	resize_map(t_data *data)
{
	int		y;
	int		x;
	char	*dest;

	y = -1;
	while (data->map[++y])
	{
		x = 0;
		dest = malloc(sizeof(char ) * (data->map_width + 1));
		if (!dest)
			return (1);
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
	}
	return (0);
}

static	void	get_map_size(t_data *data) // dim
{
	int	x;
	int	y;
	int	z;

	y = 0;
	z = 0;
	while (data->map[y])
	{
		x = ft_strlen(data->map[y]);
		if (x > z)
			z = x;
		y++;
	}
	data->map_height = data->scene_height - INFOS_LEN;
	data->map_width = z - 1;
}

bool	get_map(t_data *data)
{
	int		i;
	int		y;

	y = 0;
	i = INFOS_LEN;

	// get_map fct 
	data->map = malloc(sizeof(char *) * (data->scene_height - 5)); //-INFOS_LEN + 1
	if (!data->map)
		return (data->error->error_g |= ERROR_MALLOC, EXIT_FAILURE);
	while (data->scene[i])
		data->map[y++] = data->scene[i++];
	data->map[y] = NULL;
	get_map_size(data);
	if (resize_map(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
