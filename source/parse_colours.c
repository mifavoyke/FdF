/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colours.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:13:57 by yhusieva          #+#    #+#             */
/*   Updated: 2024/12/06 11:13:59 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_default(int *color, int z)
{
	z *= 40;
	if (z == 0)
		return ;
	else if (z > 255)
		z = 255;
	*color = z << 8 | 0x8A2BE2;
}

static int	ft_parse_hex_string(const char *hex_str)
{
	int	result;

	result = 0;
	if (hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X'))
		hex_str += 2;
	while (*hex_str)
	{
		result *= 16;
		if (*hex_str >= '0' && *hex_str <= '9')
			result += *hex_str - '0';
		else if (*hex_str >= 'a' && *hex_str <= 'f')
			result += *hex_str - 'a' + 10;
		else if (*hex_str >= 'A' && *hex_str <= 'F')
			result += *hex_str - 'A' + 10;
		else
			break ;
		hex_str++;
	}
	return (result);
}

void	ft_fill_element(t_map *map_element, char *value,
						unsigned int i, unsigned int y)
{
	char	**z_color;

	if (ft_strchr(value, ',') != NULL)
	{
		z_color = ft_split(value, ',');
		if (z_color == NULL)
			return ;
		map_element->z = ft_atoi(z_color[0]);
		map_element->color = ft_parse_hex_string(z_color[1]);
		ft_free(z_color, ft_width(z_color));
	}
	else
	{
		map_element->z = ft_atoi(value);
		map_element->color = ft_parse_hex_string("0x8A2BE2");
		ft_default(&map_element->color, map_element->z);
	}
	map_element->x = i;
	map_element->y = y;
}
