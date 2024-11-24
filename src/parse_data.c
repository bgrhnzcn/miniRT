/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:22:09 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/24 22:31:13 by bgrhnzcn         ###   ########.fr       */
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
	color->alpha = 0;
	color->red = ft_atoi(split[0]);
	color->green = ft_atoi(split[1]);
	color->blue = ft_atoi(split[2]);
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
