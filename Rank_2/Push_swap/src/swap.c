/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:33:43 by yfang             #+#    #+#             */
/*   Updated: 2023/12/22 18:17:44 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack	**stack)
{
	t_stack	*aux;

	aux = *stack;
	*stack = (*stack)->next;
	aux->next = (*stack)->next;
	(*stack)->next = aux;
}

void	ft_swap_sa(t_data *data)
{
	ft_swap(&data->stack_a);
	ft_printf("sa\n");
}

void	ft_swap_sb(t_data *data)
{
	ft_swap(&data->stack_b);
	ft_printf("sb\n");
}

void	ft_swap_ss(t_data *data)
{
	ft_swap(&data->stack_a);
	ft_swap(&data->stack_b);
	ft_printf("ss\n");
}
