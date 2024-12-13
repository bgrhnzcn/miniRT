/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:52:43 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/13 18:56:21 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mtx4	mtx4_rot(double x, double y, double z)
{
	t_mtx4	rot;

	x = ft_deg_to_rad(x);
	y = ft_deg_to_rad(y);
	z = ft_deg_to_rad(z);
	rot.col1 = ft_vec4_set(
			cos(y) * cos(z),
			cos(y) * sin(z),
			-sin(y), 0);
	rot.col2 = ft_vec4_set(
			(sin(x) * sin(y) * cos(z)) - (cos(x) * sin(z)),
			(sin(x) * sin(y) * sin(z)) + (cos(x) * cos(z)),
			(sin(x) * cos(y)), 0);
	rot.col3 = ft_vec4_set(
			(cos(x) * sin(y) * cos(z)) + (sin(x) * sin(z)),
			(cos(x) * sin(y) * sin(z)) - (sin(x) * cos(z)),
			cos(x) * cos(y), 0);
	rot.col4 = ft_vec4_set(0, 0, 0, 1);
	return (rot);
}

int	init_scene(t_rt *rt, char *path)
{
	rt->scene.scene_path = ft_strdup(path);
	if (read_scene(rt))
		return (printf("Failed to read scene file.\n"), EXIT_FAILURE);
	rt->scene.shapes = init_darray(1, sizeof(t_shape));
	if (!rt->scene.shapes)
		return (printf("Failed to initialize scene components.\n"),
			EXIT_FAILURE);
	if (parse_scene(rt))
		return (free_darray(rt->scene.scene_file),
			free_darray(rt->scene.shapes),
			printf("Failed to parse scene file.\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	t_rt	rt;

	ft_memset(&rt, 0, sizeof(t_rt));
	if (ac != 2)
		return (printf("./miniRT <path-to-scene>\n"));
	else if (control_extension(av[1]))
		return (printf("Extension of scene file must be '.rt' format.\n"));
	if (init_scene(&rt, av[1]))
		return (EXIT_FAILURE);
	if (init_display(&rt))
		return (printf("Failed to initialize display.\n"));
}
