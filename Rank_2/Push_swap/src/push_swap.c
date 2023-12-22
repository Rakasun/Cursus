/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:46:25 by yfang             #+#    #+#             */
/*   Updated: 2023/12/22 17:57:44 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_visual(t_data *data)
{
	t_stack	*tmp;

	tmp = data->stack_a;
	while (tmp)
	{
		ft_printf("Value = %d, Index = %d, Pos = %d\n", tmp->value, tmp->index, tmp->pos);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
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
	free(data);
	return (0);
}
