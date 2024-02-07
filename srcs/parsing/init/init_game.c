/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:57:27 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/07 13:50:04 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	init_game(t_data *data)
{
	if (init_images(data))
		return (ft_putstr(E_INIT_IMG, 2), 1);
	data->win = mlx_new_window(data->mlx, data->window_x,
		data->window_y, "Cub3D");
	if (!data->win)
	{
		// mlx_do_key_autorepeaton(data->mlx); //
		// free / exit
		return (ft_putstr(E_MLX_WIN, 2), 1);
	}
	// player pos
	return (0);
}