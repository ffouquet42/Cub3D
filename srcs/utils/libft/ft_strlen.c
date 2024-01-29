/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:28:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/29 08:29:10 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;
	
	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}