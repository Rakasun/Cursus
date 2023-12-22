/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:34:11 by yfang             #+#    #+#             */
/*   Updated: 2023/12/22 18:32:17 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_stack	**stack)
{
	t_stack	*aux;

	aux = *stack;
	*stack = (*stack)->next;
	ft_stcklast(*stack)->next = aux;
	aux->next = NULL;
}

void	ft_rotate_ra(t_data *data)
{
	ft_rotate(&data->stack_a);
	ft_printf("ra\n");
}

void	ft_rotate_rb(t_data *data)
{
	ft_rotate(&data->stack_b);
	ft_printf("rb\n");
}

void	ft_rotate_rr(t_data *data)
{
	ft_rotate_ra(&data->stack_a);
	ft_rotate_rb(&data->stack_b);
	ft_printf("rr\n");
}
