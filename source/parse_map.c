/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:39:05 by yhusieva          #+#    #+#             */
/*   Updated: 2024/12/05 13:39:06 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static bool	ft_check_columns(char **values, t_box *box, unsigned int y)
{
	size_t	columns;

	if (y == 0)
		box->width = ft_width(values);
	columns = ft_width(values);
	if (columns != box->width)
	{
		perror("Wrong format of the map.");
		ft_free(values, columns);
		return (false);
	}
	return (true);
}

static bool	ft_allocate_and_fill_row(char **values, t_map **map,
									unsigned int y, t_box *box)
{
	unsigned int	x;

	map[y] = (t_map *)malloc(box->width * sizeof(t_map));
	if (!map[y])
		return (false);
	x = 0;
	while (x < box->width)
	{
		ft_fill_element(&map[y][x], values[x], x, y);
		x++;
	}
	return (true);
}

static bool	ft_process_row(t_map **map, t_box *box,
						char **map_lines, unsigned int y)
{
	char	**values;

	values = ft_split(map_lines[y], ' ');
	if (values == NULL)
	{
		free(map);
		return (false);
	}
	if (!ft_check_columns(values, box, y)
		|| !ft_allocate_and_fill_row(values, map, y, box))
	{
		ft_free(map_lines, box->height);
		ft_free_map(map, y);
		return (false);
	}
	ft_free(values, box->width);
	return (true);
}

t_map	**ft_parse_map(char **map_lines, size_t height, t_box *box)
{
	t_map			**map;
	unsigned int	y;

	map = (t_map **)malloc(height * sizeof(t_map *));
	if (!map)
		return (NULL);
	y = 0;
	while (y < height)
	{
		if (!ft_process_row(map, box, map_lines, y))
			return (NULL);
		y++;
	}
	return (map);
}
