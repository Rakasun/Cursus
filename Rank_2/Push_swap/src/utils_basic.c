/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:21:52 by yfang             #+#    #+#             */
/*   Updated: 2024/01/22 12:24:12 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_absolut(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

int	ft_middle(int size)
{
	int	aux;

	if (size % 2 == 0)
		aux = size / 2;
	else
		aux = (size / 2) + 1;
	return (aux);
}

long	ft_atol(const char *str)
{
	int		i;
	int		neg;
	long	n;

	i = 0;
	neg = 1;
	n = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * neg);
}
