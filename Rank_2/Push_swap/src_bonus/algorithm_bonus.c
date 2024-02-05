/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:44:06 by yfang             #+#    #+#             */
/*   Updated: 2024/01/30 18:25:12 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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
		ft_rrotate_rra(data, 0);
		ft_short3(data);
	}
	else if (one->index > two->index && one->index > three->index)
	{
		ft_rotate_ra(data, 0);
		ft_short3(data);
	}
	else if (one->index > two->index && two->index < three->index)
		ft_swap_sa(data, 0);
}

void	ft_moves(t_data *data)
{
	t_stack	*cheapest;

	cheapest = ft_the_cheapest(data);
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		ft_rotate_rr(data, 0);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		ft_rrotate_rrr(data, 0);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
	ft_rotates(data, &(cheapest)->cost_a, 0);
	ft_rotates(data, &(cheapest)->cost_b, 1);
	ft_push_pa(data, 0);
}

void	ft_pre_order(t_data *data)
{
	int	size;
	int	i;
	int	push;

	size = ft_stacksize(data->stack_a);
	i = 0;
	push = 0;
	while (size > 6 && i < size && push <= size / 2)
	{
		if (data->stack_a->index <= size / 2)
		{
			ft_push_pb(data, 0);
			push++;
		}
		else
			ft_rotate_ra(data, 0);
		i++;
	}
}

void	ft_algostep(t_data *data)
{
	ft_pre_order(data);
	while (ft_stacksize(data->stack_a) > 3)
		ft_push_pb(data, 0);
	ft_short3(data);
	while (data->stack_b)
	{
		ft_pos(data->stack_a);
		ft_pos(data->stack_b);
		ft_target_pos(&data->stack_a, &data->stack_b);
		ft_move_cost(data);
		ft_moves(data);
	}
	if (!ft_check_order(&data->stack_a))
		ft_order(data);
}
