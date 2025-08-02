/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 09:05:33 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/02 12:24:12 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	events_options(void)
{
	ft_putstr("Key ESC to leave window.\n");
	ft_putstr("Key C to change fractal color.\n");
	ft_putstr("Mouse scroll up and down to zoom in or out.\n");
	exit(EXIT_SUCCESS);
}

void	options_menu(void)
{
	ft_putstr("Welcome to fract-ol project.\n");
	ft_putstr("You can choose the fractal type among options:\n");
	ft_putstr("mandelbrot\njulia\n");
	ft_putstr("Or choose \"events\" to see your interactio options.");
	exit(EXIT_FAILURE);
}

int	menu(char *name)
{
	if ((ft_strcmp(name, "mandelbrot")) == 0)
		return (1);
	else if ((ft_strcmp(name, "julia")) == 0)
		return (2);
	else if ((ft_strcmp(name, "events")) == 0)
	{
		events_options();
		return (0);
	}
	options_menu();
	return (0);
}
