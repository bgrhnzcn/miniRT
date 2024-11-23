/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:52:05 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/24 01:09:38 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_rt *rt)
{
	ft_fill_img(&rt->mlx.win, &rt->mlx.img, (t_color){.value = 0x10101010});
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win.win, rt->mlx.img.img, 0, 0);
}
