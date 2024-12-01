/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:50:17 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/01 03:13:23 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_inputs(t_rt *rt)
{
	float	speed;

	if (rt->key_states[SHIFT_KEY])
		speed = 5;
	else
		speed = 2;
	if (rt->key_states[ESC_KEY])
		terminate_program(rt);
	if (rt->key_states[W_KEY])
		rt->scene.camera.pos = ft_vec3_add(rt->scene.camera.pos,
			ft_vec3_mul(rt->scene.camera.orientation, speed));
	if (rt->key_states[S_KEY])
		rt->scene.camera.pos = ft_vec3_sub(rt->scene.camera.pos,
			ft_vec3_mul(rt->scene.camera.orientation, speed));
	if (rt->key_states[A_KEY])
		rt->scene.camera.pos = ft_vec3_sub(rt->scene.camera.pos,
			ft_vec3_mul(rt->scene.camera.right, speed));
	if (rt->key_states[D_KEY])
		rt->scene.camera.pos = ft_vec3_add(rt->scene.camera.pos,
			ft_vec3_mul(rt->scene.camera.right, speed));
}

//Updates inputs
//Frame start time
//Starting point for rendering.
// Frame end time
//Display how long the frame took to render as miliseconds.

void test()
{
	exit(0);
}

int	update_frame(t_rt *rt)
{
	update_inputs(rt);
	gettimeofday(&rt->timer.start, NULL);
	render(rt);
	gettimeofday(&rt->timer.end, NULL);
	display_debug_time(rt);
	return (0);
}
