#include "fractol.h"

/*
c
- ponto fixo
- veio do pixel
- não muda

z
- estado atual do cálculo
- é um t_complex
- começa em (0, 0)

i
- contador de iterações
- começa em 0
- incrementa a cada loop
*/

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
