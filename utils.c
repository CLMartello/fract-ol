/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:42:51 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/03 19:58:53 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	free_fractal(t_fractal *fractal)
{
	if (fractal->image.img_ptr)
		mlx_destroy_image(fractal->mlx_ptr, fractal->image.img_ptr);
	if (fractal->win_ptr)
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	if (fractal->mlx_ptr)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
	}
	free(fractal);
	exit(0);
}
