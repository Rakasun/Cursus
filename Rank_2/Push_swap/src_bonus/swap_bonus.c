/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:33:43 by yfang             #+#    #+#             */
/*   Updated: 2024/01/30 16:01:09 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_swap(t_stack	**stack)
{
	t_stack	*aux;

	if (ft_stacksize(*stack) > 1)
	{
		aux = *stack;
		*stack = (*stack)->next;
		aux->next = (*stack)->next;
		(*stack)->next = aux;
	}
}

void	ft_swap_sa(t_data *data, int i)
{
	ft_swap(&data->stack_a);
	if (i == 0)
		ft_printf("sa\n");
}

void	ft_swap_sb(t_data *data, int i)
{
	ft_swap(&data->stack_b);
	if (i == 0)
		ft_printf("sb\n");
}

void	ft_swap_ss(t_data *data, int i)
{
	ft_swap_sa(data, 1);
	ft_swap_sb(data, 1);
	if (i == 0)
		ft_printf("ss\n");
}
