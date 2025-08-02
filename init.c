/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:25:35 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/02 18:23:45 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

int	initial_number(t_fractal *frac)
{
	t_number	*z;
	t_number	*c;

	z = malloc(sizeof(t_number));
	if (!z)
	{
		free_fractal(frac);
		return (0);
	}
	c = malloc(sizeof(t_number));
	if (!c)
	{
		free_fractal(frac);
		return (0);
	}
	frac->z = *z;
	frac->c = *c;
	return (0);
}

void	initial_fractal(t_fractal *frac)
{
	initial_number(frac);
	frac->x = 0;
	frac->y = 0;
	frac->color = 0x66FFB2;
	frac->zoom = 0;
//	frac->offset_x = -2.5;
//	frac->offset_y = -1.5;
	frac->max_iterations = iterations;
	frac->z.x = 0.0;
	frac->z.y = 0.0;
	frac->c.x = 0.0;
	frac->c.y = 0.0;
	
	initial_mlx(frac);
}

void	initial_mlx(t_fractal *frac)
{
	frac->mlx = mlx_init();
	if (!frac->mlx)
		free_fractal(frac);
	frac->win = mlx_new_window(frac->mlx, WIDTH, HEIGHT, frac->name);
	if (!frac->win)
		free_fractal(frac);
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	if (!frac->img)
		free_fractal(frac);
	frac->data.addr = mlx_get_data_addr(frac->img,
			&frac->data.bits_per_pixel,
			&frac->data.size_line,
			&frac->data.endian);
}
