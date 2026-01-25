/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:14:27 by pedrferr          #+#    #+#             */
/*   Updated: 2026/01/25 13:14:28 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
