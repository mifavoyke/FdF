/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:57:49 by yhusieva          #+#    #+#             */
/*   Updated: 2024/12/06 10:57:51 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_shallow_line(t_parameters *params, mlx_image_t *img,
						int color0, int color1)
{
	float	x;
	float	y;
	int		i;

	x = params->x0;
	y = params->y0;
	if (x > 0 && x < img->width && y > 0 && y < img->height)
		mlx_put_pixel(img, x, y, ft_gradient(color0, color1, 0, params->dx));
	i = 0;
	while (i < params->dx)
	{
		x += params->sx;
		if (params->p <= 0)
			params->p += 2 * params->dy;
		else
		{
			y += params->sy;
			params->p += 2 * params->dy - 2 * params->dx;
		}
		if (x > 0 && x < img->width && y > 0 && y < img->height)
			mlx_put_pixel(img, x, y,
				ft_gradient(color0, color1, i + 1, params->dx));
		i++;
	}
}

void	ft_steep_line(t_parameters *params, mlx_image_t *img,
					int color0, int color1)
{
	float	x;
	float	y;
	int		i;

	x = params->x0;
	y = params->y0;
	if (x > 0 && x < img->width && y > 0 && y < img->height)
		mlx_put_pixel(img, x, y, ft_gradient(color0, color1, 0, params->dy));
	i = 0;
	while (i < params->dy)
	{
		y += params->sy;
		if (params->p <= 0)
			params->p += 2 * params->dx;
		else
		{
			x += params->sx;
			params->p += 2 * params->dx - 2 * params->dy;
		}
		if (x > 0 && x < img->width && y > 0 && y < img->height)
			mlx_put_pixel(img, x, y,
				ft_gradient(color0, color1, i + 1, params->dy));
		i++;
	}
}
