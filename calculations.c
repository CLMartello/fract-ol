/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:56:36 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/30 21:05:00 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

void    calc_mandelbrot(t_fractal *fractal)
{
        int     i;
        double  temp;

        fractal->name = "mandelbrot";
        i = 0;
        fractal->zx = 0.0;
        fractal->zy = 0.0;
        fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
        fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
        while (++i < fractal->max_iterations)
        {
                temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
                fractal->zy = 2.0 * fractal->zx * fractal->zy + fractal->cy;
                fractal->zx = temp;
                if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= __DBL_MAX__)
                        break ;
        }
        if (i == fractal->max_iterations)
                color_pixel(fractal, fractal->x, fractal->y, 0x000000);
        else
                color_pixel(fractal, fractal->x, fractal->y, (0x99004C * i));
}

void    calc_julia(t_fractal *fractal, double cx, double cy)
{
        int     i;
        double  temp;

        fractal->name = "julia";
        fractal->cx = cx;
        fractal->cy = cy;
        fractal->zx = (fractal->x / fractal->zoom) + fractal->offset_x;
        fractal->zy = (fractal->y / fractal->zoom) + fractal->offset_y;
        i = 0;
        while (++i < fractal->max_iterations)
        {
                temp = fractal->zx;
                fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
                fractal->zy = 2 * fractal->zy * temp * fractal->cy;
                if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= __DBL_MAX__)
                        break ;
        }
        if (i == fractal->max_iterations)
                color_pixel(fractal, fractal->x, fractal->y, 0x000000);
        else
                color_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i % 255)));
}

