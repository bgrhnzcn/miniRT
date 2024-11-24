/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:36:19 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/25 00:16:40 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_debug_light(t_light *light)
{
	printf("Light:\n");
	printf("\tBrightness:\t%f\n", light->brightness);
	printf("\tPosition:\n");
	printf("\t\tX:\t%f\n", light->position.x);
	printf("\t\tY:\t%f\n", light->position.y);
	printf("\t\tZ:\t%f\n", light->position.z);
	printf("\tColor:\n");
	printf("\t\tRed:\t%u\n", light->color.red);
	printf("\t\tGreen:\t%u\n", light->color.green);
	printf("\t\tBlue:\t%u\n", light->color.blue);
}

static void	print_debug_camera(t_camera *camera)
{
	printf("Camera:\n");
	printf("\tFOV:\t\t%f\n", camera->fov);
	printf("\tPosition:\n");
	printf("\t\tX:\t%f\n", camera->position.x);
	printf("\t\tY:\t%f\n", camera->position.y);
	printf("\t\tZ:\t%f\n", camera->position.z);
	printf("\tOrientation:\n");
	printf("\t\tX:\t%f\n", camera->orientation.x);
	printf("\t\tY:\t%f\n", camera->orientation.y);
	printf("\t\tZ:\t%f\n", camera->orientation.z);
}

static void	print_debug_ambient(t_ambient *ambient)
{
	printf("Ambient:\n");
	printf("\tStrength:\t%f\n", ambient->strength);
	printf("\tColor:\n");
	printf("\t\tRed:\t%u\n", ambient->color.red);
	printf("\t\tGreen:\t%u\n", ambient->color.green);
	printf("\t\tBlue:\t%u\n", ambient->color.blue);
}

static void	print_debug_sphere(t_sphere *sphere)
{
	printf("Sphere:\n");
	printf("\tRadius:\t\t%f\n", sphere->radius);
	printf("\tPosition:\n");
	printf("\t\tX:\t%f\n", sphere->position.x);
	printf("\t\tY:\t%f\n", sphere->position.y);
	printf("\t\tZ:\t%f\n", sphere->position.z);
	printf("\tColor:\n");
	printf("\t\tRed:\t%u\n", sphere->color.red);
	printf("\t\tGreen:\t%u\n", sphere->color.green);
	printf("\t\tBlue:\t%u\n", sphere->color.blue);
}

static void	print_debug_plane(t_plane *plane)
{
	printf("Plane:\n");
	printf("\tPosition:\n");
	printf("\t\tX:\t%f\n", plane->position.x);
	printf("\t\tY:\t%f\n", plane->position.y);
	printf("\t\tZ:\t%f\n", plane->position.z);
	printf("\tNormal:\n");
	printf("\t\tX:\t%f\n", plane->normal.x);
	printf("\t\tY:\t%f\n", plane->normal.y);
	printf("\t\tZ:\t%f\n", plane->normal.z);
	printf("\tColor:\n");
	printf("\t\tRed:\t%u\n", plane->color.red);
	printf("\t\tGreen:\t%u\n", plane->color.green);
	printf("\t\tBlue:\t%u\n", plane->color.blue);
}

static void	print_debug_cylinder(t_cylinder *cylinder)
{
	printf("Cylinder:\n");
	printf("\tDiameter:\t%f\n", cylinder->diameter);
	printf("\tHeight:\t\t%f\n", cylinder->height);
	printf("\tPosition:\n");
	printf("\t\tX:\t%f\n", cylinder->position.x);
	printf("\t\tY:\t%f\n", cylinder->position.y);
	printf("\t\tZ:\t%f\n", cylinder->position.z);
	printf("\tOrientation:\n");
	printf("\t\tX:\t%f\n", cylinder->orientation.x);
	printf("\t\tY:\t%f\n", cylinder->orientation.y);
	printf("\t\tZ:\t%f\n", cylinder->orientation.z);
	printf("\tColor:\n");
	printf("\t\tRed:\t%u\n", cylinder->color.red);
	printf("\t\tGreen:\t%u\n", cylinder->color.green);
	printf("\t\tBlue:\t%u\n", cylinder->color.blue);
}

void	print_debug(void *comp, t_component_type type)
{
	if (type == COMP_LIGHT)
		print_debug_light((t_light *)comp);
	else if (type == COMP_CAMERA)
		print_debug_camera((t_camera *)comp);
	else if (type == COMP_AMBIENT)
		print_debug_ambient((t_ambient *)comp);
	else if (type == COMP_SPHERE)
		print_debug_sphere((t_sphere *)comp);
	else if (type == COMP_PLANE)
		print_debug_plane((t_plane *)comp);
	else if (type == COMP_CYLINDER)
		print_debug_cylinder((t_cylinder *)comp);
}

static double	get_frame_time(t_timer *timer)
{
	double	time;

	time = (timer->end.tv_sec - timer->start.tv_sec) * 1000.0;
	time += (timer->end.tv_usec - timer->start.tv_usec) / 1000.0;
	return (time);
}

void	display_debug_time(t_rt *rt)
{
	char	str[100];

	sprintf(str, "Frame time: %.3fms", get_frame_time(&rt->timer));
	mlx_string_put(rt->mlx.mlx, rt->mlx.win.win, 10, 20, 0xFFFFFF, str);
}

void	debug_print_scene(t_rt *rt)
{
	int		i;
	char	**lines;

	i = 0;
	lines = rt->scene.scene_file->data;
	while (i < rt->scene.scene_file->size)
	{
		printf("%s\n", lines[i]);
		i++;
	}
}
