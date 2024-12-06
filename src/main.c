/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:52:43 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/03 19:22:32 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
