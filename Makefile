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
SRCS	=	ft_printchr.c ft_printhex.c ft_printnbr.c \
			ft_printstr.c ft_printunsigned.c ft_splitone.c
SRCS	:=	$(addprefix $(SRCDIR),$(SRCS))

# Objects
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

# Includes
INCDIR	=	include/
INC		=	$(wildcard $(INCDIR)*.h)

# Archive
ADIR	=	libft/
ANAME	= 	libft.a
ANAME	:=	$(addprefix $(ADIR),$(ANAME))

#--------------------------------------------------------------------------------#
#									RULES										 #
#--------------------------------------------------------------------------------#

all: $(NAME)

# Main target rule
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

# Libft rule
$(ANAME):
	$(MAKE) -C $(ADIR) all

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(ANAME) $(INC) | $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -L$(ADIR) -lft -c $< -o $@

$(OBJDIR):
	$(HIDE)mkdir -p $@

clean:
	$(HIDE)$(RM) $(OBJS)
	$(HIDE)$(MAKE) -C $(ADIR) clean

fclean: clean
	$(HIDE)$(RM) $(NAME) $(ANAME)

re: fclean all
