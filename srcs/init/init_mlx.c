/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:45:45 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/09 18:10:55 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_1(data); // je doit refaire les exits et free
	return (0);
}