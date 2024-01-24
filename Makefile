SRCS		=	

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

NAME		=	prog
#NAME		=	Cub3D

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re