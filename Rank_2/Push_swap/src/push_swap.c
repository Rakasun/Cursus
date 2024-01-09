/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:46:25 by yfang             #+#    #+#             */
/*   Updated: 2024/01/09 19:04:37 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_visual(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = data->stack_a;
	tmp2 = data->stack_b;
	while (tmp)
	{
		ft_printf("Value = %d, Index = %d, Pos = %d\n", tmp->value, tmp->index, tmp->pos);
		tmp = tmp->next;
	}
	ft_printf("\n");
	while (tmp2)
	{
		ft_printf("Value = %d, Index = %d, Pos = %d, Target = %d\n", tmp2->value, tmp2->index, tmp2->pos, tmp2->target_pos);
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
