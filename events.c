/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:36:08 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/31 21:13:27 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

int	ft_close(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	return (0);
}

void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == 4)
		zoom(fractal, x, y, 1);
	else if (mouse_code == 5)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, x, y);
	return (0);
}

int	key_event(int key_code, t_fractal *fractal)
{
	if (key_code == 65307)
	{
		exit(1);
//	mlx_hook(fractal->win_ptr, 2, 1L<<0, ft_close, &fractal);
		mlx_key_hook(fractal->win_ptr, ft_close, fractal);
//	mlx_loop(&fractal->win_ptr);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal);

int	expose_event(t_fractal *fractal);
/*
int	events(t_fractal)
{
	mlx_loop(fractal->mlx_ptr);
	mlx_key_hook(fractal->win_ptr, (FUNCTION_KEY), fractal);
	mlx_mouse_hook(fractal->img_ptr, (FUNCTION_MOUSE), fractal);
	mlx_expose_hook(fractal->img_ptr, (FUNCTION_EXPOSE), fractal);

}

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_loop(vars.mlx);
}
*/
