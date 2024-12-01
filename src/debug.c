/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:36:19 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/01 01:59:31 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_debug_light(t_light *light)
{
	printf("Light:\n");
	printf("\tBrightness:\t%f\n", light->brightness);
	printf("\tpos:\n");
	printf("\t\tX:\t%f\n", light->pos.x);
	printf("\t\tY:\t%f\n", light->pos.y);
	printf("\t\tZ:\t%f\n", light->pos.z);
	printf("\tColor:\n");
	printf("\t\tRed:\t%f\n", light->color.r * 255);
	printf("\t\tGreen:\t%f\n", light->color.g * 255);
	printf("\t\tBlue:\t%f\n", light->color.b * 255);
}

static void	print_debug_camera(t_camera *camera)
{
	printf("Camera:\n");
	printf("\tFOV:\t\t%f\n", camera->fov);
	printf("\tpos:\n");
	printf("\t\tX:\t%f\n", camera->pos.x);
	printf("\t\tY:\t%f\n", camera->pos.y);
	printf("\t\tZ:\t%f\n", camera->pos.z);
	printf("\tForward:\n");
	printf("\t\tX:\t%f\n", camera->orientation.x);
	printf("\t\tY:\t%f\n", camera->orientation.y);
	printf("\t\tZ:\t%f\n", camera->orientation.z);
	printf("\tUp:\n");
	printf("\t\tX:\t%f\n", camera->up.x);
	printf("\t\tY:\t%f\n", camera->up.y);
	printf("\t\tZ:\t%f\n", camera->up.z);
	printf("\tRight:\n");
	printf("\t\tX:\t%f\n", camera->right.x);
	printf("\t\tY:\t%f\n", camera->right.y);
	printf("\t\tZ:\t%f\n", camera->right.z);
}

static void	print_debug_ambient(t_ambient *ambient)
{
	printf("Ambient:\n");
	printf("\tStrength:\t%f\n", ambient->strength);
	printf("\tColor:\n");
	printf("\t\tRed:\t%f\n", ambient->color.r * 255);
	printf("\t\tGreen:\t%f\n", ambient->color.g * 255);
	printf("\t\tBlue:\t%f\n", ambient->color.b * 255);
}

static void	print_debug_sphere(t_sphere *sphere)
{
	printf("Sphere:\n");
	printf("\tRadius:\t\t%f\n", sphere->radius);
	printf("\tpos:\n");
	printf("\t\tX:\t%f\n", sphere->pos.x);
	printf("\t\tY:\t%f\n", sphere->pos.y);
	printf("\t\tZ:\t%f\n", sphere->pos.z);
	printf("\tColor:\n");
	printf("\t\tRed:\t%f\n", sphere->color.r * 255);
	printf("\t\tGreen:\t%f\n", sphere->color.g * 255);
	printf("\t\tBlue:\t%f\n", sphere->color.b * 255);
}

static void	print_debug_plane(t_plane *plane)
{
	printf("Plane:\n");
	printf("\tpos:\n");
	printf("\t\tX:\t%f\n", plane->pos.x);
	printf("\t\tY:\t%f\n", plane->pos.y);
	printf("\t\tZ:\t%f\n", plane->pos.z);
	printf("\tNormal:\n");
	printf("\t\tX:\t%f\n", plane->normal.x);
	printf("\t\tY:\t%f\n", plane->normal.y);
	printf("\t\tZ:\t%f\n", plane->normal.z);
	printf("\tColor:\n");
	printf("\t\tRed:\t%f\n", plane->color.r * 255);
	printf("\t\tGreen:\t%f\n", plane->color.g * 255);
	printf("\t\tBlue:\t%f\n", plane->color.b * 255);
}

static void	print_debug_cylinder(t_cylinder *cylinder)
{
	printf("Cylinder:\n");
	printf("\tDiameter:\t%f\n", cylinder->diameter);
	printf("\tHeight:\t\t%f\n", cylinder->height);
	printf("\tpos:\n");
	printf("\t\tX:\t%f\n", cylinder->pos.x);
	printf("\t\tY:\t%f\n", cylinder->pos.y);
	printf("\t\tZ:\t%f\n", cylinder->pos.z);
	printf("\tOrientation:\n");
	printf("\t\tX:\t%f\n", cylinder->orientation.x);
	printf("\t\tY:\t%f\n", cylinder->orientation.y);
	printf("\t\tZ:\t%f\n", cylinder->orientation.z);
	printf("\tColor:\n");
	printf("\t\tRed:\t%f\n", cylinder->color.r * 255);;
	printf("\t\tGreen:\t%f\n", cylinder->color.g * 255);;
	printf("\t\tBlue:\t%f\n", cylinder->color.b * 255);;
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
