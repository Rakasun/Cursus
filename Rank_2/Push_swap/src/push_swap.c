/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:46:25 by yfang             #+#    #+#             */
/*   Updated: 2023/12/21 18:30:04 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_visual(t_data *data)
{
	t_stack	*tmp;

	tmp = data->stack_a;
	while (tmp)
	{
		ft_printf("Valor = %d, Index = %d\n", tmp->value, tmp->value);
		tmp = tmp->next;
	}
}

void	ft_index(t_stack *stack_a)
{
	t_stack	*aux;
	t_stack	*tmp;

	aux = stack_a;
	while (aux)
	{
		tmp = stack_a;
		aux->index = 1;
		while (tmp)
		{
			if (tmp->value < aux->value)
				aux->index++;
			tmp = tmp->next;
		}
		aux = aux->next;
	}
}

t_stack	*ft_init_a(t_data *data)
{
	int	i;

	i = 0;
	data->stack_a = lstnew(ft_atoi(data->arg[0]));
	while (data->arg[++i])
		lstadd_back(&data->stack_a, lstnew(ft_atoi(data->arg[i])));
	ft_index(data->stack_a);
	return (data->stack_a);
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
	ft_check_ifnum(data);
	ft_check_repeat(data);
	data->stack_a = ft_init_a(data);
	ft_visual(data);
	free(data);
	return (0);
}
