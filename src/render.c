/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:11:29 by pedrferr          #+#    #+#             */
/*   Updated: 2026/01/25 13:11:34 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_fractal(t_app *app)
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
			if (app->fractal.type == MANDELBROT)
				i = mandelbrot_iter(c, app->render_iter);
			else
				i = julia_iter(c, app->fractal.julia_k, app->render_iter);
			put_pixel(&app->img, x, y,
				color_from_iter(i, app->render_iter));
			x++;
		}
		y++;
	}
}

int	redraw(t_app *app)
{
	draw_fractal(app);
	mlx_put_image_to_window(app->mlx, app->win, app->img.img, 0, 0);
	return (0);
}

void	apply_zoom(t_app *app, t_complex center, double factor)
{
	double	w;
	double	h;

	w = (app->view.max_re - app->view.min_re) * factor;
	h = (app->view.max_im - app->view.min_im) * factor;
	app->view.min_re = center.re - (w / 2.0);
	app->view.max_re = center.re + (w / 2.0);
	app->view.min_im = center.im - (h / 2.0);
	app->view.max_im = center.im + (h / 2.0);
}
