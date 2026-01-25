#include "fractol.h"

static int	init_window(t_app *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		return (1);
	app->win = mlx_new_window(app->mlx, app->img.width,
			app->img.height, "fract-ol");
	if (!app->win)
		return (1);
	return (0);
}

static int	init_image(t_app *app)
{
	app->img.img = mlx_new_image(app->mlx, app->img.width, app->img.height);
	if (!app->img.img)
		return (1);
	app->img.addr = mlx_get_data_addr(app->img.img, &app->img.bpp,
			&app->img.line_len, &app->img.endian);
	if (!app->img.addr)
		return (1);
	return (0);
}

void	app_set_defaults(t_app *app)
{
	app->img.width = WIDTH;
	app->img.height = HEIGHT;
	// app->fractal.max_iter = 80;
	app->view.min_re = -2.0;
	app->view.max_re = 1.0;
	app->view.min_im = -1.5;
	app->view.max_im = 1.5;

	app->fractal.max_iter = 200;     /* exemplo de qualidade final */
	app->render_iter = 80;           /* preview rápido */
	app->refine = 0;
	app->needs_redraw = 1;
}

void	app_destroy(t_app *app)
{
	if (app->mlx && app->img.img)
	{
		mlx_destroy_image(app->mlx, app->img.img);
		app->img.img = NULL;
		app->img.addr = NULL;
	}
	if (app->mlx && app->win)
	{
		mlx_destroy_window(app->mlx, app->win);
		app->win = NULL;
	}
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
	app->mlx = NULL;
}

int	app_init_mlx(t_app *app)
{
	if (init_window(app) != 0)
	{
		app_destroy(app);
		return (1);
	}
	if (init_image(app) != 0)
	{
		app_destroy(app);
		return (1);
	}
	return (0);
}
