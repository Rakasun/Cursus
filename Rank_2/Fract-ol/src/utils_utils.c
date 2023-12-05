/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:37:11 by yfang             #+#    #+#             */
/*   Updated: 2023/11/20 15:19:53 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_select(t_fractal *f)
{
	if (f->f_type == 1)
		ft_julia(f);
	else if (f->f_type == 2)
		ft_mandelbrot(f);
	else if (f->f_type == 3)
		ft_burning_ship(f);
}

double	ft_process(const char *str, double number, int dp_seen, double d_divi)
{
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		dp_seen = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (dp_seen)
		{
			d_divi *= 10;
			number = number + (*str - '0') / d_divi;
		}
		else
			number = number * 10 + (*str - '0');
		str++;
	}
	return (number);
}
