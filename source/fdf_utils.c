/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <yhusieva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:39:21 by yhusieva          #+#    #+#             */
/*   Updated: 2025/07/20 18:19:24 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_hook(void *param)
{
	t_fdf *fdf = (t_fdf *)param;

	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->box.offset.start_y -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->box.offset.start_y += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		fdf->box.offset.start_x += 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		fdf->box.offset.start_x -= 10;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->image = mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	ft_draw(fdf->img, fdf->map, &fdf->box);
}

void	ft_error(void)
{
	perror(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

size_t	ft_count_height(char *arg)
{
	char	*one_line;
	int		fd;
	size_t	i;

	i = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (0);
	one_line = get_next_line(fd);
	if (!one_line)
		return (0);
	while (one_line != NULL)
	{
		i++;
		free(one_line);
		one_line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**ft_get_all(char *arg, size_t height)
{
	char	**read_lines;
	char	*one_line;
	int		i;
	int		fd;

	i = 0;
	read_lines = NULL;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (NULL);
	one_line = get_next_line(fd);
	if (!one_line)
		return (NULL);
	read_lines = (char **)malloc(height * sizeof(char *));
	if (read_lines == NULL)
		return (NULL);
	while (one_line != NULL)
	{
		read_lines[i] = one_line;
		one_line = get_next_line(fd);
		i++;
	}
	free(one_line);
	close(fd);
	return (read_lines);
}
