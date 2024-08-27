#include "../includes/fdf.h"

size_t ft_count_height(char *arg)
{
	char *one_line;
	size_t i;
	int fd;

	i = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
    {
        perror("Error opening file. - fd");
        return (1);
    }
	one_line = get_next_line(fd);
	if (!one_line)
		return(0);
	while (one_line != NULL) // EOF
	{
		i++;
		free(one_line);
		one_line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char **ft_get_all(char *arg, size_t height)
{
	char **read_lines = NULL;
	char *one_line;
	int i;
	int fd;

	i = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
    {
        perror("Error opening file. - fd");
        return (NULL);
    }
	one_line = get_next_line(fd);
	if (!one_line)
		return(NULL);
	read_lines = (char **)malloc(height * sizeof(char *));
	while (one_line != NULL) // EOF
	{
		read_lines[i] = one_line;
		one_line = get_next_line(fd);
		i++;
	}
	free(one_line);
	close(fd);
	return (read_lines);
}

int32_t main(int argc, char *argv[])
{
	// mlx_t *mlx;
	// mlx_image_t *img;
	// int32_t image;
	size_t height;
	t_map **test;

	if (argc != 2)
	{
		perror("arguments.");
		return (1);
	}
	// mlx = mlx_init(WIDTH, HEIGHT, "Bruh", true);
	// if (!mlx)
	// 	ft_error();
	// img = mlx_new_image(mlx, 699, 499);
	// image = mlx_image_to_window(mlx, img, 0, 0);
	// if (!img || image < 0)
	// 	ft_error();
	height = ft_count_height(argv[1]);
	test = ft_parse_map(ft_get_all(argv[1], height), height);
	size_t y = 0;
	while (y < height)
	{
		size_t x = 0;
		while (x < height)
		{
			printf("(%u, %u, %u) ", test[y][x].x, test[y][x].y, test[y][x].z);
			x++;
		}
		printf("\n");
		y++;
	}
	y = 0;
    while (y < height)
        free(test[y]);
    free(test);
	// ft_draw(img, 0, 0, 10);
	// mlx_loop_hook(mlx, ft_hook, mlx);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	return(EXIT_SUCCESS);
}
