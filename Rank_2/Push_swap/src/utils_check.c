/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:33:55 by yfang             #+#    #+#             */
/*   Updated: 2023/12/22 17:57:07 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_checks(t_data *data)
{
	ft_check_ifnum(data);
	ft_check_repeat(data);
}

int	ft_check_order(t_stack **stack_a)
{
	t_stack	*aux;

	aux = *stack_a;
	while (aux->next)
	{
		if (aux->value > aux->next->value)
			return (0);
		aux = aux->next;
	}
	return (1);
}

void	ft_check_repeat(t_data *data)
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
				ft_error();
			j++;
		}
		i++;
	}
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
	data->numarg = i;
}
