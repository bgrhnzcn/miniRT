#include "minirt.h"

/*
int parse_cylinder(t_parse *parse, char **line)
{
	
}

int parse_sphere(t_parse *parse, char **line)
{
	
}

int parse_plane(t_parse *parse, char **line)
{
	
}
*/

int	parse_light(t_parse *parse, char **line)
{
	char	**coordinates;
	char	**rgb;

	coordinates = ft_split(line[1], ',');
	rgb = ft_split(line[3], ',');
	if (count_dpointer(coordinates) != 3 || count_dpointer(rgb) != 3)
		return (free_dpointer(coordinates), free_dpointer(rgb),
		printf("Coordinates and/or rgb values must contain 3 numbers.\n")
		, EXIT_FAILURE);
	if (control_number(coordinates[0]) || control_number(coordinates[1])
	|| control_number(coordinates[2]) || control_number(line[2])
	|| control_number(rgb[0]) || control_number(rgb[1])
	|| control_number(rgb[2]))
		return (free_dpointer(coordinates), free_dpointer(rgb)
		, printf("Incorrect number format.\n"), EXIT_FAILURE);
	else
	{
		parse->light = malloc(sizeof(t_light));
		parse->light->position.x = ft_atof(coordinates[0]);
		parse->light->position.y = ft_atof(coordinates[1]);
		parse->light->position.z = ft_atof(coordinates[2]);
		parse->light->color.red = (unsigned char)ft_atof(rgb[0]);
		parse->light->color.green = (unsigned char)ft_atof(rgb[1]);
		parse->light->color.blue = (unsigned char)ft_atof(rgb[2]);
		parse->light->brightness = ft_atof(line[2]);
	}
	print_debug(parse->light, COMP_LIGHT);
	return (EXIT_SUCCESS);
}


int	parse_ambient(t_parse *parse, char **line)
{
	char	**rgb;

	rgb = ft_split(line[2], ',');
	if (count_dpointer(rgb) != 3)
		return (free_dpointer(rgb),
		printf("Coordinates and/or rgb values must contain 3 numbers.\n")
		, EXIT_FAILURE);
	if (control_number(line[1]) || control_number(rgb[0])
	|| control_number(rgb[1])
	|| control_number(rgb[2]))
		return (free_dpointer(rgb)
		, printf("Incorrect number format.\n"), EXIT_FAILURE);
	else
	{
		parse->ambient = malloc(sizeof(t_ambient));
		parse->ambient->color.red = (unsigned char)ft_atof(rgb[0]);
		parse->ambient->color.green = (unsigned char)ft_atof(rgb[1]);
		parse->ambient->color.blue = (unsigned char)ft_atof(rgb[2]);
		parse->ambient->strength = ft_atof(line[1]);
	}
	print_debug(parse->ambient, COMP_AMBIENT);
	return (EXIT_SUCCESS);
}


int	parse_camera(t_parse *parse, char **line)
{
	char	**coordinates;
	char	**orientation;

	coordinates = ft_split(line[1], ',');
	orientation = ft_split(line[2], ',');
	if (count_dpointer(coordinates) != 3 || count_dpointer(orientation) != 3)
		return (free_dpointer(coordinates), free_dpointer(orientation),
		printf("Coordinates and/or orientation values must contain 3 numbers.\n")
		, EXIT_FAILURE);
	if (control_number(coordinates[0]) || control_number(coordinates[1])
	|| control_number(coordinates[2]) || control_number(line[3])
	|| control_number(orientation[0]) || control_number(orientation[1])
	|| control_number(orientation[2]))
		return (free_dpointer(coordinates), free_dpointer(orientation)
		, printf("Incorrect number format.\n"), EXIT_FAILURE);
	else
	{
		parse->camera = malloc(sizeof(t_camera));
		parse->camera->position.x = ft_atof(coordinates[0]);
		parse->camera->position.y = ft_atof(coordinates[1]);
		parse->camera->position.z = ft_atof(coordinates[2]);
		parse->camera->orientation.x = (unsigned char)ft_atof(orientation[0]);
		parse->camera->orientation.y = (unsigned char)ft_atof(orientation[1]);
		parse->camera->orientation.z = (unsigned char)ft_atof(orientation[2]);
		parse->camera->fov = ft_atof(line[3]);
	}
	print_debug(parse->camera, COMP_CAMERA);
	return (EXIT_SUCCESS);
}


int	control_name(t_parse *parse, char **line)
{
	if ((!string_compare(line[0], "A") && parse->ambient)
	|| (!string_compare(line[0], "C") && parse->camera)
	|| (!string_compare(line[0], "L") && parse->light))
		return (printf("File must contain only one value each of A, C and L\n"));
	if (!string_compare(line[0], "A") && count_dpointer(line) == 3)
	{
		if (parse_ambient(parse, line))
		{
			return (EXIT_FAILURE);
		}
	}
	else if (!string_compare(line[0], "C") && count_dpointer(line) == 4)
	{
		if (parse_camera(parse, line))
		{
			return (EXIT_FAILURE);
		}
	}
	else if (!string_compare(line[0], "L") && count_dpointer(line) == 4)
	{
		if (parse_light(parse, line))
		{
			return (EXIT_FAILURE);
		}
	}
	else if (!string_compare(line[0], "pl") && count_dpointer(line) == 4)
		printf("Name: %s\n", line[0]);
	else if (!string_compare(line[0], "sp") && count_dpointer(line) == 4)
		printf("Name: %s\n", line[0]);
	else if (!string_compare(line[0], "cy") && count_dpointer(line) == 6)
		printf("Name: %s\n", line[0]);
	return (EXIT_SUCCESS);
}

int	take_values(t_parse *parse)
{
	char	**line;
	int		i;

	i = -1;
	parse->ambient = NULL;
	parse->light = NULL;
	parse->camera = NULL;
	while (parse->scene_file[++i])
	{
		line = ft_split(parse->scene_file[i], ' ');
		if (control_name(parse, line))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
