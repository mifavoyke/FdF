/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <yhusieva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:38:46 by yhusieva          #+#    #+#             */
/*   Updated: 2025/07/20 18:21:30 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_map(t_fdf *fdf, char *arg)
{
	char	**map_lines;

	fdf->box.height = ft_count_height(arg);
	if (fdf->box.height == 0)
		return (1);
	map_lines = ft_get_all(arg, fdf->box.height);
	if (map_lines == NULL)
		return (1);
	fdf->map = ft_parse_map(map_lines, fdf->box.height, &fdf->box);
	if (fdf->map == NULL)
		return (1);
	ft_rescale(fdf->map, &fdf->box);
	ft_draw(fdf->img, fdf->map, &fdf->box);
	// ft_free(map_lines, fdf->box.height);
	// ft_free_map(fdf->map, fdf->box.height);
	return (0);
}

static int32_t	ft_handle_map(t_fdf *fdf, char *arg)
{
	int	issuccess;

	issuccess = ft_map(fdf, arg);
	if (issuccess == 1)
	{
		perror("Failed to open the file.");
		mlx_delete_image(fdf->mlx, fdf->img);
		mlx_terminate(fdf->mlx);
		return (EXIT_FAILURE);
	}
	return (0);
}

int32_t	main(int argc, char *argv[])
{
	t_fdf fdf;

	if (argc != 2)
	{
		perror("Wrong number of arguments.");
		return (0);
	}
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!fdf.mlx)
		ft_error();
	fdf.img = mlx_new_image(fdf.mlx, 1920, 1080);
	if (ft_handle_map(&fdf, argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fdf.image = mlx_image_to_window(fdf.mlx, fdf.img, 0, 0);
	if (!fdf.img || fdf.image < 0)
		ft_error();
	mlx_loop_hook(fdf.mlx, ft_hook, (void *)&fdf);
	mlx_loop(fdf.mlx);
	mlx_delete_image(fdf.mlx, fdf.img);
	mlx_terminate(fdf.mlx);
	return (0);
}
