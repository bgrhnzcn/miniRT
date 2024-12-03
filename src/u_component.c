/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_component.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:54:36 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/03 20:23:24 by buozcan          ###   ########.fr       */
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
	if (rt->scene.ambient.strength < 0 || rt->scene.ambient.strength > 1)
		return (free_dpointer(split), printf("Incorrect strength!\n")
			, EXIT_FAILURE);
	if (parse_color(&rt->scene.ambient.color, split[2]))
		return (free_dpointer(split), printf("Incorrect RGB! (uint[0, 255])\n")
			, EXIT_FAILURE);
	print_debug(&rt->scene.ambient, COMP_AMBIENT);
	return (EXIT_SUCCESS);
}

int	parse_camera(t_rt *rt, char *line)
{
	char		**split;
	t_camera	*camera;

	camera = &rt->scene.camera;
	split = ft_split(line, ' ');
	if (split == NULL)
		return (printf("Allocation failed!\n"), EXIT_FAILURE);
	if (count_dpointer(split) != 4)
		return (free_dpointer(split), printf("Incorrect count of inputs!\n")
			, EXIT_FAILURE);
	if (cntrl_nbr(split[3]))
		return (free_dpointer(split), printf("Incorrect strenght!\n")
			, EXIT_FAILURE);
	camera->fov = ft_atof(split[3]);
	if (camera->fov < 0 || camera->fov > 180)
		return (free_dpointer(split), printf("Incorrect FOV!\n")
			, EXIT_FAILURE);
	if (parse_vec3(&camera->pos, split[1]))
		return (free_dpointer(split), printf("Incorrect pos!\n")
			, EXIT_FAILURE);
	if (parse_vec3(&camera->orientation, split[2]))
		return (free_dpointer(split), printf("Incorrect orientation!\n")
			, EXIT_FAILURE);
	if (!ft_vec3_equ(camera->orientation, ft_vec3_norm(camera->orientation)))
		return (free_dpointer(split), printf("Orientation must be normal!\n")
			, EXIT_FAILURE);
	camera->right = ft_vec3_norm(ft_vec3_cross(g_vec3_j, camera->orientation));
	camera->up = ft_vec3_cross(camera->right, camera->orientation);
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
		return (free_dpointer(split), printf("Incorrect strenght!\n")
			, EXIT_FAILURE);
	rt->scene.light.brightness = ft_atof(split[2]);
	if (rt->scene.light.brightness < 0 || rt->scene.light.brightness > 1)
		return (free_dpointer(split), printf("Incorrect brightness!\n")
			, EXIT_FAILURE);
	if (parse_vec3(&rt->scene.light.pos, split[1]))
		return (free_dpointer(split), printf("Incorrect pos!\n")
			, EXIT_FAILURE);
	if (parse_color(&rt->scene.light.color, split[3]))
		return (free_dpointer(split), printf("Incorrect orientation!\n")
			, EXIT_FAILURE);
	print_debug(&rt->scene.light, COMP_LIGHT);
	return (EXIT_SUCCESS);
}
