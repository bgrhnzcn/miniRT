#include "minirt.h"

int control_name(char *str)
{
    //if (!string_compare(str, "A"))
    //else if (!string_compare(str, "C"))
    //else if (!string_compare(str, "L"))
    //else if (!string_compare(str, "pl"))
    //else if (!string_compare(str, "sp"))
    //else if (!string_compare(str, "cy"))
    return (EXIT_SUCCESS);
}

int take_values(t_parse *parse)
{
    char    **line;
    int     i;

    i = -1;
    while (parse->scene_file[++i])
    {
        line = ft_split(parse->scene_file[i], ' ');
        control_name(line[0]);
    }
    return (EXIT_SUCCESS);
}