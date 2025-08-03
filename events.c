/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:36:08 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/03 19:52:41 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

int	key_event(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		free_fractal(fractal);
	if (key_code == RIGHT)
		fractal->event.move_x += (0.5 * fractal->event.zoom);
	if (key_code == LEFT)
		fractal->event.move_x += (-0.5 * fractal->event.zoom);
	if (key_code == UP)
		fractal->event.move_y += (0.5 * fractal->event.zoom);
	if (key_code == DOWN)
		fractal->event.move_y += (-0.5 * fractal->event.zoom);
	if (key_code == 99)
		fractal->color -= 1000000;
	if (key_code == 106)
		julia_generator(fractal, 1);
	draw_fractal(fractal);
	return (0);
}

void	zoom(int button, int x, int y, t_fractal *fractal)
{
	double	re_math;
	double	im_math;

	re_math = (resize(2, -2, x, WIDTH) * fractal->event.zoom)
		+ fractal->event.move_x;
	im_math = (resize(-2, 2, y, HEIGHT) * fractal->event.zoom)
		+ fractal->event.move_y;
	if (button == SCROLL_UP)
		fractal->event.zoom *= 0.9;
	if (button == SCROLL_DOWN)
		fractal->event.zoom *= 1.1;
	fractal->event.move_x = re_math - resize(2, -2, x, WIDTH)
		* fractal->event.zoom;
	fractal->event.move_y = im_math - resize(-2, 2, y, HEIGHT)
		* fractal->event.zoom;
}

int	mouse_event(int mouse_code, int x, int y, t_fractal *fractal)
{
	if ((mouse_code == SCROLL_UP && mouse_code >= 1.0e-9)
		|| (mouse_code == SCROLL_DOWN && mouse_code <= 5))
		zoom(mouse_code, x, y, fractal);
	if (fractal->type == 2 && mouse_code == LEFT_CLICK)
	{
		fractal->c.re = (resize(2, -2, x, WIDTH)
				+ fractal->event.zoom) + fractal->event.move_x;
		fractal->c.im = (resize(-2, 2, y, HEIGHT)
				+ fractal->event.zoom) + fractal->event.move_y;
	}
	draw_fractal(fractal);
	return (0);
}

void	julia_generator(t_fractal *fractal, int j)
{
	static int	i;

	i += j;
	if (i == 5)
		i = 1;
	if (i == 1)
	{
		fractal->c.re = -0.5125;
		fractal->c.im = +0.5213;
	}
	if (i == 2)
	{
		fractal->c.re = -0.8;
		fractal->c.im = +0.156;
	}
	if (i == 3)
	{
		fractal->c.re = 0.35;
		fractal->c.im = 0.35;
	}
	if (i == 4)
	{
		fractal->c.re = +0.285;
		fractal->c.im = 0.0;
	}
}
