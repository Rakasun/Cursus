/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:13:53 by yfang             #+#    #+#             */
/*   Updated: 2023/12/22 18:38:45 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rrotate(t_stack	**stack)
{
	t_stack	*aux;

	aux = *stack;
	*stack = ft_stcklast(*stack)->next;
	(*stack)->next = aux;
	ft_stcklast(aux)->next = NULL;
}

void	ft_rrotate_rra(t_data *data)
{
	ft_rrotate(&data->stack_a);
	ft_printf("rra\n");
}

void	ft_rrotate_rrb(t_data *data)
{
	ft_rrotate(&data->stack_b);
	ft_printf("rrb\n");
}

void	ft_rrotate_rrr(t_data *data)
{
	ft_rotate_ra(&data->stack_a);
	ft_rotate_rb(&data->stack_b);
	ft_printf("rrr\n");
}
