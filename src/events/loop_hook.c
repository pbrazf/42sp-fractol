#include "fractol.h"

int	loop_hook(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (!app->needs_redraw)
		return (0);
	app->needs_redraw = 0;
	redraw(app);
	if (app->refine && app->render_iter != app->fractal.max_iter)
	{
		app->render_iter = app->fractal.max_iter;
		app->refine = 0;
		app->needs_redraw = 1;
	}
	return (0);
}

