SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c

OBJS = $(SRC:.c=.o)

HDRS = ft_printf.h
NAME = libftprintf.a
RM      = rm -f
CC      = cc
AR      = ar -crs
FLAGS   = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(AR) $(NAME) $(OBJS)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re