/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:13:53 by yfang             #+#    #+#             */
/*   Updated: 2024/01/22 12:55:26 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rrotate(t_stack	**stack)
{
	t_stack	*aux;
	t_stack	*tmp;

	aux = ft_stcklast(*stack);
	tmp = *stack;
	if (ft_stacksize(*stack) > 1)
	{
		while (tmp)
		{
			if (tmp->next->next == NULL)
			{
				tmp->next = NULL;
				break ;
			}
			tmp = tmp->next;
		}
		ft_stackadd_front(stack, aux);
	}
}

void	ft_rrotate_rra(t_data *data, int i)
{
	ft_rrotate(&data->stack_a);
	if (i == 0)
		ft_printf("rra\n");
}

void	ft_rrotate_rrb(t_data *data, int i)
{
	ft_rrotate(&data->stack_b);
	if (i == 0)
		ft_printf("rrb\n");
}

void	ft_rrotate_rrr(t_data *data)
{
	ft_rotate_ra(data, 1);
	ft_rotate_rb(data, 1);
	ft_printf("rrr\n");
}
