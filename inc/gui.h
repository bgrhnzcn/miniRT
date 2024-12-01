/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:22:43 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/01 03:12:38 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include <minirt.h>
# include <libft.h>
# include <mlx.h>
# include <darray.h>

typedef struct s_button
{
	t_vec2	pos;
	t_vec2	size;
	t_color	color;
	char	*label;
	void	(*on_click)();
}	t_button;

typedef struct	s_gui
{
	t_img		img;
	t_darray	*buttons;
}	t_gui;

t_gui	*init_gui(t_mlx *mlx);
void	add_button(t_gui *gui, t_button *button);
void	draw_button(t_mlx *mlx, t_img *img, t_button *button);

# endif
