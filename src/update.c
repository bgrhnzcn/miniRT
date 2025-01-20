/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:50:17 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/03 20:18:19 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_shape(t_rt *rt, float speed)
{
	if (rt->key_states[W_KEY])
		rt->selected->pos = ft_vec3_add(rt->selected->pos,
			ft_vec3_mul(rt->scene.camera.orientation, speed));
	if (rt->key_states[S_KEY])
		rt->selected->pos = ft_vec3_sub(rt->selected->pos,
			ft_vec3_mul(rt->scene.camera.orientation, speed));
	if (rt->key_states[A_KEY])
		rt->selected->pos = ft_vec3_sub(rt->selected->pos,
			ft_vec3_mul(rt->scene.camera.right, speed));
	if (rt->key_states[D_KEY])
		rt->selected->pos = ft_vec3_add(rt->selected->pos,
			ft_vec3_mul(rt->scene.camera.right, speed));
	if (rt->key_states[CTRL_KEY])
		rt->selected->pos = ft_vec3_add(rt->selected->pos,
			ft_vec3_mul(rt->scene.camera.up, speed));
	if (rt->key_states[SPACE_KEY])
		rt->selected->pos = ft_vec3_sub(rt->selected->pos,
			ft_vec3_mul(rt->scene.camera.up, speed));
	if (rt->key_states[Q_KEY])
	{
		if (rt->selected->type == Plane)
			rt->selected->normal = vec_rot_around(
				rt->selected->normal, rt->scene.camera.up, speed);
		if (rt->selected->type == Cylinder)
			rt->selected->orientation = vec_rot_around(
				rt->selected->orientation, rt->scene.camera.up, speed);
	}
	if (rt->key_states[E_KEY])
	{
		if (rt->selected->type == Plane)
			rt->selected->normal = vec_rot_around(
				rt->selected->normal, rt->scene.camera.up, -speed);
		if (rt->selected->type == Cylinder)
			rt->selected->orientation = vec_rot_around(
				rt->selected->orientation, rt->scene.camera.up, -speed);
	}
}

void	update_inputs(t_rt *rt)
{
	float	speed;

	if (rt->key_states[ESC_KEY])
		terminate_program(rt);
	if (rt->key_states[SHIFT_KEY])
		speed = 5;
	else
		speed = 2;
	if (rt->selected != NULL)
	{
		update_shape(rt, speed);
		return ;
	}
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
	if (rt->key_states[CTRL_KEY])
		rt->scene.camera.pos = ft_vec3_add(rt->scene.camera.pos,
			ft_vec3_mul(rt->scene.camera.up, speed));
	if (rt->key_states[SPACE_KEY])
		rt->scene.camera.pos = ft_vec3_sub(rt->scene.camera.pos,
			ft_vec3_mul(rt->scene.camera.up, speed));
	if (rt->key_states[Q_KEY])
	{
		rt->scene.camera.orientation = vec_rot_around(
			rt->scene.camera.orientation, rt->scene.camera.up, speed);
		rt->scene.camera.right = vec_rot_around(
			rt->scene.camera.right, rt->scene.camera.up, speed);
	}
	if (rt->key_states[E_KEY])
	{
		rt->scene.camera.orientation = vec_rot_around(
			rt->scene.camera.orientation, rt->scene.camera.up, -speed);
		rt->scene.camera.right = vec_rot_around(
			rt->scene.camera.right, rt->scene.camera.up, -speed);
	}
}

//Updates inputs
//Frame start time
//Starting point for rendering.
// Frame end time
//Display how long the frame took to render as miliseconds.

void	display_selected(t_rt *rt)
{
	mlx_string_put(rt->mlx.mlx, rt->mlx.win.win, 10, 40, 0xFFFFFF, "Selected");
	if (rt->selected == NULL)
		mlx_string_put(rt->mlx.mlx, rt->mlx.win.win, 10, 60, 0xFFFFFF, "Type: Camera");
	if (rt->selected != NULL && rt->selected->type == Plane)
		mlx_string_put(rt->mlx.mlx, rt->mlx.win.win, 10, 60, 0xFFFFFF, "Type: Plane");
	else if (rt->selected != NULL && rt->selected->type == Sphere)
		mlx_string_put(rt->mlx.mlx, rt->mlx.win.win, 10, 60, 0xFFFFFF, "Type: Sphere");
	else if (rt->selected != NULL && rt->selected->type == Cylinder)
		mlx_string_put(rt->mlx.mlx, rt->mlx.win.win, 10, 60, 0xFFFFFF, "Type: Cylinder");
	mlx_string_put(rt->mlx.mlx, rt->mlx.win.win, 10, 80, 0xFFFFFF, ft_itoa(25));
}

int	update_frame(t_rt *rt)
{
	update_inputs(rt);
	gettimeofday(&rt->timer.start, NULL);
	render(rt);
	gettimeofday(&rt->timer.end, NULL);
	display_debug_time(rt);
	display_selected(rt);
	return (0);
}
