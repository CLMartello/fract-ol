/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:35:55 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/31 21:15:26 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

void	free_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	free(fractal->mlx_ptr);
	free(fractal);
}

int	fractal_type(char *name)
{
	if (((ft_strcmp(name, "mandelbrot")) == 0))
		return (1);
	else if (((ft_strcmp(name, "julia")) == 0))
		return (2);
	else
	{
		write(1, "Choose one fractal: mandelbrot or julia\n", 40);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_fractal	*fractal;
	double	cx;
	double	cy;

	if (argc == 1 || argc > 2)
	{
		write(1, "Choose one fractal: mandelbrot or julia\n", 40);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (0);
	fractal->type = fractal_type(argv[1]);
	initial_fractal(fractal);
	initial_mlx(fractal);
	cx = -1.;
	cy = -1.;
	draw_fractal(fractal, cx, cy);
	mlx_mouse_hook(fractal->win_ptr, mouse_hook, fractal);
	mlx_key_hook(fractal->win_ptr, key_event, fractal);
//	key_event(fractal);
//        mlx_hook(fractal->win_ptr, 2, 9, ft_close, &fractal);
	mlx_loop(fractal->mlx_ptr);
	printf("fim de programa");
	free(fractal);
	printf("fractal destruido");
	return (0);
}
