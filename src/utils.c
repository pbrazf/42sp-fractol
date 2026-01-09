#include "fractol.h"

int	exit_error()
{
	write(1, "Usage: ./fractol mandelbrot || ./fractol julia <re> <im>\n", 57);
	return (-1);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
