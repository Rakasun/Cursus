/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:34:08 by yfang             #+#    #+#             */
/*   Updated: 2024/01/30 16:01:00 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_push(t_stack	**stack1, t_stack **stack2)
{
	t_stack	*aux;

	if (ft_stacksize(*stack2) > 0)
	{
		aux = *stack2;
		*stack2 = (*stack2)->next;
		aux->next = *stack1;
		*stack1 = aux;
	}
}

void	ft_push_pa(t_data *data, int i)
{
	ft_push(&data->stack_a, &data->stack_b);
	if (i == 0)
		ft_printf("pa\n");
}

void	ft_push_pb(t_data *data, int i)
{
	ft_push(&data->stack_b, &data->stack_a);
	if (i == 0)
		ft_printf("pb\n");
}
