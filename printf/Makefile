CC = CC
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c \
			print_format.c \
			print_char.c \
			print_str.c \
			print_dec.c \
			print_hex.c \
			print_ptr.c \

OBJECTS = $(SOURCES:.c=.o)

NAME = libftprintf.a

$(NAME):
		$(CC) $(CFLAGS) -c $(SOURCES)
		ar -rcs $(NAME) $(OBJECTS)

all: $(NAME)

re: fclean all

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

.PHONY: all re clean fclean