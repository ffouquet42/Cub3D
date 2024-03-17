/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:44:14 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/17 17:33:25 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

bool	parse_arg(int argc, char **argv, t_data *data)
{	
	int	fd;
	uint16_t	len;

	if (argc != 2)
		data->error->error_g |= ERROR_ARG;
	if (argv[1])
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < FD_MIN || fd > FD_MAX) 
			data->error->error_g |= ERROR_FILE;
		else 
			close(fd);
		len = ft_strlen(argv);
		if (!(argv[1][len - 4] == '.' && argv[1][len - 3] == 'c' &&
		argv[1][len - 2] == 'u' && argv[1][len - 1] == 'b'))
			data->error->error_g |= ERROR_CUB;
	}
	return (data->error->error_g);
}