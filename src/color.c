/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:34:40 by buozcan           #+#    #+#             */
/*   Updated: 2024/11/26 20:42:26 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_colorf	color_to_colorf(t_color color)
{
	t_colorf	res;

	res.a = ft_normalize(color.alpha, 0, 255);
	res.r = ft_normalize(color.red, 0, 255);
	res.g = ft_normalize(color.green, 0, 255);
	res.b = ft_normalize(color.blue, 0, 255);
	return (res);
}

t_color		colorf_to_color(t_colorf color)
{
	t_color	res;

	res.alpha = ft_lerp(color.a, 0, 255);
	res.red = ft_lerp(color.r, 0, 255);
	res.green = ft_lerp(color.g, 0, 255);
	res.blue = ft_lerp(color.b, 0, 255);
	return (res);
}
