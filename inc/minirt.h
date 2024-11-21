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