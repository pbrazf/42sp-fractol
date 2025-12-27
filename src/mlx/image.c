#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		bytespp;

	if (!img || !img->addr)
		return ;
	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	bytespp = img->bpp / 8;
	dst = img->addr + (y * img->line_len + x * bytespp);
	*(unsigned int *)dst = color;
}

int	color_from_iter(int i, int max)
{
	int	t;

	if (i >= max)
		return (0x000000);
	t = (i * 255) / max;
	return ((t << 16) | ((255 - t) << 8) | t);
}