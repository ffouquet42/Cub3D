/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:17:06 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/09 18:06:38 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


void exit_1(t_data *data)
{
	ft_putstr(E_INIT_MLX, 2);
	free_data_1(data);
	exit (1);
}

// Je fait refaire entierement tout les free une fois que le parsing est nickel
void	free_data_1(t_data *data)
{
	free(data->raycast);
	free(data->game);
}

