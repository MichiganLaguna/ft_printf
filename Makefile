SRC		=	ft_printf.c
OBJ		=	$(patsubst %.c,%.o,$(SRC))
NAME	=	libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ) : %.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all re
