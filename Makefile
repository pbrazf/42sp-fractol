NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c fractol.c
OBJS = $(SRCS:.c=.o)
MLX_LIB = minilibx-linux

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# Comando para compilar a minilibx-linux que vem do subject (se necessário)
#  make -C minilibx-linux/minilibx-linux

# Comando para compilar o programa temporariamente
# cc -Wall -Wextra -Werror -I. -Iminilibx-linux/minilibx-linux $(find src -name "*.c") -Lminilibx-linux/minilibx-linux -lmlx -lXext -lX11 -lm -o fractol
