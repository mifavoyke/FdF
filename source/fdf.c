/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:38:46 by yhusieva          #+#    #+#             */
/*   Updated: 2024/12/05 13:38:48 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_map(mlx_image_t *img, char *arg)
{
	t_box	box;
	char	**map_lines;
	t_map	**map;

	box.height = ft_count_height(arg);
	if (box.height == 0)
		return (1);
	map_lines = ft_get_all(arg, box.height);
	if (map_lines == NULL)
		return (1);
	map = ft_parse_map(map_lines, box.height, &box);
	if (map == NULL)
		return (1);
	ft_rescale(map, &box);
	ft_draw(img, map, &box);
	ft_free(map_lines, box.height);
	ft_free_map(map, box.height);
	return (0);
}

static int32_t	ft_handle_map(mlx_t *mlx, mlx_image_t *img, char *arg)
{
	int	issuccess;

	issuccess = ft_map(img, arg);
	if (issuccess == 1)
	{
		perror("Failed to open the file.");
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int32_t	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int32_t		image;

	if (argc != 2)
	{
		perror("Wrong number of arguments.");
		return (0);
	}
	mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, 1920, 1080);
	if (ft_handle_map(mlx, img, argv[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	image = mlx_image_to_window(mlx, img, 0, 0);
	if (!img || image < 0)
		ft_error();
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
