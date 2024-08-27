NAME := fdf
DIR_SRCS := ./source
HEADERS := -I ./include -I ./lib/MLX42/include -I ./lib/libft
LIBFT := ./lib/libft/libft.a
DIR_MLX42 := ./lib/MLX42/build
LIBMLX42 := $(DIR_MLX42)/libmlx42.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBS := $(LIBMLX42) -L/opt/homebrew/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit

SRCS := $(DIR_SRCS)/fdf.c \
		$(DIR_SRCS)/draw.c \
		$(DIR_SRCS)/utils.c \
		$(DIR_SRCS)/parse_map.c

OBJS := ${SRCS:.c=.o}

all: libmlx $(LIBFT) $(NAME)

$(LIBFT):
	@make all -C ./lib/libft

libmlx:
	@cmake -DDEBUG=1 ./lib/MLX42 -B $(DIR_MLX42) && make -C $(DIR_MLX42) -j4

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(DIR_SRCS)/%.o: $(DIR_SRCS)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

#  // clean libft objects DONT FORGET
clean:
	@rm -rf $(OBJS)
	@rm -rf $(DIR_MLX42)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx