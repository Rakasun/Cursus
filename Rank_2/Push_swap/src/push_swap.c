/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:46:25 by yfang             #+#    #+#             */
/*   Updated: 2024/01/22 17:37:00 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_visual(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = data->stack_a;
	tmp2 = data->stack_b;
	ft_printf("stack_a\n");
	while (tmp)
	{
		ft_printf("Value = %d, Index = %d, Pos = %d, Target = %d, Cost_a = %d, Cost_b = %d\n", tmp->value, tmp->index, tmp->pos, tmp->target_pos, tmp->cost_a, tmp->cost_b);
		tmp = tmp->next;
	}
	ft_printf("\n");
	ft_printf("stack_b\n");
	while (tmp2)
	{
		ft_printf("Value = %d, Index = %d, Pos = %d, Target = %d, Cost_a = %d, Cost_b = %d\n", tmp2->value, tmp2->index, tmp2->pos, tmp2->target_pos, tmp2->cost_a, tmp2->cost_b);
		tmp2 = tmp2->next;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (0);
	if (ac == 1)
		return (0);
	else if (ac == 2)
		data->arg = ft_split(av[1], ' ');
	else
		data->arg = ++av;
	ft_checks(data);
	data->stack_a = ft_init_a(data);
	if (!ft_check_order(&data->stack_a))
		ft_algorithm(data);
	ft_visual(data);
	free(data);
	return (0);
}
