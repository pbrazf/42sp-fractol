#include "fractol.h"

static int	on_loop(t_app *app)
{
	static int	done;

	if (done)
		return (0);
	done = 1;
	redraw(app);
	return (0);
}

int	main(int argc, char **argv)
{
	t_app	app;

	app.mlx = NULL;
	app.win = NULL;
	app.img.img = NULL;
	app.img.addr = NULL;
	if (!validate_args(argc, argv, &app))
		return (exit_error());
	app.img.width = WIDTH;
	app.img.height = HEIGHT;
	if (app_init_mlx(&app))
		return (exit_error());
	app_set_defaults(&app);
	init_hooks(&app);

	mlx_loop_hook(app.mlx, on_loop, &app);
	mlx_loop(app.mlx);
	return (0);
}
