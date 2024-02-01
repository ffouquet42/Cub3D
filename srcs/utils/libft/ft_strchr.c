/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:58:08 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/01 08:12:37 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

char	*ft_strchr(const char *s, int c) // used?
{
	const char	*ptr;

	ptr = s;
	while ((unsigned char)*ptr != '\0'
		&& (unsigned char)*ptr != (unsigned char)c)
		ptr++;
	if ((unsigned char)*ptr == (unsigned char)c)
		return ((char *)ptr);
	return (0);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int		i;
// 	char	ch;

// 	i = 0;
// 	ch = c;
// 	while (s[i] != ch)
// 	{
// 		if (s[i] == '\0')
// 			return (NULL);
// 		i++;
// 	}
// 	return ((char *)s + i);
// }