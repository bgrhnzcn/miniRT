#include "minirt.h"

int take_all_lines(char **lines, char *path)
{
    char    *temp;
    char    *temp2;
    int     fd;
    int     i;

    i = -1;
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (printf("Cannot open given file.\n"), EXIT_FAILURE);
    temp = get_next_line(fd);
    temp2 = ft_strtrim(temp, " \t\n");
    while (temp)
    {
        if (temp2 && temp2[0] != '\0')
            lines[++i] = ft_strdup(temp2);
        free (temp);
        free (temp2);
        temp = get_next_line(fd);
        temp2 = ft_strtrim(temp, " \t\n");
    }
    if (close(fd) == -1)
        return (printf("Cannot close opened file.\n"), EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int size_of_file(int fd)
{
    char    *temp;
    char    *temp2;
    int     i;

    i = 0;
    temp = get_next_line(fd);
    temp2 = ft_strtrim(temp, " \t\n");
    while (temp)
    {
        if (temp2 && temp2[0] != '\0')
            i++;
        free (temp);
        free (temp2);
        temp = get_next_line(fd);
        temp2 = ft_strtrim(temp, " \t\n");
    }
    return (i);
}

int control_extension(char *path)
{
    char    *temp;

    temp = ft_strrchr(path, '.');
    if (ft_strlen(temp) == 3 && temp[1] == 'r' && temp[2] == 't')
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}

int read_rt(char *path)
{
    t_parse parse;
    int     line_count;
    int     fd;

    parse.scene_path = path;
    fd = open(parse.scene_path, O_RDONLY);
    if (fd == -1)
        return (printf("Cannot open given file.\n"), EXIT_FAILURE);
    line_count = size_of_file(fd);
    if (line_count < 3) //birden fazla type identifier'ın aynı satırda olmayacağını varsayıyorum.
        return (printf("Scene file must contain at least 3 line.\n"), EXIT_FAILURE);
    parse.scene_file = malloc((line_count + 1) * sizeof(char *));
    if (!parse.scene_file)
        perror("Malloc!\n");
    parse.scene_file[line_count] = NULL;
    if (close(fd) == -1)
        return (printf("Cannot close opened file.\n"), EXIT_FAILURE);
    if (take_all_lines(parse.scene_file, path))
        return (EXIT_FAILURE);
    if (take_values(&parse))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}