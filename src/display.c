/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:04:50 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/24 00:07:49 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_display(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (EXIT_FAILURE);
	mlx->win.win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "miniRT");
	if (!mlx->win.win)
		return (mlx_destroy_display(mlx->mlx), EXIT_FAILURE);
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img.img)
		return (mlx_destroy_window(mlx->mlx, mlx->win.win),
			mlx_destroy_display(mlx->mlx), EXIT_FAILURE);
	mlx->img.data = (t_color *)mlx_get_data_addr(mlx->img.img,
			&mlx->img.bits_per_pixel, &mlx->img.size_line,
			&mlx->img.endian);
	if (!mlx->img.data)
		return (mlx_destroy_image(mlx->mlx, mlx->img.img),
			mlx_destroy_window(mlx->mlx, mlx->win.win),
			mlx_destroy_display(mlx->mlx), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	terminate_display(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win.win);
	mlx_destroy_display(mlx->mlx);
	return (EXIT_SUCCESS);
}
