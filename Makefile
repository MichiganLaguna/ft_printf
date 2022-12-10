#--------------------------------------------------------------------------------#
#									GENERICS									 #
#--------------------------------------------------------------------------------#

DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all clean fclean re
HIDE =

#--------------------------------------------------------------------------------#
#									VARIABLES									 #
#--------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I. -I./$(INCDIR)
RM		=	rm -f

# Main target name
NAME	=	libftprintf.a

# Sources
SRCDIR	=	src/
SRCS	=	ft_printf.c
SRCS	:=	$(addprefix $(SRCDIR),$(SRCS))

# Objects
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

# Includes
INCDIR	=	include/
INC		=	$(wildcard $(INCDIR)*.h)

#--------------------------------------------------------------------------------#
#									RULES										 #
#--------------------------------------------------------------------------------#

all: $(NAME)

# Main target rule
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -L$(ADIR) -lft -c $< -o $@

$(OBJDIR):
	$(HIDE)mkdir -p $@

clean:
	$(HIDE)$(RM) $(OBJS)

fclean: clean
	$(HIDE)$(RM) $(NAME)

re: fclean all
