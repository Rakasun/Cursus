/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:44:06 by yfang             #+#    #+#             */
/*   Updated: 2024/01/09 18:43:38 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_short3(t_data *data)
{
	t_stack	*one;
	t_stack	*two;
	t_stack	*three;

	one = data->stack_a;
	two = one->next;
	three = two->next;
	if (one->index < two->index && two->index > three->index)
	{
		ft_rrotate_rra(data);
		ft_short3(data);
	}
	else if (one->index > two->index && one->index > three->index)
	{
		ft_rotate_ra(data);
		ft_short3(data);
	}
	else if (one->index > two->index && two->index < three->index)
		ft_swap_sa(data);
}

void	ft_algostep(t_data *data)
{
	while (ft_stacksize(data->stack_a) > 3)
		ft_push_pb(data);
	ft_short3(data);
	while(data->stack_b)
	{
		ft_pos(data->stack_a);
		ft_pos(data->stack_b);
	 	ft_target_pos(data->stack_a, data->stack_b);
		break ;
	}
	ft_printf("%i\n", data->stack_a->pos);
	ft_printf("%i\n", data->stack_b->pos);
}
