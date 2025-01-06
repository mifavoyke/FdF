/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <yhusieva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:39:12 by yhusieva          #+#    #+#             */
/*   Updated: 2025/01/04 13:05:00 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_get_direction(int start, int end)
{
	int	s;

	if (end > start)
		s = 1;
	else
		s = -1;
	return (s);
}

static int	ft_get_difference(int start, int end)
{
	int	result;

	result = abs(end - start);
	return (result);
}

void	ft_define_parameters(t_parameters *params, t_coordinates *coord)
{
	params->dx = ft_get_difference(coord->x0, coord->x1);
	params->dy = ft_get_difference(coord->y0, coord->y1);
	params->sx = ft_get_direction(coord->x0, coord->x1);
	params->sy = ft_get_direction(coord->y0, coord->y1);
	params->p = 2 * params->dy - params->dx;
	params->x0 = coord->x0;
	params->y0 = coord->y0;
}

void	ft_define_offset(t_box *box)
{
	int	max_width_interval;
	int	max_height_interval;

	max_width_interval = WIDTH / box->width;
	max_height_interval = HEIGHT / box->height;
	if (max_width_interval < max_height_interval)
		box->offset.interval = max_width_interval;
	else
		box->offset.interval = max_height_interval;
	box->offset.start_x = (WIDTH - (box->width * box->offset.interval) / 2);
	box->offset.start_y = (HEIGHT - (box->height * box->offset.interval));
}
