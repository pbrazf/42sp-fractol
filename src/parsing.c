/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:35:51 by pedrferr          #+#    #+#             */
/*   Updated: 2025/12/14 18:35:54 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	parse_decimal(char **s)
{
	double	decimal;
	double	div;

	decimal = 0.0;
	div = 1.0;
	while (**s && (**s >= '0' && **s <= '9'))
	{
		decimal = decimal * 10 + (**s - '0');
		div *= 10;
		(*s)++;
	}
	return (decimal / div);
}

static double	parse_int_part(char **s, int *sign, int *has_digit)
{
	double	result;

	result = 0.0;
	*sign = 1;
	*has_digit = 0;
	while (**s && (**s == ' ' || (**s >= 9 && **s <= 13)))
		(*s)++;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*sign = -1;
		(*s)++;
	}
	while (**s && (**s >= '0' && **s <= '9'))
	{
		*has_digit = 1;
		result = result * 10 + (**s - '0');
		(*s)++;
	}
	return (result);
}

static int	parse_double(char *s, double *out)
{
	double	result;
	int		sign;
	int		has_digit;

	result = parse_int_part(&s, &sign, &has_digit);
	if (*s == '.')
	{
		s++;
		result += parse_decimal(&s);
		has_digit = 1;
	}
	while (*s && (*s == ' ' || (*s >= 9 && *s <= 13)))
		s++;
	if (*s != '\0' || !has_digit)
		return (0);
	*out = result * sign;
	return (1);
}

int	validate_args(int argc, char **argv, t_app *app)
{
	double	re;
	double	im;

	if (argc != 2 && argc != 4)
		return (0);
	if (!ft_strcmp(argv[1], "julia")
		&& !ft_strcmp(argv[1], "mandelbrot"))
		return (0);
	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "mandelbrot"))
			return (0);
		app->fractal.type = MANDELBROT;
		return (1);
	}
	if (!parse_double(argv[2], &re) || !parse_double(argv[3], &im))
		return (0);
	app->fractal.type = JULIA;
	app->fractal.julia_k.re = re;
	app->fractal.julia_k.im = im;
	return (1);
}
