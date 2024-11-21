#include "minirt.h"

int main(int ac, char *av[])
{
    if (ac != 2)
        return (printf("./miniRT <path-to-scene>\n"));
    else if (control_extension(av[1]) == EXIT_FAILURE)
        return (printf("Extension of scene file must be '.rt' format.\n"));
    read_rt(av[1]);
}