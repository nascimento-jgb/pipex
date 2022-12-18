NAME		= pipex
INCLUDE		= includes
LIBFT		= libft
SRC_DIR		= src/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -I
RM			= rm -f

#Sources

SRC_FILES	=	pipex.c process.c free_n_error.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

###

all:		$(NAME)

$(NAME):	$(SRC)
			@make -C $(LIBFT)
			@$(CC) -o $(NAME) $(SRC) -L. $(LIBFT)/libft.a

clean:
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re norm
