/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:15:46 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/11 19:04:18 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

inline bool	is_char_in_set(char c, char *set) // rename
{
	int	i; //uint 

	i = 0;
	while (set[i])
	{
		if (c == set[i++])
			return (true);
	}
	return (false);
}