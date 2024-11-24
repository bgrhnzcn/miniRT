/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_component.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:54:36 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/25 00:12:28 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_ambient(t_rt *rt, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (count_dpointer(split) != 3)
		return (free_dpointer(split), EXIT_FAILURE);
	if (cntrl_nbr(split[1]))
		return (free_dpointer(split), printf("Incorrect strenght! (f[0, 1])\n")
			, EXIT_FAILURE);
	rt->scene.ambient.strength = ft_atof(split[1]);
	if (parse_color(&rt->scene.ambient.color, split[2]))
		return (free_dpointer(split), printf("Incorrect RGB! (uint[0, 255])\n")
			, EXIT_FAILURE);
	print_debug(&rt->scene.ambient, COMP_AMBIENT);
	return (EXIT_SUCCESS);
}

int	parse_camera(t_rt *rt, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split == NULL)
		return (printf("Allocation failed!\n"), EXIT_FAILURE);
	if (count_dpointer(split) != 4)
		return (free_dpointer(split), printf("Incorrect count of inputs!\n")
			, EXIT_FAILURE);
	if (cntrl_nbr(split[3]))
		return (free_dpointer(split), printf("Incorrect strenght! (f[0, 1])\n")
			, EXIT_FAILURE);
	rt->scene.camera.fov = ft_atof(split[3]);
	if (parse_vec3(&rt->scene.camera.position, split[1]))
		return (free_dpointer(split), printf("Incorrect position!\n")
			, EXIT_FAILURE);
	if (parse_vec3(&rt->scene.camera.orientation, split[2]))
		return (free_dpointer(split), printf("Incorrect orientation!\n")
			, EXIT_FAILURE);
	print_debug(&rt->scene.camera, COMP_CAMERA);
	return (EXIT_SUCCESS);
}

int	parse_light(t_rt *rt, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (count_dpointer(split) != 4)
		return (free_dpointer(split), EXIT_FAILURE);
	if (cntrl_nbr(split[2]))
		return (free_dpointer(split), printf("Incorrect strenght! (f[0, 1])\n")
			, EXIT_FAILURE);
	rt->scene.light.brightness = ft_atof(split[2]);
	if (parse_vec3(&rt->scene.light.position, split[1]))
		return (free_dpointer(split), printf("Incorrect position!\n")
			, EXIT_FAILURE);
	if (parse_color(&rt->scene.light.color, split[3]))
		return (free_dpointer(split), printf("Incorrect orientation!\n")
			, EXIT_FAILURE);
	print_debug(&rt->scene.light, COMP_LIGHT);
	return (EXIT_SUCCESS);
}
