/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:50:17 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/24 01:11:14 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	update_frame(t_rt *rt)
{
	gettimeofday(&rt->timer.start, NULL); //Frame start time
	render(rt); //Starting point for rendering.
	gettimeofday(&rt->timer.end, NULL); // Frame end time
	display_debug_time(rt); //Display how long the frame took to render as miliseconds.
	return (0);
}
