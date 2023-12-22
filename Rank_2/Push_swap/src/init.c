/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:09:51 by yfang             #+#    #+#             */
/*   Updated: 2023/12/22 15:48:01 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_index(t_stack *stack_a)
{
	t_stack	*aux;
	t_stack	*tmp;

	aux = stack_a;
	while (aux)
	{
		tmp = stack_a;
		aux->index = 1;
		while (tmp)
		{
			if (tmp->value < aux->value)
				aux->index++;
			tmp = tmp->next;
		}
		aux = aux->next;
	}
}

void	ft_pos(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

t_stack	*ft_init_a(t_data *data)
{
	int	i;

	i = 0;
	data->stack_a = ft_stcknew(ft_atoi(data->arg[0]));
	while (data->arg[++i])
		ft_stckadd_back(&data->stack_a, ft_stcknew(ft_atoi(data->arg[i])));
	ft_index(data->stack_a);
	ft_pos(data->stack_a);
	return (data->stack_a);
}
