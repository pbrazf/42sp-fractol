/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:13:35 by pedrferr          #+#    #+#             */
/*   Updated: 2026/01/25 13:13:38 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(t_complex c, int max_iter)
{
	t_complex	z;
	int			i;

	i = 0;
	z.im = 0;
	z.re = 0;
	while (i < max_iter && complex_abs2(z) <= 4)
	{
		z = complex_square(z);
		z = complex_add(z, c);
		i++;
	}
	return (i);
}
