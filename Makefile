CLIENT_NAME = client
SERVER_NAME = server

C_SOURCE = client.c
S_SOURCE = server.c

C_OBJECT = $(C_SOURCE:.c=.o)
S_OBJECT = $(S_SOURCE:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT_NAME) $(SERVER_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_NAME): $(C_OBJECT)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(C_OBJECT) $(LIBFT) $(PRINTF) -o $(CLIENT_NAME)
	@echo client made

$(SERVER_NAME): $(S_OBJECT)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(S_OBJECT) $(LIBFT) $(PRINTF) -o $(SERVER_NAME)
	@echo server made

clean:
	rm -f $(C_OBJECT) $(S_OBJECT)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: clean fclean all re
