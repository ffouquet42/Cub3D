/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:44:14 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/11 20:07:55 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static	inline	bool	is_cub(char *argv) 
{
	uint16_t	len;

	len = ft_strlen(argv);
	return (argv[len - 4] == '.' && argv[len - 3] == 'c' &&
		argv[len - 2] == 'u' && argv[len - 1] == 'b');
}

bool	parse_arg(int argc, char **argv, t_data *data)
{	
	int	fd;

	if (argc != 2)
		data->error->error_g |= ERROR_ARG;
	if (argv[1])
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < FD_MIN || fd > FD_MAX) 
			data->error->error_g |= ERROR_FILE;
		else 
			close(fd);
		if (!is_cub(argv[1]))
			data->error->error_g |= ERROR_CUB;
	}
	if (data->error->error_g)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}