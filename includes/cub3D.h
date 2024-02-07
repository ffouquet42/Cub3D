/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:39:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/07 13:37:26 by fllanet          ###   ########.fr       */
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
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>


//**********************************************//
//					DEFINES						//
//**********************************************//

# define BUFFER_SIZE 100


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
	void	*mlx_img;	// rename
	char	*addr;		// rename
	int		bpp;		// rename
	int		rowlen;		// rename
	int		end;		// rename
	int		img_height;
	int		img_width;
}			t_image;

typedef struct s_texture
{
	// t_image	*no; // rename
	// t_image	*so; // rename
	// t_image	*we; // rename
	// t_image	*ea; // rename
}			t_texture;

typedef struct s_e_scene
{
	int		no;
	int		so;
	int		ea;
	int		we;
	int		f;
	int		c;
}			t_e_scene;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			window_x;
	int			window_y;
	t_game		*game;
	t_raycast	*raycast;
	char		**scene;
	char		**map;
	int			map_height;
	int			map_width;
	t_e_scene	*e_scene;
	int			rgb_floor[3];
	int			rgb_ceiling[3];
	t_image		images[4];
	
	// t_img		*mini_img;
	// t_img		*img;
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

//---------------   init_game.c   --------------//
int		init_game(t_data *data);

//---------------   init_images.c   ------------//
int		init_images(t_data *data);
int		init_image(t_data *data, int i);

//---------------   init_mlx.c   ---------------//
int		init_mlx(t_data *data);

//**********************************************//
//					PARSER						//
//**********************************************//

//---------------   map.c   --------------------//
char	**get_map(char **scene, t_data *data);
void	get_map_size(char **map, t_data *data);
char	**resize_map(char **map, t_data *data);

//---------------   parse_map.c   --------------//
int		parse_map(t_data *data);
int		check_map_char(t_data *data);
int		is_map_char(char c, char *set);
int		one_start_pos(t_data *data);
int		char_is_in_set(char c, char *set);

//---------------   parse_scene.c   ------------//
int		parse_scene(t_data *data);
int		path_is_xpm(char *path);
int		check_rgb(char *rgb, t_data *data, int fc);

//---------------   parsing.c   ----------------//
int		parsing(int argc, char **argv, t_data *data);

//---------------   rgb.c   --------------------//
int		count_comma(char *str);
int		rgb_format(char *str);
int		rgb_value(char *str, t_data *data, int fc);
int		save_rgb_value(char *str, t_data *data, int rgb, int fc);
int		correct_rgb_value(t_data *data);

//---------------   scene.c   ------------------//
char	**get_scene(char *scene_path);
int		scene_len(char *scene_path);
char	**clean_scene(char **scene);
char	**remove_map_from_scene(t_data *data);

//---------------   sort_scene.c   -------------//
char	**sort_scene(t_data *data);
int		all_identifiants(t_data *data);

//---------------   wall.c   -------------------//
int		closed_by_wall(t_data *data);
char	**copy_map(t_data *data);
int		fill_map(t_data *data, char **map, char *to_replace);
int		no_void_around(t_data *data, char **map);
int		test_around(char **map, int y, int x);


//**********************************************//
//					UTILS						//
//**********************************************//

//---------------   digit.c   ------------------//
int		only_digit_or_comma(char *str);
int		only_digit(char *str);
int		is_digit(char c);

//---------------   exit.c   -------------------//
void 	exit_1(t_data *data);

//---------------   free.c   -------------------//
void	free_data_1(t_data *data);

//---------------   get_next_line.c   ----------//
char	*get_next_line(int fd);
char	*merge_stash_and_buff(char *stash, char *buff);
char	*buff_to_stash(char *buff);
int		search_newline(const char *buff);
char	*stash_to_line(char *stash, char *buf);

//---------------   line.c   -------------------//
int		line_is_empty(char *str);

//**********************************************//
//					LIBFT						//
//**********************************************//

//---------------   ft_atoi.c   ----------------//
int		ft_atoi(const char *str);

//---------------   ft_calloc.c   --------------//
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

//---------------   ft_putstr.c   --------------//
void	ft_putstr(char *str, int fd);

//---------------   ft_strchr.c   --------------//
char	*ft_strchr(const char *s, int c);

//---------------   ft_strdup.c   --------------//
char	*ft_strdup(const char *s);

//---------------   ft_strlen.c   --------------//
size_t	ft_strlen(const char *str);

//**********************************************//
//					EXEC						//
//**********************************************//

// dev
void	print_scene(char **scene);
void	print_map(char **map);
void	print_rgb(t_data *data);

#endif