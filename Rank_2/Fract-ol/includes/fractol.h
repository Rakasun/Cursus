/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:24:26 by yfang             #+#    #+#             */
/*   Updated: 2023/12/05 14:17:30 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*---------------------------------   LIBS   ---------------------------------*/
# include "Libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
// Global
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <memory.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*--------------------------------   MACROS   --------------------------------*/
// Size
# define HEIGHT 700
# define WIDTH 900
// MLX ERR
# define MLX_ERR 1
# define IMG_ERR 2

/*--------------------------------   STRUCTS   -------------------------------*/
typedef struct s_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb;

typedef struct s_ncom
{
	double	real;
	double	imagi;
}	t_ncom;

/* Key
	-mlx_t	*mlx; --> window
	-mlx_t	*img; --> put_image
	-t_rgb	rgb; --> color;
	-char	*name; --> set fractal
	-double	zoom; --> iteraction
	-int	x; --> position
	-t_ncom	z; --> julia position
*/
typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_rgb		rgb;
	int			color;
	int			smooth;
	char		*name;
	int			f_type;
	double		zoom;
	double		xmv;
	double		ymv;
	int			max_iter;
	int			i;
	int			x;
	int			y;
	t_ncom		z;
	t_ncom		c;
	t_ncom		jul_arg;
}	t_fractal;

/*-------------------------------   FUNCTIONS   ------------------------------*/
//	errors
void	ft_control(void);
void	ft_error_usage(void);
void	ft_error(int err, t_fractal *f);
//	utils
void	ft_fractol(t_fractal *f);
int		ft_double_check(char *s);
double	ft_atof(const char *str);
void	ft_name(t_fractal *f);
void	ft_f_type(t_fractal *f);
// utils_utils
void	ft_put_pixel(t_fractal *f);
void	ft_select(t_fractal *f);
double	ft_process(const char *str, double number, int dp_seen, double d_divi);
//hook
void	ft_hook(void *param);
//fractals
void	ft_julia(t_fractal *f);
void	ft_mandelbrot(t_fractal *f);
void	ft_burning_ship(t_fractal *f);

#endif