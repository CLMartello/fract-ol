/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 09:05:33 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/06 19:21:39 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

static void	events_options(void)
{
	ft_putstr("Your event options are:.\n");
	ft_putstr("Mouse scroll up and down to zoom in or out.\n");
	ft_putstr("Mouse left click to create julia set.\n");
	ft_putstr("Key arrows to move image.\n");
	ft_putstr("Key C to change fractal color.\n");
	ft_putstr("Key J to create famous julia sets.\n");
	ft_putstr("Key ESC to leave window.\n");
	exit(EXIT_SUCCESS);
}

void	options_menu(void)
{
	ft_putstr("Welcome to fract-ol project.\n");
	ft_putstr("You can choose the fractal type among options:\n");
	ft_putstr("1- mandelbrot\n2- julia\n3- tricorn\n");
	ft_putstr("Or choose \"events\" to see your event options.");
	exit(EXIT_FAILURE);
}

int	menu(char *name, t_fractal *fractal)
{
	if ((ft_strcmp(name, "mandelbrot")) == 0)
		return (1);
	else if ((ft_strcmp(name, "julia")) == 0)
		return (2);
	else if ((ft_strcmp(name, "tricorn")) == 0)
		return (3);
	else if ((ft_strcmp(name, "events")) == 0)
	{
		free(fractal);
		events_options();
	}
	free(fractal);
	options_menu();
	return (0);
}
