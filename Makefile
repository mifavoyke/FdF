NAME := fdf
DIR_SRCS := ./source
HEADERS := -I ./include -I ./lib/MLX42/include -I ./lib/libft
LIBFT := ./lib/libft/libft.a
DIR_MLX42 := ./lib/MLX42/build
LIBMLX42 := $(DIR_MLX42)/libmlx42.a

CC := gcc
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast -g

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
LIBS := $(LIBMLX42) -L/opt/homebrew/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else
LIBS := $(LIBMLX42) -ldl -lglfw -pthread -lm
endif

SRCS := $(DIR_SRCS)/draw.c \
		$(DIR_SRCS)/bresenhams_line.c \
		$(DIR_SRCS)/draw_utils.c \
		$(DIR_SRCS)/fdf.c \
		$(DIR_SRCS)/fdf_utils.c \
		$(DIR_SRCS)/gradient.c \
		$(DIR_SRCS)/isometric.c \
		$(DIR_SRCS)/parse_map.c \
		$(DIR_SRCS)/parse_colours.c \
		$(DIR_SRCS)/parse_utils.c

OBJS := ${SRCS:.c=.o}

all: libmlx $(LIBFT) $(NAME)

$(LIBFT):
	@make all -C ./lib/libft

libmlx:
	@cmake -DDEBUG=1 ./lib/MLX42 -B $(DIR_MLX42) && make -C $(DIR_MLX42) -j4

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

$(DIR_SRCS)/%.o: $(DIR_SRCS)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

clean:
	@rm -rf $(OBJS)
	@make clean -C ./lib/libft
	@rm -rf $(DIR_MLX42)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./lib/libft

re: fclean all

.PHONY: all clean fclean re libmlx
