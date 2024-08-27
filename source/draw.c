#include "../includes/fdf.h"

uint32_t ft_derivative_x(uint32_t x, uint32_t z)
{
	uint32_t iso_x;

	iso_x = x - z * cos(30 * (M_1_PI/180));
	return (iso_x);
}

uint32_t ft_derivative_y(uint32_t y, uint32_t z)
{
	uint32_t iso_y;

	iso_y = y - z * sin(30 * (M_1_PI/180));
	return (iso_y);
}

uint32_t ft_curve(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1)
{
    uint32_t y;
    uint32_t x;
    
    x = x0 + 1;
    y = ((y1 - y0) / (x1 - x0) * (x - x0)) + y0;
    return (y);
}

void ft_draw_big_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color, uint32_t scale)
{
	uint32_t i = 0;
	uint32_t j;

	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			mlx_put_pixel(img, x * scale + i, y * scale + j, color);
			++j;
		}
		++i;
	}
}

void ft_draw(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t z)
{
	x = ft_derivative_x(x, z);
	printf("%d\n", x);
    while (x < 50)
    {
        y = ft_curve(x, y, 50, 40);
	    ft_draw_big_pixel(img, x, y, 0xFF0000FF, 4);
        printf("%d; ", x);
        printf("%d\n", y);
        x++;
    }
    while(y < 40)
    {
        x = ft_derivative_x(x, z);
    }
}
