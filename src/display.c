/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:04:50 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/01 03:18:48 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	init_events(t_rt *rt)
{
	mlx_do_key_autorepeatoff(rt->mlx.mlx);
	mlx_hook(rt->mlx.win.win, Destroy, DestroyMask, terminate_program, rt);
	mlx_hook(rt->mlx.win.win, KeyPress, KeyPressMask, key_press, rt);
	mlx_hook(rt->mlx.win.win, KeyRelease, KeyReleaseMask, key_release, rt);
	mlx_hook(rt->mlx.win.win, ButtonPress, ButtonPressMask, mouse_press, rt);
	mlx_hook(rt->mlx.win.win, ButtonRelease, ButtonReleaseMask, mouse_release,
		rt);
	mlx_loop_hook(rt->mlx.mlx, update_frame, rt);
	mlx_loop(rt->mlx.mlx);
}

int	init_display(t_rt *rt)
{
	rt->mlx.mlx = mlx_init();
	if (!rt->mlx.mlx)
		return (EXIT_FAILURE);
	rt->mlx.win.win = mlx_new_window(rt->mlx.mlx, WIDTH, HEIGHT, "miniRT");
	rt->mlx.win.height = HEIGHT;
	rt->mlx.win.width = WIDTH;
	if (!rt->mlx.win.win)
		return (EXIT_FAILURE);
	rt->mlx.img.img = mlx_new_image(rt->mlx.mlx, WIDTH, HEIGHT);
	if (!rt->mlx.img.img)
		return (mlx_destroy_window(rt->mlx.mlx, rt->mlx.win.win),
			EXIT_FAILURE);
	rt->mlx.img.data = (t_color32 *)mlx_get_data_addr(rt->mlx.img.img,
			&rt->mlx.img.bits_per_pixel, &rt->mlx.img.size_line,
			&rt->mlx.img.endian);
	rt->mlx.img.size_line /= rt->mlx.img.bits_per_pixel / 8;
	if (!rt->mlx.img.data)
		return (mlx_destroy_image(rt->mlx.mlx, rt->mlx.img.img),
			mlx_destroy_window(rt->mlx.mlx, rt->mlx.win.win),
			EXIT_FAILURE);
	rt->renderer.image_height = 2 * tan(rt->scene.camera.fov / 2);
	rt->renderer.image_width = rt->renderer.image_height * ASPECT_RATIO;
	init_events(rt);
	return (EXIT_SUCCESS);
}

int	terminate_display(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win.win);
	mlx_destroy_display(mlx->mlx);
	return (EXIT_SUCCESS);
}
