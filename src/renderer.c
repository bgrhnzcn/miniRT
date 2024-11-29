/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:52:05 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/11/29 19:22:08 by buozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calc_ray_dir(t_rt *rt)
{
	float	u;
	float	v;
	int	i;
	int	j;

	i = 0;
	rt->renderer.image_height = 2 * tan(rt->scene.camera.fov / 2); 
	rt->renderer.image_width = rt->renderer.image_height * ASPECT_RATIO;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			u = (2 * ft_normalize(i + 0.5, 0, WIDTH) - 1)
				* rt->renderer.image_width / 2;
			v = (2 * ft_normalize(j + 0.5, 0, HEIGHT) - 1)
				* rt->renderer.image_height / 2;
			rt->renderer.ray_dir[j + WIDTH * i]
				= ft_vec3_add(rt->scene.camera.orientation,
					ft_vec3_add(ft_vec3_mul(rt->scene.camera.right, u),
						ft_vec3_mul(rt->scene.camera.up, v)));
			j++;
		}
		i++;
	}
}

t_hitinfo	sphere_intersect(t_rt *rt, t_sphere *sphere)
{
	t_hitinfo	info;
	float	roots[2];
	float	discriminant;

	memset(&info, 0, sizeof(t_hitinfo));
	//calculate discriminant and check intersection. If intersect, find intersection points.
	//Discriminant = sqrt(b^2 - 4ac)
	//roots = (-b +- sqrt(D)) / 2a
	if (discriminant < 0)
		return (info);
}

t_bool	check_intersections(t_rt *rt, int i, int j)
{
	int	k;

	k = 0;
	while (k < rt->scene.spheres->size)
	{
		sphere_intersect(rt, &rt->scene.spheres->data[i + WIDTH * j]);
		k++;
	}
	(void)rt;
	(void)i;
	(void)j;
	return (false);
}

void	cast_ray(t_rt *rt)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (check_intersections(rt, i, j))
				ft_put_pixel(&rt->mlx.img, i, j,
					(t_color){.a = 0, .r = 1, .g = 0, .b = 0});
			else
				ft_put_pixel(&rt->mlx.img, i, j,
					(t_color){.a = 0, .r = 0, .g = 0, .b = 0});
			j++;
		}
		i++;
	}
}

void	render(t_rt *rt)
{
	calc_ray_dir(rt);
	cast_ray(rt);
}
