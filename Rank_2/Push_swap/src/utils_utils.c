/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:04:33 by yfang             #+#    #+#             */
/*   Updated: 2024/01/22 18:04:31 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* void	ft_order(t_stack **stack)
{
	int	
} */

t_stack	*ft_target(t_stack *tmp, t_stack *aux, int j, int i)
{
	while (tmp)
	{
		if (aux == NULL && tmp->index > j)
			aux = tmp;
		if (i == 0)
		{
			if (tmp->index > j && aux->index > tmp->index)
				aux = tmp;
		}
		else if (i == 1)
		{
			if (tmp->index < j && aux->index > tmp->index)
				aux = tmp;
		}
		tmp = tmp->next;
	}
	return (aux);
}

void	ft_rotates(t_data *data, int *cost, int i)
{
	if (*cost > 0)
	{
		while (*cost > 0)
		{
			if (i == 0)
				ft_rotate_ra(data, 0);
			if (i == 1)
				ft_rotate_rb(data, 0);
			(*cost)--;
		}
	}
	if (*cost < 0)
	{
		while (*cost < 0)
		{
			if (i == 0)
				ft_rrotate_rra(data, 0);
			if (i == 1)
				ft_rrotate_rrb(data, 0);
			(*cost)++;
		}
	}
}

t_stack	*ft_the_cheapest(t_data *data)
{
	t_stack	*aux;
	t_stack	*tmp;

	aux = data->stack_b;
	tmp = aux;
	while (aux)
	{
		if ((ft_absolut(aux->cost_a) + ft_absolut(aux->cost_b))
			< (ft_absolut(tmp->cost_a) + ft_absolut(tmp->cost_b)))
			tmp = aux;
		aux = aux->next;
	}
	return (tmp);
}

void	ft_algorithm(t_data *data)
{
	if (data->numarg == 2)
		ft_swap_sa(data, 0);
	else if (data->numarg == 3)
		ft_short3(data);
	else if (data->numarg > 3)
		ft_algostep(data);
}
