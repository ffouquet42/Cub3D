CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g3 -I ./include -I./mlx_linux # -g -MMD
MLX			=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME		=	cub3D

SRCS		=	srcs/main.c								\
				srcs/parsing/parsing.c					\
				srcs/parsing/arg/parse_arg.c			\
				srcs/parsing/scene/scene.c				\
				srcs/parsing/infos/infos.c				\
				srcs/parsing/infos/parse_infos.c		\
				srcs/parsing/infos/image.c				\
				srcs/parsing/infos/rgb.c				\
				srcs/parsing/map/parse_map.c			\
				srcs/parsing/map/wall.c					\
				srcs/exec/game_management.c				\
				srcs/exec/move/move.c					\
				srcs/exec/move/rotate.c					\
				srcs/utils/parsing_utils/libft.c		\
				srcs/utils/parsing_utils/lib_memory.c	\
				srcs/utils/parsing_utils/get_next_line.c\
				srcs/utils/parsing_utils/print.c		\
				srcs/utils/parsing_utils/scene_utils.c	\
				srcs/utils/parsing_utils/infos_utils.c	\
				srcs/utils/parsing_utils/map_utils.c	\
				srcs/utils/free.c						\

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C ./mlx_linux
			$(CC) -o $(NAME) $(SRCS) $(CFLAGS) $(MLX)

clean:
			$(RM) $(OBJS)

fclean:		clean
			make  clean -C ./mlx_linux
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re