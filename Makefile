NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c putnbr.c print_hex.c

OBJS:= $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
clean:
	rm -rf $(OBJS)
	rm -f *.o

fclean: clean
	rm -Rf $(NAME)

re: fclean all 

.PHONY: all bonus clean fclean re