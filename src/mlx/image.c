/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 13:12:35 by pedrferr          #+#    #+#             */
/*   Updated: 2026/01/25 13:12:36 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	static const int	pal[] = {
		0x421E0F, 0x19071A, 0x09012F, 0x040449,
		0x000764, 0x0C2C8A, 0x1852B1, 0x397DD1,
		0x86B5E5, 0xD3ECF8, 0xF1E9BF, 0xF8C95F,
		0xFFAA00, 0xCC8000, 0x995700, 0x6A3403
	};
	int					idx;

	if (i >= max)
		return (0x000000);
	idx = i % (int)(sizeof(pal) / sizeof(pal[0]));
	return (pal[idx]);
}
