SRC		=	ft_printf.c
OBJ		=	ft_printf.o
NAME	=	libftprintf.a

.PHONY : clean fclean all re

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ) : %.o : %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

