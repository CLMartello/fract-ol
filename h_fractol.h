/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_fractol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:45:47 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/31 21:11:50 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_FRACTOL_H

# define H_FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
//# include <math.h>
# include "minilibx-linux/mlx.h"
//# include <X11/keysym.h>

# define WIDTH 800 
# define HEIGHT	600
# define ESC 53

typedef struct s_data
{
	char	*addr;
	int     bits_per_pixel;
	int	size_line;
	int	endian;
}		t_data;

typedef struct	s_fractal
{
	int	type;
	char	*name;
	double	x;
	double	y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int	max_iterations;
	char	*pointer_to_img;
    t_data	data;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int	color;
}		t_fractal;

int	ft_strcmp(char *s1, char *s2);
int	draw_fractal(t_fractal *fractal, double cx, double cy);
void	calc_mandelbrot(t_fractal *fractal);
void	calc_julia(t_fractal *fractal, double cx, double cy);
void	free_fractal(t_fractal *fractal);
void	mlx_fractal(t_fractal *fractal);
void    calc_mandel_julia(t_fractal *fractal);
void    initial_mlx(t_fractal *fractal);
void    initial_fractal(t_fractal *fractal);
void    color_pixel(t_fractal *fractal, int x, int y, int color);
int     ft_close(t_fractal *fractal);
//int     key_event(t_fractal *fractal);
int     key_event(int key_code, t_fractal *fractal);
void    zoom(t_fractal *fractal, int x, int y, int zoom);
int     mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

#endif
