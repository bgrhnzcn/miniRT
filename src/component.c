/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:53:31 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/01 01:59:31 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_sphere(t_rt *rt, char *line)
{
	char		**split;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	split = ft_split(line, ' ');
	if (count_dpointer(split) != 4)
		return (free_dpointer(split), EXIT_FAILURE);
	if (parse_vec3(&sphere->pos, split[1]))
		return (free_dpointer(split), printf("Incorrect pos!\n")
			, EXIT_FAILURE);
	if (cntrl_nbr(split[2]))
		return (free_dpointer(split), printf("Incorrect radius!\n")
			, EXIT_FAILURE);
	sphere->radius = ft_atof(split[2]);
	if (parse_color(&sphere->color, split[3]))
		return (free_dpointer(split), printf("Incorrect RGB! [0, 255]\n")
			, EXIT_FAILURE);
	push_darray(rt->scene.spheres, sphere);
	print_debug(sphere, COMP_SPHERE);
	return (EXIT_SUCCESS);
}

int	parse_plane(t_rt *rt, char *line)
{
	char	**split;
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	split = ft_split(line, ' ');
	if (count_dpointer(split) != 4)
		return (free_dpointer(split), EXIT_FAILURE);
	if (parse_vec3(&plane->pos, split[1]))
		return (free_dpointer(split), printf("Incorrect pos!\n")
			, EXIT_FAILURE);
	if (parse_vec3(&plane->normal, split[2]))
		return (free_dpointer(split), printf("Incorrect normal!\n")
			, EXIT_FAILURE);
	if (parse_color(&plane->color, split[3]))
		return (free_dpointer(split), printf("Incorrect RGB! [0, 255]\n")
			, EXIT_FAILURE);
	push_darray(rt->scene.planes, plane);
	print_debug(plane, COMP_PLANE);
	return (EXIT_SUCCESS);
}

int	parse_cylinder(t_rt *rt, char *line)
{
	char		**split;
	t_cylinder	*cy;

	cy = malloc(sizeof(t_cylinder));
	split = ft_split(line, ' ');
	if (count_dpointer(split) != 6)
		return (free_dpointer(split), EXIT_FAILURE);
	if (parse_vec3(&cy->pos, split[1]))
		return (free_dpointer(split), printf("Incorrect pos!\n"), 1);
	if (parse_vec3(&cy->orientation, split[2]))
		return (free_dpointer(split), printf("Incorrect normal!\n"), 1);
	if (cntrl_nbr(split[3]))
		return (free_dpointer(split), printf("Incorrect radius!\n"), 1);
	cy->diameter = ft_atof(split[3]);
	if (cntrl_nbr(split[4]))
		return (free_dpointer(split), printf("Incorrect height!\n"), 1);
	cy->height = ft_atof(split[4]);
	if (parse_color(&cy->color, split[5]))
		return (free_dpointer(split), printf("Incorrect RGB! [0, 255]\n")
			, EXIT_FAILURE);
	push_darray(rt->scene.cylinders, cy);
	print_debug(cy, COMP_CYLINDER);
	return (EXIT_SUCCESS);
}
