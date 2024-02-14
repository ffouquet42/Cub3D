/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:17:50 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/14 08:26:00 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <stdint.h>

typedef struct s_error
{
	uint16_t	error_g;
}				t_error;

# define COLOR_RESET   "\x1b[0m"
# define COLOR_RED     "\x1b[31m"


# define ERROR_ARG				0x1
# define ERROR_FILE				0x2
# define ERROR_CUB				0x4
# define ERROR_EMPTY			0x8
# define ERROR_SCENE			0X10
# define ERROR_MAP				0X20
# define ERROR_RM_MAP			0x40
# define ERROR_SORT_S			0x80
# define ERROR_CHAR				0x100
# define ERROR_START			0x200
# define ERROR_WALL				0x400


# define ERROR_EXIT				0x800
# define ERROR_COL				0x1000
# define ERROR_CHAR				0x2000
# define ERROR_NO_VALID_PATH	0x4000

# define ERROR_MALLOC			0x8000



# define E_PARS_ARGS COLOR_RED "Error\nNeed a single argument, a .cub map.\n" COLOR_RESET
# define E_PARS_FILE COLOR_RED "Error\nOPEN FAILURE. Need an existing file. \n" COLOR_RESET
# define E_PARS_CUB COLOR_RED "Error\nInvalid file format. Need a .cub map. \n" COLOR_RESET
# define E_EMPTY_MAP COLOR_RED "Error\nInformation is missing or the map is too small\n" COLOR_RESET
# define E_GET_SCENE COLOR_RED "Error\nGet scene failed.\n" COLOR_RESET
# define E_GET_MAP COLOR_RED "Error\nGet map failed.\n" COLOR_RESET
# define E_RM_MAP COLOR_RED "Error\nRemove map from scene failed.\n" COLOR_RESET
# define E_SORT_SCE COLOR_RED "Error\nSort scene failed.\n" COLOR_RESET
# define E_MAP_CHAR COLOR_RED "Error\nInvalid char for map.\n" COLOR_RESET
# define E_ONE_START COLOR_RED "Error\nNeed one start position.\n" COLOR_RESET
# define E_CLO_WALL COLOR_RED "Error\nMap must be closed by walls.\n" COLOR_RESET


# define E_INIT_DATA COLOR_RED "Error\nInit data failed.\n" COLOR_RESET
# define E_INIT_MLX COLOR_RED "Error\nInit mlx failed.\n" COLOR_RESET
# define E_NO_XPM COLOR_RED "Error\nNeed .xpm files for textures.\n" COLOR_RESET
# define E_RGB COLOR_RED "Error\nInvalid RGB values.\n" COLOR_RESET
# define E_INIT_IMG COLOR_RED "Error\nInit images failed.\n" COLOR_RESET
# define E_MLX_WIN COLOR_RED "Error\nmlx new window failed.\n" COLOR_RESET
# define E_GET_P_POS COLOR_RED "Error\nGet player pos failed.\n" COLOR_RESET

# define E_MALLOC_FAIL COLOR_RED "Error\nA malloc have failed.\n" COLOR_RESET

#endif