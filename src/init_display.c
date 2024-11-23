/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:04:50 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/23 19:42:09 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_display(t_rt *rt)
{
	rt->mlx.mlx = mlx_init();
	if (!rt->mlx.mlx)
		return (EXIT_FAILURE);
	rt->mlx.win.win = mlx_new_window(rt->mlx.mlx, WIDTH, HEIGHT, "miniRT");
	if (!rt->mlx.win.win)
		return (mlx_destroy_display(rt->mlx.mlx), EXIT_FAILURE);
	rt->mlx.img.img = mlx_new_image(rt->mlx.mlx, WIDTH, HEIGHT);
	if (!rt->mlx.img.img)
		return (mlx_destroy_window(rt->mlx.mlx, rt->mlx.win.win),
			mlx_destroy_display(rt->mlx.mlx), EXIT_FAILURE);
	rt->mlx.img.data = mlx_get_data_addr(rt->mlx.img.img,
			&rt->mlx.img.bits_per_pixel, &rt->mlx.img.size_line,
			&rt->mlx.img.endian);
	if (!rt->mlx.img.data)
		return (mlx_destroy_image(rt->mlx.mlx, rt->mlx.img.img),
			mlx_destroy_window(rt->mlx.mlx, rt->mlx.win.win),
			mlx_destroy_display(rt->mlx.mlx), EXIT_FAILURE);
}
