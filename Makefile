NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

CPPFLAGS	= -I. -I$(MLX_DIR)

SRC_DIR		= src
OBJ_DIR		= obj

SRCS	= \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/parsing.c \
	$(SRC_DIR)/render.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/events/hooks.c \
	$(SRC_DIR)/events/loop_hook.c \
	$(SRC_DIR)/fractals/julia.c \
	$(SRC_DIR)/fractals/mandelbrot.c \
	$(SRC_DIR)/math/complex.c \
	$(SRC_DIR)/math/mapping.c \
	$(SRC_DIR)/mlx/image.c \
	$(SRC_DIR)/mlx/init.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Error: MiniLibX not found at $(MLX_DIR)"; \
		echo "Put the minilibx-linux folder at the project root (as in the subject)."; \
		exit 1; \
	fi
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean; fi

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
