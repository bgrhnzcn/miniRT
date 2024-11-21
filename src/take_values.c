#include "minirt.h"

int control_name(char **line)
{
    if (!string_compare(line[0], "A") && count_dpointer(line) == 3)
        printf("Name: %s\n", line[0]);
    else if (!string_compare(line[0], "C") && count_dpointer(line) == 4)
        printf("Name: %s\n", line[0]);
    else if (!string_compare(line[0], "L") && count_dpointer(line) == 4)
        printf("Name: %s\n", line[0]);
    else if (!string_compare(line[0], "pl") && count_dpointer(line) == 4)
        printf("Name: %s\n", line[0]);
    else if (!string_compare(line[0], "sp") && count_dpointer(line) == 4)
        printf("Name: %s\n", line[0]);
    else if (!string_compare(line[0], "cy") && count_dpointer(line) == 6)
        printf("Name: %s\n", line[0]);
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
        control_name(line);
    }
    return (EXIT_SUCCESS);
}