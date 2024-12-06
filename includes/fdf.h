/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:17:07 by yhusieva          #+#    #+#             */
/*   Updated: 2024/12/06 11:17:10 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# define PI 3.14159265359
# define WIDTH 800
# define HEIGHT 600

typedef struct s_map
{
	float	x;
	float	y;
	int		z;
	int		color;
}	t_map;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_parameters
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		p;
	float	x0;
	float	y0;
}	t_parameters;

typedef struct s_box
{
	size_t	width;
	size_t	height;
}	t_box;

typedef struct s_offset
{
	int	start_x;
	int	start_y;
	int	interval;
}	t_offset;

typedef struct s_pos
{
	unsigned int	x;
	unsigned int	y;
}	t_pos;

typedef struct s_coordinates
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
}	t_coordinates;

// DRAWING
void	ft_draw(mlx_image_t *img, t_map **map, t_box *box);
void	ft_shallow_line(t_parameters *params, mlx_image_t *img,
			int color0, int color1);
void	ft_steep_line(t_parameters *params, mlx_image_t *img,
			int color0, int color1);

// GRADIENT
int		ft_gradient(int start_color, int end_color, int position, int len);

// PARSING
t_map	**ft_parse_map(char **map_lines, size_t height, t_box *box);
void	ft_rescale(t_map **map, t_box *box);
void	ft_fill_element(t_map *map_element, char *value,
			unsigned int i, unsigned int y);

// UTILS
size_t	ft_count_height(char *arg);
char	**ft_get_all(char *arg, size_t height);
void	ft_hook(void *param);
void	ft_define_parameters(t_parameters *params, t_coordinates *coord);
void	ft_define_offset(t_offset *offset, t_box *box);
size_t	ft_width(char **values);
void	ft_error(void);
void	ft_free(char **ptr, size_t size);
void	ft_free_map(t_map **map, size_t height);

#endif
