/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:56:36 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/02 18:28:10 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

void	calc_mandelbrot_julia(t_fractal *frac)
{
	int		i;
	double	temp;

	i = 0;
	while (++i < frac->max_iterations)
	{
		temp = (frac->z.x * frac->z.x) - (frac->z.y * frac->z.y) + frac->c.x;
		frac->z.y = 2.0 * frac->z.x * frac->z.y + frac->c.y;
		frac->z.x = temp;
//		if ((frac->z.x * frac->z.x) + (frac->z.y * frac->z.y) >= __DBL_MAX__)
		if ((frac->z.x * frac->z.x) + (frac->z.y * frac->z.y) > 4)
			break ;
	}
	if (i == frac->max_iterations)
		color_pixel(frac, frac->x, frac->y, (0x000000));
	else
	{
		frac->color = resize(new_xmax, new_xmin, i, old_xmax);
		color_pixel(frac, frac->x, frac->y, (frac->color * i));
	}
}

double	resize(double new_max, double new_min, double actual_nbr, double old_max)
{
	double	value;

	value = (new_max - new_min) * (actual_nbr) / old_max + new_min;
	return (value);
}

void	choose_mandelbrot_julia(t_fractal *frac)
{
	if (frac->type == 1)
	{
//		frac->name = "mandelbrot";
		frac->z.x = 0.0;
		frac->z.y = 0.0;
//		frac->c.x = (frac->x / frac->zoom) + frac->offset_x;
//		frac->c.y = (frac->y / frac->zoom) + frac->offset_y;
		frac->c.x = resize(new_xmax, new_xmin, frac->x, old_xmax);
		frac->c.y = resize(new_xmax, new_xmin, frac->y, old_xmax);
	}
	else if (frac->type == 2)
	{
//		frac->cx = 1.1;
//		frac->cy = 0;
//		frac->name = "julia";
		frac->z.x = (frac->x / frac->zoom) + frac->offset_x;
		frac->z.y = (frac->y / frac->zoom) + frac->offset_y;
	}
	calc_mandelbrot_julia(frac);
}
