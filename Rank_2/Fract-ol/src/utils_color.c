/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:18:10 by yfang             #+#    #+#             */
/*   Updated: 2023/11/28 13:11:10 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	smooth_color(t_fractal *f)
{
	double	zn;
	double	nu;

	zn = log(f->z.real * f->z.real + f->z.imagi * f->z.imagi) / 2.0;
	nu = log(zn / log(2)) / log(2);
	if (f->i < f->max_iter)
		return (f->i + 1 - nu);
	else if (f->i > 0)
		return (f->max_iter);
	else
		return (0.0);
}

uint32_t	rgb(t_rgb color)
{
	return (color.r << 24 | color.g << 16 | color.b << 8 | 255);
}

void	ft_take_color(t_fractal *f, t_rgb *rgb)
{
	if (f->color == 0)
	{
		rgb->r = 255;
		rgb->g = 255;
		rgb->b = 255;
	}
	if (f->color == 1)
	{
		rgb->r = 215;
		rgb->g = 127;
		rgb->b = 226;
	}
	if (f->color == 2)
	{
		rgb->r = 135;
		rgb->g = 226;
		rgb->b = 185;
	}
	if (f->color == 3)
	{
		rgb->r = 255;
		rgb->g = 167;
		rgb->b = 0;
	}
}

t_rgb	ft_color(t_fractal *f, double l)
{
	t_rgb	palette;
	t_rgb	rgb;

	ft_take_color(f, &rgb);
	palette = (t_rgb){
		(rgb.r / f->max_iter) * l,
		(rgb.g / f->max_iter) * l,
		(rgb.b / f->max_iter) * l};
	return (palette);
}

void	ft_put_pixel(t_fractal *f)
{
	int		color;
	double	l;

	if (f->i >= f->max_iter)
		mlx_put_pixel(f->img, f->x, f->y, 0x000000FF);
	else
	{
		if (f->smooth)
			l = smooth_color(f);
		else
			l = f->i;
		color = rgb(ft_color(f, l));
		mlx_put_pixel(f->img, f->x, f->y, color);
	}
}
