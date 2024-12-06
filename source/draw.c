/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:21:59 by yhusieva          #+#    #+#             */
/*   Updated: 2024/12/05 13:36:42 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_draw_diagonal(mlx_image_t *img, t_parameters *params,
							int color0, int color1)
{
	int	m;

	if (params->dx == 0)
		m = 1;
	else
		m = params->dy / params->dx;
	if (m < 1)
		ft_shallow_line(params, img, color0, color1);
	else
		ft_steep_line(params, img, color0, color1);
}

static void	ft_horizontal(mlx_image_t *img, t_map **map,
							t_parameters *params, t_pos *pos)
{
	t_coordinates	coord;

	coord.x0 = map[pos->y][pos->x].x;
	coord.y0 = map[pos->y][pos->x].y;
	coord.x1 = map[pos->y][pos->x + 1].x;
	coord.y1 = map[pos->y][pos->x + 1].y;
	ft_define_parameters(params, &coord);
	ft_draw_diagonal(img, params, map[pos->y][pos->x].color,
		map[pos->y][pos->x + 1].color);
}

static void	ft_vertical(mlx_image_t *img, t_map **map,
						t_parameters *params, t_pos *pos)
{
	t_coordinates	coord;

	coord.x0 = map[pos->y][pos->x].x;
	coord.y0 = map[pos->y][pos->x].y;
	coord.x1 = map[pos->y + 1][pos->x].x;
	coord.y1 = map[pos->y + 1][pos->x].y;
	ft_define_parameters(params, &coord);
	ft_draw_diagonal(img, params, map[pos->y][pos->x].color,
		map[pos->y + 1][pos->x].color);
}

void	ft_draw(mlx_image_t *img, t_map **map, t_box *box)
{
	t_parameters	params;
	t_pos			position;

	position.y = 0;
	while (position.y < box->height)
	{
		position.x = 0;
		while (position.x < box->width)
		{
			if (position.x < box->width - 1)
				ft_horizontal(img, map, &params, &position);
			if (position.y < box->height - 1)
				ft_vertical(img, map, &params, &position);
			position.x++;
		}
		position.y++;
	}
}
