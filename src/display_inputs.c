/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:59:42 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/24 00:06:59 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	terminate_program(t_rt *rt)
{
	terminate_display(&rt->mlx);
	printf("Program terminated successfully.\n");
	exit(EXIT_SUCCESS);
}
