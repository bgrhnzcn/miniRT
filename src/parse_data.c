/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:22:09 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/28 16:50:07 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_color(t_color *color, char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (count_dpointer(split) != 3)
		return (free_dpointer(split), EXIT_FAILURE);
	if (cntrl_nbr(split[0]) || cntrl_nbr(split[1]) || cntrl_nbr(split[2]))
		return (free_dpointer(split), EXIT_FAILURE);
	color->a = 1.;
	color->r = ft_atoi(split[0]) / 255.;
	color->g = ft_atoi(split[1]) / 255.;
	color->b = ft_atoi(split[2]) / 255.;
	if (color->r < 0 || color->r > 1 || color->g < 0 || color->g > 1
		|| color->b < 0 || color->b > 1)
		return (free_dpointer(split), EXIT_FAILURE);
	free_dpointer(split);
	return (EXIT_SUCCESS);
}

int	parse_vec3(t_vec3 *vec3, char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (count_dpointer(split) != 3)
		return (free_dpointer(split), EXIT_FAILURE);
	if (cntrl_nbr(split[0]) || cntrl_nbr(split[1]) || cntrl_nbr(split[2]))
		return (free_dpointer(split), EXIT_FAILURE);
	vec3->x = ft_atof(split[0]);
	vec3->y = ft_atof(split[1]);
	vec3->z = ft_atof(split[2]);
	free_dpointer(split);
	return (EXIT_SUCCESS);
}
