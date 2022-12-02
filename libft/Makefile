#-------------------------------------------------------------------------------#
#									GENERICS									#
#-------------------------------------------------------------------------------#

DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all clean fclean re
HIDE = 

#-------------------------------------------------------------------------------#
#									VARIABLES									#
#-------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I. -I./$(INCDIR)
RM		=	rm -f

# Main target name
NAME	=	libft.a

# Sources
SRCDIR	=	src/
SRCS	=	ft_atoi.c     ft_lstadd_back.c	 ft_memchr.c	  ft_split.c \
			ft_strncmp.c ft_bzero.c    ft_lstadd_front.c  ft_memcmp.c \
			ft_strchr.c	 ft_strnstr.c ft_calloc.c   ft_lstclear.c \
			ft_memcpy.c	  ft_strdup.c	 ft_strrchr.c ft_isalnum.c \
			ft_lstdelone.c	 ft_memmove.c	  ft_striteri.c  ft_strtrim.c \
			ft_isalpha.c  ft_lstiter.c	 ft_memset.c	  ft_strjoin.c \
			ft_substr.c ft_isascii.c  ft_lstlast.c	 ft_putchar_fd.c \
			ft_strlcat.c	 ft_tolower.c ft_isdigit.c  ft_lstmap.c	\
			ft_putendl_fd.c  ft_strlcpy.c	 ft_toupper.c ft_isprint.c \
			ft_lstnew.c	 ft_putnbr_fd.c   ft_strlen.c ft_itoa.c \
			ft_lstsize.c	 ft_putstr_fd.c   ft_strmapi.c
SRCS	:=	$(addprefix $(SRCDIR),$(SRCS))

# Objects
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

# Includes
INCDIR	=	include/
INC		=	$(wildcard $(INCDIR)*.h)

#-------------------------------------------------------------------------------#
#									RULES										#
#-------------------------------------------------------------------------------#

all: $(NAME)

# Main target rule
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	$(HIDE)mkdir -p $@

clean:
	$(HIDE)$(RM) $(OBJS)

fclean: clean
	$(HIDE)$(RM) $(NAME)

re: fclean all