/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:52:05 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/26 22:24:33 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_rt *rt)
{
	static float time = 0;
	int	i;
	int	j;

	float	x;
	float	y;
	float	mul;
	i = 0;
	time += 0.1;
	mul = (sin(time) + 1) / 2;
	ft_fill_img(&rt->mlx.win, &rt->mlx.img, (t_color){.value = 0xffffffff});
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			x = ft_normalize(i, 0, WIDTH);
			y = ft_normalize(j, 0, HEIGHT);
			//x = 2 * x - 1;
			//y = 2 * y - 1;
			ft_put_pixel(&rt->mlx.img, i, j, colorf_to_color((t_colorf){.r = x, .g = y, .a = mul}));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win.win,
		rt->mlx.img.img, 0, 0);
}
