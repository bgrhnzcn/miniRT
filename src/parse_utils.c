/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:31:29 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/25 00:15:03 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	cntrl_nbr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != '-' && str[i] != '+' && str[i] != '.'
			&& !(str[i] >= '0' && str[i] <= '9'))
			return (EXIT_FAILURE);
	if (ft_strchr(str, '.') != ft_strrchr(str, '.'))
		return (EXIT_FAILURE);
	i = 0;
	while (str[++i])
	{
		if (str[i] != '-' || str[i] != '+')
			break ;
		i++;
	}
	if (ft_strchr(str + i, '-') != NULL)
		return (EXIT_FAILURE);
	if (ft_strchr(str + i, '+') != NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

float	ft_atof(char *str)
{
	float	res;
	int		i;

	if (!ft_strchr(str, '.'))
		return (ft_atoi(str));
	res = 0;
	res = ft_atoi(str);
	i = -1;
	while (str[++i] && str[i] != '.')
		;
	if (str[i] == '\0')
		i = 0;
	else
		i += 1;
	res += (ft_atoi(str + i) / pow(10, ft_strlen(str + i)));
	return (res);
}

void	free_dpointer(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free (str);
}

int	count_dpointer(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
