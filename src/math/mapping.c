#include "fractol.h"

t_complex	pixel_to_complex(int x, int y, t_app *app)
{
	t_complex	c;
	double		x_percent;
	double		y_percent;

	x_percent = (double)x / (double)(app->img.width - 1);
	y_percent = (double)y / (double)(app->img.height - 1);
	c.re = app->view.min_re + x_percent * (app->view.max_re - app->view.min_re);
	c.im = app->view.max_im - y_percent * (app->view.max_im - app->view.min_im);
	return (c);
}
