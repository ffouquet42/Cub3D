/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:17:50 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/16 15:54:43 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <stdint.h>

/*Struct errors*/

typedef struct s_error
{
	uint32_t	error_g;
}				t_error;

# define COLOR_RESET   "\x1b[0m"
# define COLOR_RED     "\x1b[31m"

// General error for msg_error here..

# define ERROR_ARG				(uint8_t)0x1
# define ERROR_FILE				(uint8_t)0x2 
# define ERROR_CUB				(uint8_t)0x4

# define ERROR_EMPTY_S			(uint8_t)0x8
# define ERROR_EMPTY_LINE		(uint8_t)0x10
# define ERROR_SCENE			(uint8_t)0X20


# define ERROR_MAP				(uint8_t)0X40
# define ERROR_RM_MAP			(uint8_t)0x80
# define ERROR_SORT_S			(uint16_t)0x100
# define ERROR_CHAR				(uint16_t)0x200
# define ERROR_START			(uint16_t)0x400
# define ERROR_WALL				(uint16_t)0x800
# define ERROR_XPM				(uint16_t)0x1000
# define ERROR_RGB				(uint16_t)0x2000
# define ERROR_INIT_MLX			(uint16_t)0x4000
# define ERROR_INIT_IMG			(uint16_t)0x8000
# define ERROR_MLX_WIN			0x10000
# define ERROR_POS				0x20000
# define ERROR_MALLOC			0x40000

# define E_PARS_ARGS "Need a single argument, a .cub map.\n"
# define E_PARS_FILE "OPEN FAILURE. Need an existing file.\n"
# define E_PARS_CUB "Invalid file format. Need a .cub map.\n"
# define E_EMPTY_SCENE "Information is missing or the map is too small\n"
# define E_EMPTY_LINE "There are one or more empty lines on the map\n"
# define E_GET_SCENE "Get scene failed.\n"
# define E_GET_MAP "Get map failed.\n"
# define E_RM_MAP "Remove map from scene failed.\n"
# define E_SORT_SCE "Sort scene failed.\n"
# define E_MAP_CHAR "Invalid char for map.\n"
# define E_ONE_START "Need one start position.\n"
# define E_CLO_WALL "Map must be closed by walls.\n"
# define E_NO_XPM "Need .xpm files for textures.\n"
# define E_RGB "Invalid RGB values.\n"
# define E_INIT_MLX "Init mlx failed.\n"
# define E_INIT_IMG "Init images failed.\n"
# define E_MLX_WIN "mlx new window failed.\n"
# define E_GET_P_POS "Get player pos failed.\n"
# define E_INIT_DATA "Init data failed.\n"
# define E_MALLOC_FAIL "A malloc have failed.\n"

#endif