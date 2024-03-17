/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:15:46 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/17 18:01:26 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

inline void get_player_pos(t_scene *scene, int x, int y)
{
	if (is_char_in_set(scene->scene[y][x], "NSEW"))
	{
		scene->map->nb_s_pos++;
		scene->map->p_pos_x = (double)x + 0.5;
		scene->map->p_pos_y = (double)y + 0.5; // 0.5 dans t_game
	}
}

inline bool	is_void_around(t_scene *scene, int x, int y, char *charset) 
{
	return (!is_char_in_set(scene->scene[y - 1][x], charset) 
		|| !is_char_in_set(scene->scene[y + 1][x], charset)
		|| !is_char_in_set(scene->scene[y][x - 1], charset)
		|| !is_char_in_set(scene->scene[y][x + 1], charset));
}

inline bool	is_char_in_set(char c, char *set)
{
	int	i; //uint 

	i = -1;
	while (set[++i])
	{
		if (c == set[i])
			return (true);
	}
	return (false);
}