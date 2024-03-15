/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:01:37 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/15 13:47:46 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	inline	void	sort_infos(t_scene *scene)
{
	uint8_t i; 
	 
	while (scene->infos->sort_index < INFOS_LEN)
	{
		i = scene->infos->sort_index;	
		if (scene->scene[i][0] == 'N' && scene->scene[i][1] == 'O')
			ft_swap(scene, 0);
		else if (scene->scene[i][0] == 'S' && scene->scene[i][1] == 'O')
			ft_swap(scene, 1);
		else if (scene->scene[i][0] == 'W' && scene->scene[i][1] == 'E')
			ft_swap(scene, 2);
		else if (scene->scene[i][0] == 'E' && scene->scene[i][1] == 'A')
			ft_swap(scene, 3);
		else if (scene->scene[i][0] == 'F')
			ft_swap(scene, 4);
		else if (scene->scene[i][0] == 'C')
			ft_swap(scene, 5);
		scene->infos->sort_index++;
	}
}

static	inline void	clean_infos(t_scene *scene)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < INFOS_LEN)
	{
		j = 0;
		k = 0;
		tmp = scene->scene[i];
		while (tmp[j]) 
		{
			if (tmp[j] != ' ' && tmp[j] != '\t')
				scene->scene[i][k++] = tmp[j++];
			else
				j++;
		}
		scene->scene[i][k] = '\0';
		i++;
	}
}

bool	get_infos(t_scene *scene)
{
	clean_infos(scene);
	sort_infos(scene);
	return (EXIT_SUCCESS);
}
