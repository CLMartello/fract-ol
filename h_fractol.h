/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_fractol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:45:47 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/02 18:24:23 by clumertz         ###   ########.fr       */
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

//Resolution definitions
//mudar definicoes para letra maiuscula depois??
# define WIDTH 800 
# define HEIGHT	600
# define old_xmax 799
# define old_xmin 0
# define new_xmax 2
# define new_xmin -2
# define old_ymax 599
# define old_ymin 0
# define new_ymax 2
# define new_ymin -2
# define iterations 100

//Key and mouse definitions

typedef struct s_number
{
	double	x;
	double	y;
}		t_number;

typedef struct s_data
{
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}		t_data;

typedef struct s_fractal
{
	int		type;
	char	*name;
	double	x;
	double	y;
	t_number z;
	t_number c;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		max_iterations;
	char	*pointer_to_img;
	t_data	data;
	void	*mlx;
	void	*win;
	void	*img;
	int		color;
}		t_fractal;

int		draw_fractal(t_fractal *frac, double cx, double cy);
void	mlx_fractal(t_fractal *frac);
void	color_pixel(t_fractal *frac, int x, int y, int color);

//Init functions
void	initial_mlx(t_fractal *frac);
void	initial_fractal(t_fractal *frac);
int     initial_number(t_fractal *frac);

//Events functions
int		key_event(int key_code, t_fractal *frac);
void	zoom(t_fractal *frac, int x, int y, int zoom);
int		mouse_hook(int mouse_code, int x, int y, t_fractal *frac);

//Parse functions
void	options_menu(void);
int		menu(char *name);

//Calculations functions 
void	calc_mandelbrot_julia(t_fractal *frac);
void	choose_mandelbrot_julia(t_fractal *frac);
double  resize(double new_max, double new_min, double actual_nbr, double size);

//Utils functions
int		ft_strcmp(char *s1, char *s2);
int	free_fractal(t_fractal *frac);

#endif
