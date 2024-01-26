/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:45:45 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/26 10:04:18 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	init_mlx(t_data *data)
{
	data->mlx = NULL; // tmp
	if (!data->mlx)
	{
		printf("call exit_1(data)\n"); // dev
		exit_1(data);
		exit(1);
	}
	return (0);
}