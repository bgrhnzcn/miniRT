#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <mlx.h>
# include <libft.h>
# include <get_next_line.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

//parse

typedef struct s_camera
{
	t_vec3	position; // x, y, z
	t_vec3	orientation; // x, y, z normalized
	float	fov; // [0, 180]
}	t_camera;

typedef struct s_ambient
{
	float strength; // [0.0, 1.0]
	t_color color; // A:[0, 0] R:[0, 255] G:[0, 255] B:[0, 255]
}

typedef struct s_light
{
	t_vec3	position; // x, y, z
	float	brightness; // [0.0, 1.0]
	t_color color; // A:[0, 0] R:[0, 255] G:[0, 255] B:[0, 255]
}	t_light;

typedef struct sphere
{
	t_vec3	position; // x, y, z
	float	radius; // > 0
	t_color	color; // A:[0, 0] R:[0, 255] G:[0, 255] B:[0, 255]
}	t_sphere;

typedef struct s_plane
{
	t_vec3	position; // x, y, z
	t_vec3	normal; // x, y, z normalized
	t_color	color; // A:[0, 0] R:[0, 255] G:[0, 255] B:[0, 255]
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	position; // x, y, z
	t_vec3	orientation; // x, y, z normalized
	float	diameter; // > 0
	float	height; // > 0
	t_color	color; // A:[0, 0] R:[0, 255] G:[0, 255] B:[0, 255]
}	t_cylinder;

typedef struct s_parse
{
	char		**scene_file;
	char		*scene_path;
}	t_parse;

int     control_extension(char *path);
int     read_rt(char *path);
int		take_values(t_parse *parse);
int		string_compare(char *str, char *str1);
int		count_dpointer(char **str);

#endif