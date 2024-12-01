/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:59:42 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/01 03:18:44 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	get_keysym_from_keycode(int keycode)
{
	int	i;

	i = 0;
	while (i < MAX_KEY_COUNT)
	{
		if (keycode == g_keysym_to_keycode[i])
			return (i);
		i++;
	}
	return (-1);
}

int	terminate_program(t_rt *rt)
{
	terminate_display(&rt->mlx);
	printf("Program terminated successfully.\n");
	exit(EXIT_SUCCESS);
}

int	key_press(int keycode, t_rt *rt)
{
	int	keysym;

	keysym = get_keysym_from_keycode(keycode);
	if (keysym != -1)
		rt->key_states[keysym] = true;
	return (0);
}

int	key_release(int keycode, t_rt *rt)
{
	int	keysym;

	keysym = get_keysym_from_keycode(keycode);
	if (keysym != -1)
		rt->key_states[keysym] = false;
	return (0);
}

int	mouse_press(int button, int x, int y, t_rt *rt)
{
	(void)button;
	(void)x;
	(void)y;
	(void)rt;
	printf("Mouse pressed. Button %d\n", button);
	printf("Mouse position: x: %d, y: %d\n", x, y);
	return (0);
}

int	mouse_release(int button, int x, int y, t_rt *rt)
{
	(void)button;
	(void)x;
	(void)y;
	(void)rt;
	printf("Mouse released. Button %d\n", button);
	printf("Mouse position: x: %d, y: %d\n", x, y);
	return (0);
}
