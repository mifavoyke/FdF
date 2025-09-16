NAME := fdf
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -O3 -ffast-math -g
CC := gcc
RM := rm -rf
HEADERS = -I ./include -I ./lib/MLX42/include -I ./lib/libft

SRC_DIR := ./source
LIBFT_DIR := ./lib/libft
MLX42_DIR = ./lib/MLX42
MLX42_BUILD = ./lib/MLX42/build
MLX42_REPO = https://github.com/codam-coding-college/MLX42.git

ifeq ($(shell uname), Darwin)
LIBS := $(MLX42_BUILD)/libmlx42.a -L/opt/homebrew/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else
LIBS := $(MLX42_BUILD)/libmlx42.a -ldl -lglfw -pthread -lm
endif

SRCS := $(SRC_DIR)/draw.c \
		$(SRC_DIR)/bresenhams_line.c \
		$(SRC_DIR)/draw_utils.c \
		$(SRC_DIR)/fdf.c \
		$(SRC_DIR)/fdf_utils.c \
		$(SRC_DIR)/gradient.c \
		$(SRC_DIR)/isometric.c \
		$(SRC_DIR)/parse_map.c \
		$(SRC_DIR)/parse_colours.c \
		$(SRC_DIR)/parse_utils.c

OBJS := ${SRCS:.c=.o}

all: libmlx libft $(NAME)

check_mlx:
	@if [ ! -d "$(MLX42_DIR)" ]; then \
		echo "MLX42 not found, cloning from GitHub..."; \
		git clone $(MLX42_REPO) $(MLX42_DIR); \
	elif [ -z "$(shell ls $(MLX42_DIR))" ]; then \
		echo "MLX42 directory is empty, cloning from GitHub..."; \
		rm -rf $(MLX42_DIR); \
		git clone $(MLX42_REPO) $(MLX42_DIR); \
	else \
		echo "MLX42 exists, pulling latest updates..."; \
		cd $(MLX42_DIR) && git pull; \
	fi

libmlx: check_mlx
	@cmake -DDEBUG=1 $(MLX42_DIR) -B $(MLX42_BUILD) && make -C $(MLX42_BUILD) -j4

libft:
	@echo "\033[0;35mCompiling...\033[0m"
	@make all -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(MLX42_BUILD)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(MLX42_DIR)

re: fclean all

.PHONY: all clean fclean re libmlx

.SILENT: $(OBJS)