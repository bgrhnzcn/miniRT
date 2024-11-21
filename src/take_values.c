#include "minirt.h"

int control_name(t_parse *parse, char **line)
{
    if ((!string_compare(line[0], "A") && parse->ambient)
    || (!string_compare(line[0], "C") && parse->camera)
    || (!string_compare(line[0], "L") && parse->light))
        return (printf("File must contain only one value each of A, C and L\n"));
    if (!string_compare(line[0], "A") && count_dpointer(line) == 3)
    {
        printf("Name: %s\n", line[0]);
        parse->ambient = malloc(sizeof(t_ambient));
        parse->ambient->strength = ft_atoi(line[1]);
        parse->ambient->color.alpha = ft_atoi("255");
        char **rgb = ft_split(line[2], ',');
        parse->ambient->color.red = ft_atoi(rgb[0]);
        parse->ambient->color.green = ft_atoi(rgb[1]);
        parse->ambient->color.blue = ft_atoi(rgb[2]);
        printf("rgb: %u, %u, %u\n", parse->ambient->color.red, parse->ambient->color.green, parse->ambient->color.blue);
    }
    else if (!string_compare(line[0], "C") && count_dpointer(line) == 4)
    {
        printf("Name: %s\n", line[0]);
        parse->camera = malloc(sizeof(t_camera));
    }
    else if (!string_compare(line[0], "L") && count_dpointer(line) == 4)
    {
        printf("Name: %s\n", line[0]);
        parse->light = malloc(sizeof(t_light));
    }
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
    parse->ambient = NULL;
    parse->light = NULL;
    parse->camera = NULL;
    while (parse->scene_file[++i])
    {
        line = ft_split(parse->scene_file[i], ' ');
        if (control_name(parse, line))
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}