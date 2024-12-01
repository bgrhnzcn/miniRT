/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:52:05 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/01 02:16:59 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	calc_ray_dir(t_rt *rt, int i, int j)
{
	float	u;
	float	v;
	
	u = (2 * ft_normalize(i + 0.5, 0, WIDTH) - 1)
		* rt->renderer.image_width / 2;
	v = (2 * ft_normalize(j + 0.5, 0, HEIGHT) - 1)
		* rt->renderer.image_height / 2;
	return (ft_vec3_add(rt->scene.camera.orientation,
				ft_vec3_add(ft_vec3_mul(rt->scene.camera.right, u),
					ft_vec3_mul(rt->scene.camera.up, v))));
}

float	select_root(float *roots)
{
	if (roots[0] > 0 && roots[1] > 0)
	{
		if (roots[0] < roots[1])
			return (roots[0]);
		else
			return (roots[1]);
	}
	else if (roots[0] > 0)
		return (roots[0]);
	else if (roots[1] > 0)
		return (roots[1]);
	return (0);
}

void	sphere_intersect(t_rt *rt, t_sphere *sphere, t_vec3 ray_dir,
	t_hitinfo *info)
{
	float	roots[2];
	float	disc;
	float	coeff[3];

	coeff[A] = ft_vec3_dot(ray_dir, ray_dir);
	coeff[B] = 2 * ft_vec3_dot(ray_dir,
			ft_vec3_sub(rt->scene.camera.pos, sphere->pos));
	coeff[C] = ft_vec3_dot(ft_vec3_sub(rt->scene.camera.pos,
				sphere->pos),
			ft_vec3_sub(rt->scene.camera.pos, sphere->pos))
		- sphere->radius * sphere->radius;
	disc = coeff[B] * coeff[B] - (4 * coeff[A] * coeff[C]);
	if (disc < 0)
		return ;
	roots[0] = (-coeff[B] + sqrt(disc)) / (2 * coeff[A]);
	roots[1] = (-coeff[B] - sqrt(disc)) / (2 * coeff[A]);
	info->dist = select_root(roots);
	if (info->dist == 0)
		return ;
	info->point = ft_vec3_add(rt->scene.camera.pos,
					ft_vec3_mul(ray_dir, info->dist));
	info->normal = ft_vec3_norm(ft_vec3_sub(info->point, sphere->pos));
	info->color = sphere->color;
}

void	plane_intersect(t_rt *rt, t_plane *plane, t_vec3 ray_dir,
	t_hitinfo *info)
{
	(void)rt;
	(void)plane;
	(void)ray_dir;
	(void)info;
}

void	cylinder_intersect(t_rt *rt, t_cylinder *cylinder, t_vec3 ray_dir,
	t_hitinfo *info)
{
	(void)rt;
	(void)cylinder;
	(void)ray_dir;
	(void)info;
}

t_hitinfo	check_intersections(t_rt *rt, t_vec3 ray_dir)
{
	t_hitinfo	info;
	t_hitinfo	temp;
	int			k;

	k = 0;
	ft_memset(&info, 0, sizeof(t_hitinfo));
	ft_memset(&temp, 0, sizeof(t_hitinfo));
	while (k < rt->scene.spheres->size)
	{
		sphere_intersect(rt, &((t_sphere *)rt->scene.spheres->data)[k],
			ray_dir, &info);
		if (temp.dist > 0 && temp.dist < info.dist)
			info = temp;
		temp = info;
		k++;
	}
	k = 0;
	while (k < rt->scene.planes->size)
	{
		plane_intersect(rt, &((t_plane *)rt->scene.planes->data)[k],
			ray_dir, &info);
		if (temp.dist > 0 && temp.dist < info.dist)
			info = temp;
		temp = info;
		k++;
	}
	k = 0;
	while (k < rt->scene.planes->size)
	{
		cylinder_intersect(rt, &((t_cylinder *)rt->scene.cylinders->data)[k],
			ray_dir, &info);
		if (temp.dist > 0 && temp.dist < info.dist)
			info = temp;
		temp = info;
		k++;
	}
	return (info);
}

t_hitinfo	cast_ray(t_rt *rt, t_vec3 ray_dir, int i, int j)
{
	t_hitinfo	hitinfo;

	hitinfo = check_intersections(rt, ray_dir);
	if (ft_vec3_dot(hitinfo.normal, hitinfo.normal))
		ft_put_pixel(&rt->mlx.img, i, j,
			hitinfo.color);
	else
		ft_put_pixel(&rt->mlx.img, i, j,
			ft_set_color(255, 10, 20, 80));
	return (hitinfo);
}

void	render(t_rt *rt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= WIDTH && j < HEIGHT)
	{
		if (i == WIDTH)
		{
			i = 0;
			j++;
		}
		cast_ray(rt, calc_ray_dir(rt, i, j), i, j);
		i++;
	}
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win.win, rt->mlx.img.img, 0, 0);
}
