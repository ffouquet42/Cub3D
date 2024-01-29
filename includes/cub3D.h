/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:39:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/29 08:29:56 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//**********************************************//
//					INCLUDES					//
//**********************************************//

# include "errors.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


//**********************************************//
//					DEFINES						//
//**********************************************//


//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_raycast
{
	// double	camera;
	// double	diray_x;
	// double	diray_y;
	// int		map_x;
	// int		map_y;
	// double	side_dist_x;
	// double	side_dist_y;
	// double	delta_dist_x;
	// double	delta_dist_y;
	// double	ray_length;
	// int		step_x;
	// int		step_y;
	// int		hit;
	// int		side;
	// int		line_height;
	// double	wall_x;
	// int		tex_x;
	// double	step;
	// double	tex_pos;
	// int		draw_start;
	// int		draw_end;
}			t_raycast;

typedef struct s_game
{
	// double	p_pos_x;
	// double	p_pos_y;
	// double	p_ori_x;
	// double	p_ori_y;
	// double	plane_x;
	// double	plane_y;
	// double	cur_time;
	// double	old_time;
	// int		key_w;
	// int		key_s;
	// int		key_a;
	// int		key_d;
	// int		key_right;
	// int		key_left;
	// int		texture;
}			t_game;

typedef struct s_image
{
	// void	*mlx_img;
	// char	*addr;
	// int		bpp;
	// int		rowlen;
	// int		end;
	// int		tex_width;
	// int		tex_height;
}			t_image;

typedef struct s_textures // sprite / texture
{
	// t_img	*no;
	// t_img	*so;
	// t_img	*we;
	// t_img	*ea;
}			t_textures;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			window_x;
	int			window_y;
	t_game		*game;
	t_raycast	*raycast;
	
	// t_img		*mini_img;
	// t_img		textures[4];
	// t_img		*img;
	// char		**desc;
	// int			floor[4];
	// int			ceiling[4];
	// char		**map;
	// int			map_height;
	// int			mouse_x;
	// int			fc;
	// double		rotation_speed;
	// int			mouse_active;
	// int			run;
	// double		movespeed;
}			t_data;


//**********************************************//
//					PROTOTYPES					//
//**********************************************//

//---------------   cub3D.c   ------------------//
int		main(int argc, char **argv);


//**********************************************//
//					PARSING						//
//**********************************************//

//**********************************************//
//					CHECK						//
//**********************************************//

//---------------   args.c   -------------------//
int		check_args(int argc, char **argv);

//**********************************************//
//					INIT						//
//**********************************************//

//---------------   init_data.c   --------------//
int		init_data(t_data *data);
void	init_data_2(t_data *data);

//---------------   init_mlx.c   ---------------//
int		init_mlx(t_data *data);

//**********************************************//
//					PARSER						//
//**********************************************//

//---------------   parsing.c   ----------------//
int		parsing(int argc, char **argv, t_data *data);


//**********************************************//
//					UTILS						//
//**********************************************//

//---------------   exit.c   -------------------//
void 	exit_1(t_data *data);

//---------------   free.c   -------------------//
void	free_data_1(t_data *data);


//**********************************************//
//					LIBFT						//
//**********************************************//

//---------------   ft_putstr.c   --------------//
void	ft_putstr(char *str, int fd);

//---------------   ft_strlen.c   --------------//
size_t	ft_strlen(const char *str);

//**********************************************//
//					EXEC						//
//**********************************************//


#endif