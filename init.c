/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:25:35 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/10 11:21:12 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

void	initial_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->z.re = 0.0;
	fractal->z.im = 0.0;
	fractal->c.re = 0.4;
	fractal->c.im = 0.4;
	fractal->max_iterations = 100;
	fractal->color = 0x66FFB2;
	fractal->event.move_x = 0.0;
	fractal->event.move_y = 0.0;
	fractal->event.zoom = 1.0;
	fractal->event.off_x = 0.0;
	fractal->event.off_y = 0.0;
	initial_mlx(fractal);
}

void	initial_mlx(t_fractal *frac)
{
	frac->mlx_ptr = mlx_init();
	if (!frac->mlx_ptr)
		free_fractal(frac);
	frac->win_ptr = mlx_new_window(frac->mlx_ptr, WIDTH, HEIGHT, frac->name);
	if (!frac->win_ptr)
		free_fractal(frac);
	frac->image.img_ptr = mlx_new_image(frac->mlx_ptr, WIDTH, HEIGHT);
	if (!frac->image.img_ptr)
		free_fractal(frac);
	frac->image.addr = mlx_get_data_addr(frac->image.img_ptr,
			&frac->image.bits_per_pixel,
			&frac->image.size_line,
			&frac->image.endian);
}

void	initial_events(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr, 2, 1L << 0, key_event, fractal);
	mlx_hook(fractal->win_ptr, 4, 1L << 2, mouse_event, fractal);
	mlx_hook(fractal->win_ptr, 17, 1L << 17, free_fractal, fractal);
}
