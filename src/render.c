#include "fractol.h"

static void	draw_mandelbrot(t_app *app)
{
	int			x;
	int			y;
	t_complex	c;
	int			i;

	y = 0;
	while (y < app->img.height)
	{
		x = 0;
		while (x < app->img.width)
		{
			c = pixel_to_complex(x, y, app);
			i = mandelbrot_iter(c, app->fractal.max_iter);
			put_pixel(&app->img, x, y,
				color_from_iter(i, app->fractal.max_iter));
			x++;
		}
		y++;
	}
}

void	render(t_app *app)
{
	draw_mandelbrot(app);
	mlx_put_image_to_window(app->mlx, app->win, app->img.img, 0, 0);
}
