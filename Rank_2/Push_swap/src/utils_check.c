/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:33:55 by yfang             #+#    #+#             */
/*   Updated: 2023/12/18 19:39:25 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	ft_check_order(t_data *data)
{
	int	i;
	
}

int	ft_check_repeat(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->arg[i])
	{
		j = i + 1;
		while (data->arg[j])
		{
			if (ft_atoi(data->arg[i]) == ft_atoi(data->arg[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_ifnum(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->arg[i])
	{
		j = 0;
		if (data->arg[i][j] == '-')
			j++;
		while (data->arg[i][j])
		{
			if (!ft_isdigit(data->arg[i][j]))
				ft_error();
			j++;
		}
		if (ft_atol(data->arg[i]) < MIN || ft_atol(data->arg[i]) > MAX)
			ft_error();
		i++;
	}
}
