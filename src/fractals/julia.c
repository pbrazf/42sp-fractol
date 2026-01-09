#include "fractol.h"

int	julia_iter(t_complex z0, t_complex k, int max_iter)
{
	t_complex	z;
	int			i;

	i = 0;
	z = z0;
	while (i < max_iter && complex_abs2(z) <= 4)
	{
		z = complex_square(z);
		z = complex_add(z, k);
		i++;
	}
	return (i);
}
