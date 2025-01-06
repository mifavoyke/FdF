/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <yhusieva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:38:46 by yhusieva          #+#    #+#             */
/*   Updated: 2025/01/04 14:06:58 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_map(mlx_image_t *img, t_box	*box, char *arg)
{
	char	**map_lines;
	t_map	**map;

	box->height = ft_count_height(arg);
	if (box->height == 0)
		return (1);
	map_lines = ft_get_all(arg, box->height);
	if (map_lines == NULL)
		return (1);
	map = ft_parse_map(map_lines, box->height, box);
	if (map == NULL)
		return (1);
	ft_rescale(map, box);
	ft_draw(img, map, box);
	ft_free(map_lines, box->height);
	ft_free_map(map, box->height);
	return (0);
}

static int32_t	ft_handle_map(mlx_t *mlx, mlx_image_t *img, t_box	*box, char *arg)
{
	int	issuccess;

	issuccess = ft_map(img, box, arg);
	if (issuccess == 1)
	{
		perror("Failed to open the file.");
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
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
	if (ft_handle_map(fdf.mlx, fdf.img, &fdf.box, argv[1]) == EXIT_FAILURE)
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
