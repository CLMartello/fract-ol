/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_fractol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:45:47 by clumertz          #+#    #+#             */
/*   Updated: 2025/08/06 19:21:37 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_FRACTOL_H

# define H_FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"

//Resolution definitions
# define WIDTH 800 
# define HEIGHT	800

//Key definitions
# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

//Mouse definitions
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_number
{
	double	re;
	double	im;
}			t_number;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_image;

typedef struct s_event
{
	double	move_x;
	double	move_y;
	double	zoom;
	double	off_x;
	double	off_y;
}			t_event;

typedef struct s_fractal
{
	int			type;
	char		*name;
	double		x;
	double		y;
	t_number	z;
	t_number	c;
	int			max_iterations;
	int			color;
	t_image		image;
	void		*mlx_ptr;
	void		*win_ptr;
	t_event		event;
}				t_fractal;

//Draw functions
int		draw_fractal(t_fractal *fractal);
void	color_pixel(t_fractal *fractal, int x, int y, int color);

//Init functions
void	initial_mlx(t_fractal *fractal);
void	initial_fractal(t_fractal *fractal);
void	initial_events(t_fractal *fractal);

//Events functions
int		key_event(int key_code, t_fractal *fractal);
void	zoom(int button, int x, int y, t_fractal *fractal);
int		mouse_event(int mouse_code, int x, int y, t_fractal *fractal);
void	julia_generator(t_fractal *fractal, int j);
void	color_change(t_fractal *fractal, int j);

//Parse functions
void	options_menu(void);
int		menu(char *name, t_fractal *fractal);

//Calculations functions 
void	calc_mandelbrot_julia(t_fractal *fractal);
void	choose_mandelbrot_julia(t_fractal *fractal);
double	resize(double new_max, double new_min, double nbr, double size);
void	calc_tricorn(t_fractal *fractal);

//Utils functions
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		free_fractal(t_fractal *fractal);

#endif
