INC_DIR		= .
MANDA_DIR	= .

MANDA_NAMES	=	atoi.c bzero.c calloc.c isalnum.c isalpha.c isascii.c \
				isdigit.c isprint.c itoa.c memccpy.c memchr.c memcmp.c memcpy.c \
				memmove.c memset.c putchar_fd.c putnbr_fd.c putendl_fd.c putstr_fd.c split.c strchr.c strdup.c strjoin.c \
				strlcat.c strlcpy.c strlen.c strmapi.c strncmp.c strnstr.c strrchr.c \
				strtrim.c strtrim.c substr.c tolower.c toupper.c 
				
MANDA_SRCS	= $(addprefix $(MANDA_DIR)/ft_, $(MANDA_NAMES))

BONUS_NAMES	=	 lstnew.c lstadd_front.c lstsize.c lstlast.c lstadd_back.c \
				lstdelone.c lstclear.c lstiter.c lstmap.c

BONUS_SRCS	= $(addprefix $(MANDA_DIR)/ft_, $(BONUS_NAMES))

MANDA_OBJS	= $(MANDA_SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rc

RM			= rm -f

RL			= ranlib

.c.o:
			$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(MANDA_OBJS)
			$(AR) $(NAME) $(MANDA_OBJS)
			$(RL) $(NAME)

all:		$(NAME)

bonus:		$(MANDA_OBJS) $(BONUS_OBJS)
			$(AR) $(NAME) $(MANDA_OBJS) $(BONUS_OBJS)
			$(RL) $(NAME)

clean:
			$(RM) $(MANDA_OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re