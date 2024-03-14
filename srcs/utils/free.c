/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:17:06 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/14 07:20:03 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	quit_loop(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (EXIT_SUCCESS);
}

static	inline	void	free_tab(char **tab) 
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

// static	void	free_mlx(t_data *data)
// {
// 	uint8_t	i;

// 	i = 0;
// 	if (data->win)
// 		mlx_destroy_window(data->mlx, data->win);
// 	while (i < 4)
// 	{
// 		if (data->images[i].mlx_img)
// 			mlx_destroy_image(data->mlx, data->images[i].mlx_img);
// 		i++;
// 	}
// 	if (data->mlx)
// 		mlx_destroy_display(data->mlx);
// 	if (data->mlx)
// 		free(data->mlx);
// }

inline	void	free_all(t_data *data)
{
	if (data->scene->scene)
		free_tab(data->scene->scene);
	// free_mlx(data);
	exit(EXIT_SUCCESS);
}
