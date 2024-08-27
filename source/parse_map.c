#include "../includes/fdf.h"

int *ft_parse_values(char **line, size_t size)
{
	int	*values;
	size_t	x;

	values = (int *)malloc(size * sizeof(int));
	if (values == NULL)
		return (NULL);
	x = 0;
	while (x < size)
	{
		values[x] = ft_atoi(line[x]);
		x++;
	}
	return (values);
}

void ft_free(char **values, size_t width)
{
    size_t i;

    i = 0;
    while(i < width)
    {
        free(values[i]);
        i++;
    }
}

size_t ft_width(char **values)
{
    size_t i;

    i = 0;
    while (values[i])
        i++;
    return (i);
}

void ft_fill_row(t_map **map, int *parsed_values, size_t width, size_t y)
{
    size_t x;

    x = 0;
    while (x < width)
    {
        map[y][x].x = x;
        map[y][x].y = y;
        map[y][x].z = parsed_values[x];
        x++;
    }
}

t_map **ft_parse_map(char **map_lines, size_t height)
{
    t_map **map;
    size_t y;
    size_t width;
    int *parsed_values;
    char **values;

    map = (t_map **)malloc(height * sizeof(t_map *));
    if (map == NULL)
        return (NULL);
    y = 0;
    while (y < height)
    {
        values = ft_split(map_lines[y], ' ');
        width = ft_width(values);
        parsed_values = ft_parse_values(values, width);
        map[y] = (t_map *)malloc(width * sizeof(t_map));
        ft_fill_row(map, parsed_values, width, y);
        free(parsed_values);
        ft_free(values, width);
        free(values);
        y++;
    }
    return (map);
}

// int main(void)
// {
//     char *map_lines[] = {
//     "1 2 3", 
//     "4 5 6", 
//     "7 8 9"};
//     size_t height = 3;
//     size_t y = 0;
//     size_t x = 0;

//     t_map **map = ft_parse_map(map_lines, height);
//     while (y < height)
//     {
//         x = 0;
//         while (x < height)
//         {
//             printf("(%u, %u, %u) ", map[y][x].x, map[y][x].y, map[y][x].z);
//             x++;
//         }
//         printf("\n");
//         y++;
//     }
//     y = 0;
//     while (y < height)
//         free(map[y]);
//     free(map);
//     return (0);
// }
