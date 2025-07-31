/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:06:44 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/30 20:59:12 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

int	draw_fractal(t_fractal *fractal, double cx, double cy)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < WIDTH)
	{
		while (fractal->y < HEIGHT)
		{
			if (fractal->type == 1)
				calc_mandelbrot(fractal);
			else if (fractal->type == 2)
				calc_julia(fractal, cx, cy);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img_ptr, 0, 0);
	return (0);
}

void	color_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*destiny;
	
	destiny = fractal->data.addr + (y * fractal->data.size_line + x * (fractal->data.bits_per_pixel / 8));
	*(unsigned int *)destiny = color;
}

