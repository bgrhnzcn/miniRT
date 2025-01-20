#include "minirt.h"

t_vec3	vec_rot_around(t_vec3 vec, t_vec3 axis, float angle)
{
	t_vec3	res;
	float	rad;

	rad = ft_deg_to_rad(angle);
	res = ft_vec3_add(ft_vec3_add(ft_vec3_mul(vec, cos(rad)), ft_vec3_mul(
			ft_vec3_cross(axis, vec), sin(rad))), ft_vec3_mul(
				   axis, ft_vec3_dot(axis, vec) * (1 - cos(rad))));
	return (res);
}

void	ft_ftoa(float value, char *buffer, int decimal)
{
	
}
