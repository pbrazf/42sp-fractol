/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:11:07 by pedrferr          #+#    #+#             */
/*   Updated: 2026/01/25 13:11:12 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	mlx_loop(app.mlx);
	return (0);
}
