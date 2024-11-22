/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:04:50 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/25 00:17:33 by bgrhnzcn         ###   ########.fr       */
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
		return (EXIT_FAILURE);
	rt->mlx.img.img = mlx_new_image(rt->mlx.mlx, WIDTH, HEIGHT);
	if (!rt->mlx.img.img)
		return (mlx_destroy_window(rt->mlx.mlx, rt->mlx.win.win),
			EXIT_FAILURE);
	rt->mlx.img.data = (t_color *)mlx_get_data_addr(rt->mlx.img.img,
			&rt->mlx.img.bits_per_pixel, &rt->mlx.img.size_line,
			&rt->mlx.img.endian);
	if (!rt->mlx.img.data)
		return (mlx_destroy_image(rt->mlx.mlx, rt->mlx.img.img),
			mlx_destroy_window(rt->mlx.mlx, rt->mlx.win.win),
			EXIT_FAILURE);
	mlx_do_key_autorepeatoff(rt->mlx.mlx);
	mlx_hook(rt->mlx.win.win, Destroy, DestroyMask, terminate_program, rt);
	mlx_hook(rt->mlx.win.win, KeyPress, KeyPressMask, key_press, rt);
	mlx_hook(rt->mlx.win.win, KeyRelease, KeyReleaseMask, key_release, rt);
	mlx_loop_hook(rt->mlx.mlx, update_frame, rt);
	mlx_loop(rt->mlx.mlx);
	return (EXIT_SUCCESS);
}

int	terminate_display(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win.win);
	//mlx_destroy_display(mlx->mlx); Usefull for mlx-linux. Not exist for MacOS.
	free(mlx->mlx);
	return (EXIT_SUCCESS);
}
