/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:39:37 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/18 00:18:42 by mfeldman         ###   ########.fr       */
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
# include <math.h>
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
#include <limits.h>

//**********************************************//
//					DEFINES						//
//**********************************************//

/*GNL BUFFER*/
# define BUFFER_SIZE 100

/*KEYCODE*/
# define KEY_W 119
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_M 109
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_SHIFT	65505
# define KEY_ESC	65307

/*WINDOWS SIZE*/

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

/*SPEED*/
# define MOVESPEED 0.05
# define ROTSPEED 0.02

//**********************************************//
//					STRUCTURES					//
//**********************************************//

typedef struct s_raycast
{
	double	camera;
	double	diray_x;
	double	diray_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	ray_length;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		draw_start;
	int		draw_end;
}			t_raycast;

typedef struct s_game
{
	double	player_pos_x;
	double	player_pos_y;
	double	player_or_x;
	double	player_or_y;
	double	plane_x; //
	double	plane_y; //
	
	// double	cur_time;
	// double	old_time;
	int		key_w; // uint8_t
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_right;
	int		key_left;
	int		texture;
}			t_game;

typedef struct s_image
{
	void	*mlx_img;	
	char	*add;		
	int		bpp;		
	int		rowlen;		
	int		end;
	int		img_height;
	int		img_width;
}			t_image;

typedef struct s_texture
{
	// t_image	*no; // rename
	// t_image	*so; // rename
	// t_image	*we; // rename//---------------   cub3D.c   ------------------//
	// t_image	*ea; // rename
}			t_texture;

typedef struct s_data
{
	
	t_error		*error;
	
	void		*mlx;
	void		*win;
	t_game		*game;
	t_raycast	*ray;
	t_image		images[4];
	char		**scene;
	char		**f_scene;
	char		**f2_scene;
	char		**map;
	int			map_height;
	int			map_width;
	int			scene_height;
	int			rgb_floor[3];
	int			rgb_ceiling[3];
	bool		run;
	bool		mouse;
	int			mouse_x;
	double		speed;
	double		rotation_speed;
	t_image		*img;
}			t_data;


//**********************************************//
//					PROTOTYPES					//
//**********************************************//

//---------------   cub3D.c   ------------------//

int		main(int argc, char **argv);

//*****************wrap_mlx_init*****************************//
//					PARSING						//
//**********************************************//

//**********************************************//
//					INIT						//
//**********************************************//

//---------------   init_data.c   --------------//
bool	init_data(t_data *data);

//---------------   init_game.c   --------------//
bool	init_game(t_data *data);
void	get_player_pos(t_data *data);
void	get_first_orientation(t_data *data, char c);
void	get_first_orientation_two(t_data *data, char c);

//---------------   init_images.c   ------------//
bool	init_images(t_data *data);
bool	init_image(t_data *data, int i);
void	clean_nl_scene(t_data *data);

//**********************************************//
//					PARSER						//
//**********************************************//

//---------------   map.c   --------------------//
bool	get_map(t_data *data);
void	get_map_size(t_data *data);
void	resize_map(t_data *data);

//---------------   parse_map.c   --------------//
bool	parse_map(t_data *data);
bool	check_map_char(t_data *data);
bool	is_map_char(char c, char *set);
bool	one_start_pos(t_data *data);
bool	char_is_in_set(char c, char *set);

//---------------   parse_scene.c   ------------//
bool	parse_scene(t_data *data);
bool	path_is_xpm(char *path);
bool	check_rgb(char *rgb, t_data *data, int fc);

//---------------   parsing.c   ----------------//
bool	parsing(int argc, char **argv, t_data *data);
bool	check_args(int argc, char **argv, t_data *data);
bool	is_cub(char **argv);

//---------------   rgb.c   --------------------//
bool	count_comma(char *str);
bool	rgb_format(char *str);
bool	rgb_value(char *str, t_data *data, int fc);
bool	correct_rgb_value(t_data *data);

//---------------   scene.c   ------------------//
bool	get_data_scene(char *scene_path, t_data *data);
int		scene_len(char *scene_path, t_data *data);
bool	get_scene(int fd, t_data *data);
void	clean_scene(t_data *data);
bool	remove_map_from_scene(t_data *data);

//---------------   sort_scene.c   -------------//
bool	sort_scene(t_data *data);
char 	**sort_scene_2(t_data *data);
//---------------   wall.c   -------------------//
bool	closed_by_wall(t_data *data);
bool	no_void_around(t_data *data, char *charset);
bool	test_around(char **map, int y, int x, char *charset);


//**********************************************//
//					UTILS						//
//**********************************************//

//---------------   digit.c   ------------------//
bool	only_digit_or_comma(char *str);
// bool	only_digit(char *str);
bool	is_digit(char c);

//---------------   free.c   -------------------//
void 	free_all(t_data *data);
void	free_mlx(t_data *data);
void	free_map(t_data *data); 
void	free_scene(t_data *data);
void	free_map_scene(t_data *data);

//---------------   get_next_line.c   ----------//
char	*get_next_line(int fd);
char	*merge_stash_and_buff(char *stash, char *buff);
char	*buff_to_stash(char *buff);
bool	search_newline(const char *buff);
char	*stash_to_line(char *stash, char *buf);

//---------------	print.c			 ----------//

void	parsing_msg_error(t_error *error);
void	ft_putstr(char *str, int fd);
void	print_map();

//---------------	libft.c			  ----------//

int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);

//---------------	scene_utils.c ----------//

bool	line_is_empty(char *str);

//---------------	draw_utils.c ----------//

void	ft_mlx_pixel_put(t_image *img, int x, int y, int color);


//**********************************************//
//					EXEC						//
//**********************************************//

//---------------	game_management.c ----------//

bool	game_management(t_data *data);
int 	key_press(int keycode, t_data *data);
int 	key_release(int keycode, t_data *data);
int 	game_loop(t_data *data);
void	move(t_data *data);

//---------------	move.c ----------//

void	move_right(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_up(t_data *data);

//---------------	rotate.c ----------//

void	rotate_left(t_data *data);
void	rotate_right(t_data *data);
void	get_rotate_speed(t_data *data);

//---------------	raycasting.c ----------//

void	raycast(t_data *data);
void	init_cast_img(t_data *data);
void	set_side_dist(t_data *data, t_raycast *ray);
void	set_camera(t_data *data, t_raycast *ray, int x);

//---------------	draw.c ----------//

void	draw_textures(t_data *data, t_raycast *ray, int x);
void	pick_texture(t_data *cub, t_raycast *ray);
void	set_textures_variables(t_data *data, t_raycast *ray, int x);
int		get_rgb(int *color);
int		get_color(t_data *data, int x, int y, int image);

int exit_all();

#endif