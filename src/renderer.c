/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 00:52:05 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2024/12/13 19:33:25 by buozcan          ###   ########.fr       */
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
	return (-1);
}

void	sphere_intersect(t_rt *rt, t_shape *sphere, t_vec3 ray_dir,
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
	if (info->dist < 0)
		return ;
	info->point = ft_vec3_add(rt->scene.camera.pos,
					ft_vec3_mul(ray_dir, info->dist));
	info->normal = ft_vec3_norm(ft_vec3_sub(info->point, sphere->pos));
	info->color = sphere->color;
	info->is_hit = true;
	info->type = Sphere;
	info->ref = sphere;
}
//(nx*dirx + ny*diry + nz*dirz) * t + nx*ax + ny*ay + nz*az = 0
void	plane_intersect(t_rt *rt, t_shape *plane, t_vec3 ray_dir,
	t_hitinfo *info)
{
	float	coeff[2];
	float	root;

	coeff[A] = ft_vec3_dot(plane->normal, ray_dir);
	coeff[B] = ft_vec3_dot(plane->normal, ft_vec3_sub(rt->scene.camera.pos,
		plane->pos));
	root = -coeff[B] / coeff[A];
	if (root < 0)
		return ;
	info->dist = root;
	info->point = ft_vec3_add(rt->scene.camera.pos, ft_vec3_mul(ray_dir, root));
	info->normal = plane->normal;
	info->color = plane->color;
	info->is_hit = true;
	info->type = Plane;
	info->ref = plane;
}

void	cylinder_intersect(t_rt *rt, t_shape *cylinder, t_vec3 ray_dir,
	t_hitinfo *info)
{
	float	coeff[3];
	float	disc;
	float	roots[2];
	t_vec3	pos;

	pos = ft_vec3_sub(rt->scene.camera.pos, cylinder->pos);
	coeff[A] = (ray_dir.x * ray_dir.x) + (ray_dir.y * ray_dir.y);
	coeff[B] = (2 * pos.x * ray_dir.x) + (2 * pos.y * ray_dir.y);
	coeff[C] = (pos.x * pos.x) + (pos.y * pos.y) - (cylinder->diameter * cylinder->diameter);
	disc = coeff[B] * coeff[B] - (4 * coeff[A] * coeff[C]);
	if (disc < 0)
		return ;
	roots[0] = (-coeff[B] + sqrt(disc)) / (2 * coeff[A]);
	roots[1] = (-coeff[B] - sqrt(disc)) / (2 * coeff[A]);
	info->dist = select_root(roots);
	if (info->dist < 0)
		return ;
	info->point = ft_vec3_add(rt->scene.camera.pos,
					ft_vec3_mul(ray_dir, info->dist));
	info->normal = g_vec3_i;
	info->color = cylinder->color;
	info->is_hit = true;
	info->type = Cylinder;
	info->ref = cylinder;
}

t_hitinfo	check_intersections(t_rt *rt, t_vec3 pos, t_vec3 ray_dir)
{
	t_hitinfo	info;
	t_hitinfo	temp;
	int			k;

	(void)pos;
	k = 0;
	ft_memset(&info, 0, sizeof(t_hitinfo));
	ft_memset(&temp, 0, sizeof(t_hitinfo));
	while (k < rt->scene.shapes->size)
	{
		((t_shape *)rt->scene.shapes->data)[k].intersect(rt,
			&((t_shape *)rt->scene.shapes->data)[k], ray_dir, &info);
		if (temp.dist > 0 && temp.dist < info.dist)
			info = temp;
		temp = info;
		k++;
	}
	k = 0;
	return (info);
}

void	calc_light(t_rt *rt, t_hitinfo *hitinfo)
{
	t_vec3	dir;
	float	angle;

	dir = ft_vec3_norm(ft_vec3_sub(rt->scene.light.pos, hitinfo->point));
	//printf("dir: %f, %f; point: %f, %f\n", dir.x, dir.y, hitinfo->point.x, hitinfo->point.y);
	t_hitinfo inf = check_intersections(rt, hitinfo->point, dir);
	if (!inf.is_hit)
	{
		angle = ft_vec3_dot(dir, hitinfo->normal);
		if (hitinfo->type == Plane)
		{
			hitinfo->normal = ft_vec3_mul(hitinfo->normal, -1);
			angle = ft_vec3_dot(dir, hitinfo->normal);
		}
		if (angle > rt->scene.ambient.strength)
		{
			hitinfo->color.r *= angle;
			hitinfo->color.g *= angle;
			hitinfo->color.b *= angle;
		}
		else
		{
			hitinfo->color.r *= rt->scene.ambient.strength;
			hitinfo->color.g *= rt->scene.ambient.strength;
			hitinfo->color.b *= rt->scene.ambient.strength;
		}
	}
	else
	{
		hitinfo->color.r *= rt->scene.ambient.strength;
		hitinfo->color.g *= rt->scene.ambient.strength;
		hitinfo->color.b *= rt->scene.ambient.strength;
	}
}

t_hitinfo	cast_ray(t_rt *rt, t_vec3 ray_dir, int i, int j)
{
	t_hitinfo	hitinfo;

	hitinfo = check_intersections(rt, rt->scene.camera.pos, ray_dir);
	if (hitinfo.is_hit)
	{
		calc_light(rt, &hitinfo);
		ft_put_pixel(&rt->mlx.img, i, j,
			hitinfo.color);
	}
	else
		ft_put_pixel(&rt->mlx.img, i, j,
			ft_set_color(255, 20, 40, 70));
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

