/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:15:46 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/07 20:33:16 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

bool	is_char_in_set(char c, char *set) // rename
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (true);
		i++;
	}
	return (false);
}