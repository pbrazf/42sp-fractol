/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:12:58 by pedrferr          #+#    #+#             */
/*   Updated: 2026/01/25 13:12:59 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	complex_square(t_complex z)
{
	t_complex	square;
	double		x;
	double		y;

	x = z.re;
	y = z.im;
	square.re = (x * x) - (y * y);
	square.im = 2 * x * y;
	return (square);
}

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	sum;

	sum.re = a.re + b.re;
	sum.im = a.im + b.im;
	return (sum);
}

double	complex_abs2(t_complex z)
{
	double		square;

	square = (z.re * z.re) + (z.im * z.im);
	return (square);
}
