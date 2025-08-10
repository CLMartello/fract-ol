/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:56:36 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/10 11:20:50 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

void	calc_mandelbrot_julia(t_fractal *fractal)
{
	int		i;
	double	temp;

	i = 0;
	while (++i < fractal->max_iterations)
	{
		temp = (fractal->z.re * fractal->z.re) - (fractal->z.im * fractal->z.im)
			+ fractal->c.re;
		fractal->z.im = 2.0 * fractal->z.re * fractal->z.im + fractal->c.im;
		fractal->z.re = temp;
		if ((fractal->z.re * fractal->z.re)
			+ (fractal->z.im * fractal->z.im) > 4)
			break ;
	}
	if (i == fractal->max_iterations)
		color_pixel(fractal, fractal->x, fractal->y, (0x000000));
	else
	{
		color_pixel(fractal, fractal->x, fractal->y, (fractal->color * i));
	}
}

double	resize(double new_max, double new_min, double nbr, double old_max)
{
	double	value;

	value = (new_max - new_min) * (nbr) / old_max + new_min;
	return (value);
}

void	choose_mandelbrot_julia(t_fractal *fractal)
{
	if (fractal->type == 1)
	{
		fractal->z.re = 0.0;
		fractal->z.im = 0.0;
		fractal->c.re = (resize(2, -2, fractal->x, WIDTH)
				* fractal->event.zoom) + fractal->event.move_x;
		fractal->c.im = (resize(-2, 2, fractal->y, HEIGHT)
				* fractal->event.zoom) + fractal->event.move_y;
	}
	else if (fractal->type == 2)
	{
		fractal->z.re = (resize(2, -2, fractal->x, WIDTH)
				* fractal->event.zoom) + fractal->event.move_x;
		fractal->z.im = (resize(-2, 2, fractal->y, HEIGHT)
				* fractal->event.zoom) + fractal->event.move_y;
	}
	calc_mandelbrot_julia(fractal);
}

void	calc_tricorn(t_fractal *fractal)
{
	int		i;
	double	temp;

	i = 0;
	fractal->z.re = 0.0;
	fractal->z.im = 0.0;
	fractal->c.re = (resize(2, -2, fractal->x, WIDTH)
			* fractal->event.zoom) + fractal->event.move_x;
	fractal->c.im = (resize(-2, 2, fractal->y, HEIGHT)
			* fractal->event.zoom) + fractal->event.move_y;
	while (++i < fractal->max_iterations)
	{
		temp = fractal->z.re * fractal->z.re - fractal->z.im
			* fractal->z.im + fractal->c.re;
		fractal->z.im = -2.0 * fractal->z.re * fractal->z.im + fractal->c.im;
		fractal->z.re = temp;
		if ((fractal->z.re * fractal->z.re + fractal->z.im * fractal->z.im) > 4)
			break ;
	}
	if (i == fractal->max_iterations)
		color_pixel(fractal, fractal->x, fractal->y, (0x000000));
	else
		color_pixel(fractal, fractal->x, fractal->y, (fractal->color * i));
}
