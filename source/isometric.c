/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:39:27 by yhusieva          #+#    #+#             */
/*   Updated: 2024/12/05 13:39:28 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static float	ft_derivative_x(float x, float y, int z)
{
	float	der_x;

	der_x = cos(45 * (PI / 180)) * x - sin(45 * (PI / 180)) * y;
	x = der_x - z * cos(60 * (PI / 180));
	return (x);
}

static float	ft_derivative_y(float x, float y, int z)
{
	float	der_y;

	der_y = sin(45 * (PI / 180)) * x + cos(45 * (PI / 180)) * y;
	y = der_y - z * sin(60 * (PI / 180));
	return (y);
}

static void	ft_zoom(t_map **map, t_offset *offset,
					unsigned int x, unsigned int y)
{
	int	new_x;
	int	new_y;

	new_x = map[y][x].x * offset->interval;
	new_y = map[y][x].y * offset->interval;
	map[y][x].x = ft_derivative_x(new_x, new_y, map[y][x].z) + offset->start_x;
	map[y][x].y = ft_derivative_y(new_x, new_y, map[y][x].z) + offset->start_y;
}

void	ft_rescale(t_map **map, t_box *box)
{
	unsigned int	x;
	unsigned int	y;
	t_offset		offset;

	ft_define_offset(&offset, box);
	y = 0;
	while (y < box->height)
	{
		x = 0;
		while (x < box->width)
		{
			ft_zoom(map, &offset, x, y);
			x++;
		}
		y++;
	}
}
