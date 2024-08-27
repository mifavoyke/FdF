#ifndef FDF_H
# define FDF_H

# include "../lib/libft/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <fcntl.h>

# ifndef WIDTH
#  define WIDTH 700
# endif

# ifndef HEIGHT
#  define HEIGHT 500
# endif

typedef struct s_map {
    uint32_t x;
    uint32_t y;
    uint32_t z;
} t_map;

// typedef struct s_map2 {
//     char **row;
//     size_t width;
//     struct s_map2 next;
// } t_map2;

uint32_t ft_derivative_x(uint32_t x, uint32_t z);
void ft_draw_big_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color, uint32_t scale);
void ft_draw(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t z);
void ft_error(void);
void ft_hook(void *param);
t_map **ft_parse_map(char **map_lines, size_t height);

#endif