/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:50:17 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/25 00:18:41 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_inputs(t_rt *rt)
{
	if (rt->key_states[ESC_KEY])
		terminate_program(rt);
}

//Updates inputs
//Frame start time
//Starting point for rendering.
// Frame end time
//Display how long the frame took to render as miliseconds.

int	update_frame(t_rt *rt)
{
	update_inputs(rt);
	gettimeofday(&rt->timer.start, NULL);
	render(rt);
	gettimeofday(&rt->timer.end, NULL);
	display_debug_time(rt);
	return (0);
}
