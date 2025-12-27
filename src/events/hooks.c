#include "fractol.h"

static int	on_destroy(t_app *app)
{
	app_destroy(app);
	exit(0);
	return (0);
}

static int	on_keydown(int keycode, t_app *app)
{
	if (keycode == XK_Escape)
		on_destroy(app);
	return (0);
}

int	init_hooks(t_app *app)
{
	mlx_hook(app->win, 17, 0, on_destroy, app); // X
	mlx_hook(app->win, 2, 1L << 0, on_keydown, app); // ESC
	return (0);
}
