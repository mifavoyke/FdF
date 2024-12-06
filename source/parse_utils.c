/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:39:35 by yhusieva          #+#    #+#             */
/*   Updated: 2024/12/05 13:39:36 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free(char **ptr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_free_map(t_map **map, size_t height)
{
	size_t	y;

	y = 0;
	while (y < height)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

size_t	ft_width(char **values)
{
	size_t	i;

	i = 0;
	if (!values)
		return (0);
	while (values[i])
		i++;
	return (i);
}
