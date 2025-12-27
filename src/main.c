#include "fractol.h"

int	main(int argc, char **argv)
{
	t_app	app;

	app.mlx = NULL;
	app.win = NULL;
	app.img.img = NULL;
	app.img.addr = NULL; // Pointer to the win
	if (!validate_args(argc, argv, &app))
		return (exit_error());
	app.img.width = WIDTH;
	app.img.height = HEIGHT;
	if (app_init_mlx(&app))
		return (exit_error());
	app_set_defaults(&app);
	init_hooks(&app);
	render(&app);
	mlx_loop(app.mlx);
	return (0);
}
