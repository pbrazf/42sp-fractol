/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:14:20 by pedrferr          #+#    #+#             */
/*   Updated: 2026/01/25 13:14:21 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	on_expose(t_app *app)
{
	app->needs_redraw = 1;
	return (0);
}

int	on_mouse(int button, int x, int y, t_app *app)
{
	t_complex	center;
	double		factor;

	(void)x;
	(void)y;
	if (button != 4 && button != 5)
		return (0);
	factor = 1.10;
	if (button == 4)
		factor = 0.90;
	center.re = (app->view.min_re + app->view.max_re) / 2.0;
	center.im = (app->view.min_im + app->view.max_im) / 2.0;
	apply_zoom(app, center, factor);
	app->render_iter = 60;
	if (app->render_iter > app->fractal.max_iter)
		app->render_iter = app->fractal.max_iter;
	app->refine = 0;
	app->needs_redraw = 1;
	return (0);
}

int	init_hooks(t_app *app)
{
	mlx_hook(app->win, 17, 0, on_destroy, app);
	mlx_hook(app->win, 2, 1L << 0, on_keydown, app);
	mlx_mouse_hook(app->win, on_mouse, app);
	mlx_hook(app->win, 12, 1L << 15, on_expose, app);
	mlx_loop_hook(app->mlx, loop_hook, app);
	return (0);
}
