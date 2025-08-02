/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:42:51 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/02 16:43:05 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fractol.h"

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

int	free_fractal(t_fractal *frac)
{
	if (frac->img)
		mlx_destroy_image(frac->mlx, frac->img);
	else if (frac->win)
		mlx_destroy_window(frac->mlx, frac->win);
	else if (frac->mlx)
	{
		mlx_destroy_display(frac->mlx);
		free(frac->mlx);
	}
	free(frac);
	return (0);
}

void	set_random_julia(double cx, double cy)
{
	cx = (((double)rand() / RAND_MAX) * 3.0 - 1.5);
	cy = (((double)rand() / RAND_MAX) * 3.0 - 1.5);

}
