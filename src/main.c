#include "minirt.h"

int main(int ac, char *av[])
{
	t_rt	rt;

	if (ac != 2)
		return (printf("./miniRT <path-to-scene>\n"));
	else if (control_extension(av[1]) == EXIT_FAILURE)
		return (printf("Extension of scene file must be '.rt' format.\n"));
	read_rt(av[1]);
	if (init_display(&rt.mlx))
		return (printf("Failed to initialize display.\n"));
	mlx_hook(rt.mlx.win.win, 17, 0, terminate_program, &rt);
	mlx_loop_hook(rt.mlx.mlx, update_frame, &rt);
	mlx_loop(rt.mlx.mlx);
}
