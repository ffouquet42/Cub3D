/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:35 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/15 14:54:58 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	inline	bool	are_chars_valid(t_scene *scene)
{
	int	y;
	int	x;

	y = INFOS_LEN - 1;
	while (scene->scene[++y])
	{
		x = -1;
		while (scene->scene[y][++x]) 
		{
			printf("char invalid map[%i][%i]\n", y,x);
			if (!is_char_in_set(scene->scene[y][x], "01NSEW \n"))
				return (false);
			if (x == 0 || x == scene->map->width - 1 || y == INFOS_LEN || y == scene->map->height - 1)
			{
				if (scene->scene[y][x] != '1' && scene->scene[y][x] != ' ' 
						&& scene->scene[y][x] != '\n')
					return (false);
			}
			if (is_char_in_set(scene->scene[y][x], "0NSEW"))
				if (is_void_around(scene, x, y, "01NSEW"))
					return (false);
			get_player_pos(scene, x, y);
		}
	}
	return (scene->map->pos == 1);
}

static	inline	void	get_size_map(t_scene *scene) // in get_player_pos
{
	int 	i;
	int 	len;
	
	i = INFOS_LEN;
	while (scene->scene[i++])
	{
		len = ft_strlen(scene->scene[i]);
		if (len > scene->map->width)
			scene->map->width = len - 1;
	}
	scene->map->height = scene->height - INFOS_LEN;
}

bool	parse_map(t_data *data)
{
	get_size_map(data->scene);
	if (!are_chars_valid(data->scene))
		return (data->error->error_g |= ERROR_CHAR, EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
