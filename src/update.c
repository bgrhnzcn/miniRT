/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:50:17 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/24 16:06:47 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_inputs(t_rt *rt)
{
	if (rt->key_states[ESC_KEY] && rt->key_states[CTRL_KEY])
		terminate_program(rt);
}

int	update_frame(t_rt *rt)
{
	update_inputs(rt); //Updates inputs
	gettimeofday(&rt->timer.start, NULL); //Frame start time
	render(rt); //Starting point for rendering.
	gettimeofday(&rt->timer.end, NULL); // Frame end time
	display_debug_time(rt); //Display how long the frame took to render as miliseconds.
	return (0);
}
