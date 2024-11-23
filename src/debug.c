/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:36:19 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/23 23:49:58 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_debug_light(t_light *light)
{
	printf("Light:\n");
	printf("\tBrightness: %f\n", light->brightness);
	printf("\tPosition:\n");
	printf("\t\tX: %f\n", light->position.x);
	printf("\t\tY: %f\n", light->position.y);
	printf("\t\tZ: %f\n", light->position.z);
	printf("\tColor:\n");
	printf("\t\tRed: %u\n", light->color.red);
	printf("\t\tGreen: %u\n", light->color.green);
	printf("\t\tBlue: %u\n", light->color.blue);
}

static void	print_debug_camera(t_camera *camera)
{
	printf("Camera:\n");
	printf("\tFOV: %f\n", camera->fov);
	printf("\tPosition:\n");
	printf("\t\tX: %f\n", camera->position.x);
	printf("\t\tY: %f\n", camera->position.y);
	printf("\t\tZ: %f\n", camera->position.z);
	printf("\tOrientation:\n");
	printf("\t\tX: %f\n", camera->orientation.x);
	printf("\t\tY: %f\n", camera->orientation.y);
	printf("\t\tZ: %f\n", camera->orientation.z);
}

static void	print_debug_ambient(t_ambient *ambient)
{
	printf("Ambient:\n");
	printf("\tStrength: %f\n", ambient->strength);
	printf("\tColor:\n");
	printf("\t\tRed: %u\n", ambient->color.red);
	printf("\t\tGreen: %u\n", ambient->color.green);
	printf("\t\tBlue: %u\n", ambient->color.blue);
}

static void	print_debug_sphere(t_sphere *sphere)
{
	printf("Sphere:\n");
	printf("\tRadius: %f\n", sphere->radius);
	printf("\tPosition:\n");
	printf("\t\tX: %f\n", sphere->position.x);
	printf("\t\tY: %f\n", sphere->position.y);
	printf("\t\tZ: %f\n", sphere->position.z);
	printf("\tColor:\n");
	printf("\t\tRed: %u\n", sphere->color.red);
	printf("\t\tGreen: %u\n", sphere->color.green);
	printf("\t\tBlue: %u\n", sphere->color.blue);
}

static void	print_debug_plane(t_plane *plane)
{
	printf("Plane:\n");
	printf("\tPosition:\n");
	printf("\t\tX: %f\n", plane->position.x);
	printf("\t\tY: %f\n", plane->position.y);
	printf("\t\tZ: %f\n", plane->position.z);
	printf("\tNormal:\n");
	printf("\t\tX: %f\n", plane->normal.x);
	printf("\t\tY: %f\n", plane->normal.y);
	printf("\t\tZ: %f\n", plane->normal.z);
	printf("\tColor:\n");
	printf("\t\tRed: %u\n", plane->color.red);
	printf("\t\tGreen: %u\n", plane->color.green);
	printf("\t\tBlue: %u\n", plane->color.blue);
}

static void	print_debug_cylinder(t_cylinder *cylinder)
{
	printf("Cylinder:\n");
	printf("\tDiameter: %f\n", cylinder->diameter);
	printf("\tHeight: %f\n", cylinder->height);
	printf("\tPosition:\n");
	printf("\t\tX: %f\n", cylinder->position.x);
	printf("\t\tY: %f\n", cylinder->position.y);
	printf("\t\tZ: %f\n", cylinder->position.z);
	printf("\tOrientation:\n");
	printf("\t\tX: %f\n", cylinder->orientation.x);
	printf("\t\tY: %f\n", cylinder->orientation.y);
	printf("\t\tZ: %f\n", cylinder->orientation.z);
	printf("\tColor:\n");
	printf("\t\tRed: %u\n", cylinder->color.red);
	printf("\t\tGreen: %u\n", cylinder->color.green);
	printf("\t\tBlue: %u\n", cylinder->color.blue);
}

void	print_debug(void *comp, t_component_type type)
{
	if (type == COMP_LIGHT) //light
		print_debug_light((t_light *)comp);
	else if (type == COMP_CAMERA) //camera
		print_debug_camera((t_camera *)comp);
	else if (type == COMP_AMBIENT) //ambient
		print_debug_ambient((t_ambient *)comp);
	else if (type == COMP_SPHERE) //sphere
		print_debug_sphere((t_sphere *)comp);
	else if (type == COMP_PLANE) //plane
		print_debug_plane((t_plane *)comp);
	else if (type == COMP_CYLINDER) //cylinder
		print_debug_cylinder((t_cylinder *)comp);
}
