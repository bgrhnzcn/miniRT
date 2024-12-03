/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:06:52 by buozcan           #+#    #+#             */
/*   Updated: 2024/12/03 19:13:38 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_shape	*init_sphere()
{
	t_shape	*sphere;

	sphere = ft_calloc(1, sizeof(t_shape));
	sphere->type = Sphere;
	sphere->intersect = sphere_intersect;
	return (sphere);
}

t_shape	*init_plane()
{
	t_shape	*plane;

	plane = ft_calloc(1, sizeof(t_shape));
	plane->type = Plane;
	plane->intersect = plane_intersect;
	return (plane);
}

t_shape	*init_cylinder()
{
	t_shape	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_shape));
	cylinder->type = Cylinder;
	cylinder->intersect = cylinder_intersect;
	return (cylinder);
}
