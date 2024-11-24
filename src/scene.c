/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:40:42 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/24 23:51:02 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	control_extension(char *path)
{
	char	*temp;

	temp = ft_strrchr(path, '.');
	if (ft_strlen(temp) == 3 && temp[1] == 'r' && temp[2] == 't')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	read_scene(t_rt *rt)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(rt->scene.scene_path, O_RDONLY);
	if (fd == -1)
		return (printf("Cannot open given file.\n"), EXIT_FAILURE);
	rt->scene.scene_file = init_darray(1, sizeof(char **));
	if (!rt->scene.scene_file)
		return (printf("Failed to initialize scene file.\n"), EXIT_FAILURE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strtrim(line, " \t\n");
		if (!ft_strequ(temp, ""))
			push_darray(rt->scene.scene_file, &temp);
		else
			free(temp);
		free(line);
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}

static t_component_type	is_component_exist(t_rt *rt, char *line)
{
	if (!ft_strncmp(line, "A ", 2) && !rt->check.ambient)
		return (COMP_AMBIENT);
	if (!ft_strncmp(line, "C ", 2) && !rt->check.camera)
		return (COMP_CAMERA);
	if (!ft_strncmp(line, "L ", 2) && !rt->check.light)
		return (COMP_LIGHT);
	if (!ft_strncmp(line, "sp ", 3))
		return (COMP_SPHERE);
	if (!ft_strncmp(line, "pl ", 3))
		return (COMP_PLANE);
	if (!ft_strncmp(line, "cy ", 3))
		return (COMP_CYLINDER);
	return (COMP_FAIL);
}

int	parse_scene(t_rt *rt)
{
	t_component_type	type;
	char				**scene_file;
	int					i;

	i = -1;
	scene_file = (char **)rt->scene.scene_file->data;
	while (++i < rt->scene.scene_file->size)
	{
		type = is_component_exist(rt, scene_file[i]);
		if (type == COMP_FAIL)
			return (printf("Invalid component!\n"), EXIT_FAILURE);
		if (type == COMP_AMBIENT && parse_ambient(rt, scene_file[i]))
			return (EXIT_FAILURE);
		if (type == COMP_CAMERA && parse_camera(rt, scene_file[i]))
			return (EXIT_FAILURE);
		if (type == COMP_LIGHT && parse_light(rt, scene_file[i]))
			return (EXIT_FAILURE);
		if (type == COMP_SPHERE && parse_sphere(rt, scene_file[i]))
			return (EXIT_FAILURE);
		if (type == COMP_PLANE && parse_plane(rt, scene_file[i]))
			return (EXIT_FAILURE);
		if (type == COMP_CYLINDER && parse_cylinder(rt, scene_file[i]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
