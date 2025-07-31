/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:25:35 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/30 21:04:36 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

void	initial_fractal(t_fractal *fractal)
{
	
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0x66FFB2;
	fractal->zoom = 200;
	fractal->offset_x = -2.5;
	fractal->offset_y = -1.5;
//	fractal->offset_x = 0.0;
//	fractal->offset_y = 0.0;
	fractal->max_iterations = 200;
	
}

void	initial_mlx(t_fractal *fractal)
{
        fractal->mlx_ptr = mlx_init();
//        if (!fractal->mlx_ptr)
//                free_fractal(fractal);
        fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
//        if (!fractal->win_ptr)
//                free_fractal(fractal);
	fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
//        if (!fractal->img_ptr)
//                free_fractal(fractal);
        fractal->data.addr = mlx_get_data_addr(fractal->img_ptr, &fractal->data.bits_per_pixel, &fractal->data.size_line, &fractal->data.endian);
}
