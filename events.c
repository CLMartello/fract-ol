/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:36:08 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/02 16:01:11 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

//left click	1
//right click	2
//middle click	3
//scroll up	4
//scroll down	5

void	zoom(t_fractal *frac, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.5;
	if (zoom == 1)
	{
		frac->offset_x = (x / frac->zoom + frac->offset_x) - (x
				/ (frac->zoom * zoom_level));
		frac->offset_y = (y / frac->zoom + frac->offset_y) - (y
				/ (frac->zoom * zoom_level));
		frac->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		frac->offset_x = (x / frac->zoom + frac->offset_x) - (x
				/ (frac->zoom / zoom_level));
		frac->offset_y = (y / frac->zoom + frac->offset_y) - (y
				/ (frac->zoom / zoom_level));
		frac->zoom /= zoom_level;
	}
	else
		return ;
}



int	mouse_hook(int mouse_code, int x, int y, t_fractal *frac)
{
//	mlx_hook(frac->win, 17, 1L<<17, free_fractal, &frac);
	if (mouse_code == 4)
		zoom(frac, x, y, 1);
	else if (mouse_code == 5)
		zoom(frac, x, y, -1);
/*	else if (mouse_code == 1 && frac->type == 2)
	{
		frac->cy = x;
		frac->cy = y;
	}*/
	draw_fractal(frac, x, y);
	return (0);
}

//# define KEY_UP		65362
//# define KEY_DOWN		65364
//# define KEY_LEFT		65361
//# define KEY_RIGHT		65363

int	key_event(int key_code, t_fractal *frac)
{
	if (key_code == 65307)
	{
		free_fractal(frac);
		exit(1);
	}
	else if (key_code == 99)
	{
		frac->color = (255 * 255 * 255) / 100;
		draw_fractal(frac, 0, 0);
/*		int i = 1;
		while (i < 5)
		{
			frac->color = (255 * 255 * 255) / i;
			draw_fractal(frac, 0, 0);
			i++;
		}*/
//		draw_fractal(frac, 0, 0);
//tentando fazer o c funcionar infinitamente
//	        mlx_key_hook(frac->win, key_event, frac);
//		mlx_loop(frac->mlx);	
		mlx_loop_hook(frac->mlx, key_event, frac);
		mlx_loop(frac->mlx);	
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *frac);

int	expose_event(t_fractal *frac);
/*
int	events(t_fractal)
{
	mlx_loop(frac->mlx_ptr);
	mlx_key_hook(frac->win_ptr, (FUNCTION_KEY), frac);
	mlx_mouse_hook(frac->img_ptr, (FUNCTION_MOUSE), frac);
	mlx_expose_hook(frac->img_ptr, (FUNCTION_EXPOSE), frac);

}
*/
