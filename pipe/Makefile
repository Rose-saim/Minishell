MANDA_NAMES = 	../libft/ft_split.c ../libft/ft_strlen.c ../libft/ft_strncmp.c\
				../libft/ft_calloc.c ../libft/ft_memset.c ../libft/ft_memcpy.c\
				exec_fd.c free_lst.c ft_init.c get_cmd.c main.c manage_fd.c utils.c 

MANDA_OBJS =	 $(MANDA_NAMES:.c=.o)

NAME = pipex

CC = clang
CFLAGS = -Wall -Wextra -Werror

AR = ar rc

RM = rm -f

RL = ranlib

$(NAME):	$(MANDA_OBJS)
			$(CC) $(CFLAGS) $(MANDA_OBJS) -o $(NAME)

all:		$(NAME)

clean:	
			$(RM) $(MANDA_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
