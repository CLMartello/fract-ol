/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:06:44 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/04 21:26:53 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

int	draw_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < WIDTH)
	{
		while (fractal->y < HEIGHT)
		{
			if (fractal->type == 1 || fractal->type == 2)
				choose_mandelbrot_julia(fractal);
			if (fractal->type == 3)
				calc_tricorn(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->image.img_ptr, 0, 0);
	return (0);
}

void	color_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*destiny;

	destiny = fractal->image.addr + (y * fractal->image.size_line
			+ x * (fractal->image.bits_per_pixel / 8));
	*(unsigned int *)destiny = color;
}
