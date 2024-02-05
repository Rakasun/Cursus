/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:46:25 by yfang             #+#    #+#             */
/*   Updated: 2024/02/05 15:05:43 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 1)
		return (0);
	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (0);
	if (av[1][0] == '\0')
		ft_error();
	else if (ac == 2)
		data->arg = ft_split(av[1], ' ');
	else
		data->arg = ++av;
	ft_checks(data);
	data->stack_a = ft_init_a(data);
	if (!ft_check_order(&data->stack_a))
		ft_algorithm(data);
	ft_free_stack(&data->stack_a);
	ft_free_stack(&data->stack_b);
	if (ac == 2)
		ft_free2(data->arg);
	free(data);
	return (0);
}
