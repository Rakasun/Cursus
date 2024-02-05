/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:34:11 by yfang             #+#    #+#             */
/*   Updated: 2024/01/30 16:01:03 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_rotate(t_stack	**stack)
{
	t_stack	*aux;

	if (ft_stacksize(*stack) > 1)
	{
		aux = *stack;
		*stack = (*stack)->next;
		ft_stcklast(*stack)->next = aux;
		aux->next = NULL;
	}
}

void	ft_rotate_ra(t_data *data, int i)
{
	ft_rotate(&data->stack_a);
	if (i == 0)
		ft_printf("ra\n");
}

void	ft_rotate_rb(t_data *data, int i)
{
	ft_rotate(&data->stack_b);
	if (i == 0)
		ft_printf("rb\n");
}

void	ft_rotate_rr(t_data *data, int i)
{
	ft_rotate_ra(data, 1);
	ft_rotate_rb(data, 1);
	if (i == 0)
		ft_printf("rr\n");
}
