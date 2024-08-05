CC = cc
FLAGS = -Werror -Wextra -Wall
SERVER = server
CLIENT = client
LDFLAGS = -Ift_printf -Lft_printf -lftprintf

all: $(SERVER) $(CLIENT)

$(SERVER): server.c ft_printf/libftprintf.a
	$(CC) $(CFLAGS) $(LDFLAGS) server.c -o $(SERVER)

$(CLIENT): client.c ft_printf/libftprintf.a
	$(CC) $(CFLAGS) $(LDFLAGS) client.c -o $(CLIENT)

ft_printf/libftprintf.a:
	make -C ft_printf

clean:
	make clean -C ft_printf
	
fclean: clean
	make fclean -C ft_printf
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re printf/printf.a