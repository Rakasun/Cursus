/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:59:17 by yfang             #+#    #+#             */
/*   Updated: 2023/11/16 15:50:30 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_fractol(t_fractal *f)
{
	f->y = 0;
	while (f->y < HEIGHT)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			ft_select(f);
			f->x++;
		}
		f->y++;
	}
}

void	ft_f_type(t_fractal *f)
{
	if (f->f_type == 1)
	{
		if (!(f->jul_arg.real || f->jul_arg.imagi))
			f->jul_arg = (t_ncom){-0.8, 0.156};
	}
	else if (f->f_type == 2)
	{
		f->xmv = -0.8;
		f->ymv = 0.0;
	}
	else if (f->f_type == 3)
	{
		f->xmv = -0.5;
		f->ymv = -0.4;
	}
}

void	ft_name(t_fractal *f)
{
	if (f->f_type == 1)
		f->name = "Julia";
	if (f->f_type == 2)
		f->name = "Mandelbrot";
	if (f->f_type == 3)
		f->name = "BurningShip";
}

int	ft_double_check(char *s)
{
	int	decimal_points;
	int	i;

	decimal_points = 0;
	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] != '.' && s[i] != '-' && !(s[i] >= '0' && s[i] <= '9'))
			return (0);
		if (s[i] == '.')
			decimal_points++;
		i++;
	}
	if (decimal_points > 1)
		return (0);
	return (1);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	number;
	int		decimal_point_seen;
	double	decimal_divisor;

	sign = 1;
	number = 0;
	decimal_point_seen = 0;
	decimal_divisor = 1;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	number = ft_process(str, number, decimal_point_seen, decimal_divisor);
	return (sign * number);
}
