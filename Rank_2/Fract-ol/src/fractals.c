/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:18:10 by yfang             #+#    #+#             */
/*   Updated: 2023/11/20 15:41:28 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_julia(t_fractal *f)
{
	double	temp;

	f->z.real = (f->x - WIDTH / 2.0) * f->zoom / WIDTH + f->xmv;
	f->z.imagi = (f->y - HEIGHT / 2.0) * f->zoom / HEIGHT + f->ymv;
	f->c.real = f->jul_arg.real;
	f->c.imagi = f->jul_arg.imagi;
	f->i = 0;
	while (f->z.real * f->z.real + f->z.imagi * f->z.imagi < (1 << 8)
		&& f->i < f->max_iter)
	{
		temp = f->z.real * f->z.real - f->z.imagi * f->z.imagi + f->c.real;
		f->z.imagi = 2.0 * f->z.real * f->z.imagi + f->c.imagi;
		if (f->z.real == temp && f->z.imagi == f->z.imagi)
		{
			f->i = f->max_iter;
			break ;
		}
		f->z.real = temp;
		f->i++;
	}
	ft_put_pixel(f);
}

void	ft_mandelbrot(t_fractal *f)
{
	double	temp;

	f->c.real = (f->x - WIDTH / 2.0) * f->zoom / WIDTH + f->xmv;
	f->c.imagi = (f->y - HEIGHT / 2.0) * f->zoom / HEIGHT + f->ymv;
	f->z.real = 0;
	f->z.imagi = 0;
	f->i = 0;
	while (f->z.real * f->z.real + f->z.imagi * f->z.imagi < (1 << 8)
		&& f->i < f->max_iter)
	{
		temp = f->z.real * f->z.real - f->z.imagi * f->z.imagi + f->c.real;
		f->z.imagi = f->z.real * f->z.imagi * 2.0 + f->c.imagi;
		if (f->z.real == temp && f->i == f->z.imagi)
		{
			f->i = f->max_iter;
			break ;
		}
		f->z.real = temp;
		f->i++;
	}
	ft_put_pixel(f);
}

void	ft_burning_ship(t_fractal *f)
{
	double	temp;

	f->c.real = (f->x - WIDTH / 2.0) * f->zoom / WIDTH + f->xmv;
	f->c.imagi = (f->y - WIDTH / 2.0) * f->zoom / WIDTH + f->ymv;
	f->z.real = 0;
	f->z.imagi = 0;
	f->i = 0;
	while (f->z.real * f->z.real + f->z.imagi * f->z.imagi < (1 << 8)
		&& f->i < f->max_iter)
	{
		f->z.real = fabs(f->z.real);
		f->z.imagi = fabs(f->z.imagi);
		temp = f->z.real * f->z.real - f->z.imagi * f->z.imagi + f->c.real;
		f->z.imagi = 2.0 * f->z.real * f->z.imagi + f->c.imagi;
		if (f->z.real == temp && f->z.imagi == f->z.imagi)
		{
			f->i = f->max_iter;
			break ;
		}
		f->z.real = temp;
		f->i++;
	}
	ft_put_pixel(f);
}