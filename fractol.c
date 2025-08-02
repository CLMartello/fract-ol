/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:35:55 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/02 16:38:24 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	*frac;
	double		cx;
	double		cy;

	if (argc == 1 || argc > 2)
		options_menu();
	frac = malloc(sizeof(t_fractal));
	if (!frac)
		return (0);
	frac->type = menu(argv[1]);
	frac->name = argv[1];
	initial_fractal(frac);
	cx = 0;
	cy = 0;
	mlx_mouse_hook(frac->win, mouse_hook, frac);
	mlx_key_hook(frac->win, key_event, frac);
	draw_fractal(frac, cx, cy);
        mlx_hook(frac->win, 17, 1L<<17, free_fractal, &frac);
	mlx_loop(frac->mlx);
	free(frac);
	return (0);
}
