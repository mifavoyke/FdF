/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:38:56 by yhusieva          #+#    #+#             */
/*   Updated: 2024/12/05 13:38:58 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	int32_t	pixel;

	pixel = r << 24;
	pixel |= g << 16;
	pixel |= b << 8;
	pixel |= a;
	return (pixel);
}

static t_color	ft_define_rgb(int color)
{
	t_color	new_color;

	new_color.r = (color >> 16) & 0xFF;
	new_color.g = (color >> 8) & 0xFF;
	new_color.b = color & 0xFF;
	return (new_color);
}

int	ft_gradient(int start_color, int end_color, int position, int len)
{
	t_color	start_rgb;
	t_color	end_rgb;
	t_color	new_color;
	int		result;

	if (len == 0)
		return (end_color);
	start_rgb = ft_define_rgb(start_color);
	end_rgb = ft_define_rgb(end_color);
	new_color.r = start_rgb.r + ((end_rgb.r - start_rgb.r) * position / len);
	new_color.g = start_rgb.g + ((end_rgb.g - start_rgb.g) * position / len);
	new_color.b = start_rgb.b + ((end_rgb.b - start_rgb.b) * position / len);
	result = ft_pixel(new_color.r, new_color.g, new_color.b, 0xFF);
	return (result);
}
