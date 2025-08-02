/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:06:44 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/02 17:40:07 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

int	draw_fractal(t_fractal *frac, double cx, double cy)
{
	frac->x = 0;
	frac->y = 0;
	if (frac->type == 2)
	{
		frac->c.x = cx;
		frac->c.y = cy;
	}
	while (frac->x < WIDTH)
	{
		while (frac->y < HEIGHT)
		{
			choose_mandelbrot_julia(frac);
			frac->y++;
		}
		frac->x++;
		frac->y = 0;
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
	return (0);
}

void	color_pixel(t_fractal *frac, int x, int y, int color)
{
	char	*destiny;

	destiny = frac->data.addr + (y * frac->data.size_line
			+ x * (frac->data.bits_per_pixel / 8));
	*(unsigned int *)destiny = color;
}
