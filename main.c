/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:35:55 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/06 19:21:09 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	*fractal;

	if (argc == 1 || argc > 2)
	{
		options_menu();
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (0);
	fractal->type = menu(argv[1], fractal);
	fractal->name = argv[1];
	initial_fractal(fractal);
	initial_events(fractal);
	draw_fractal(fractal);
	mlx_loop(fractal->mlx_ptr);
	return (0);
}
