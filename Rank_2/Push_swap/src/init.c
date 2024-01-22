/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:09:51 by yfang             #+#    #+#             */
/*   Updated: 2024/01/22 19:06:04 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_pos(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

void	ft_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	int		j;
	t_stack	*tmpa;
	t_stack	*tmpb;
	t_stack	*aux;

	tmpb = *stack_b;
	while (tmpb)
	{
		tmpa = *stack_a;
		j = tmpb->index;
		aux = NULL;
		while (tmpa)
		{
			if (aux == NULL && tmpa->index > j)
				aux = tmpa;
			if (tmpa->index > j && aux->index > tmpa->index)
				aux = tmpa;

			tmpa = tmpa->next;
		}
		if (aux == NULL)
			while (tmpa)
			{
				if (aux == NULL && tmpa->index < j)
					aux = tmpa;
				if (tmpa->index < j && aux->index < tmpa->index)
					aux = tmpa;
				tmpa = tmpa->next;
			}
		tmpb->target_pos = aux->pos;
		tmpb = tmpb->next;
	}
}

void	ft_move_cost(t_data *data)
{
	int		size_a;
	int		size_b;
	int		mid_a;
	int		mid_b;
	t_stack	*aux;

	aux = data->stack_b;
	size_a = ft_stacksize(data->stack_a);
	size_b = ft_stacksize(data->stack_b);
	mid_a = ft_middle(size_a);
	mid_b = ft_middle(size_b);
	while (aux)
	{
		if (aux->pos <= mid_b)
			aux->cost_b = aux->pos - 1;
		else if (aux->pos > mid_b)
			aux->cost_b = (size_b - aux->pos + 1) * -1;
		if (aux->target_pos <= mid_a)
			aux->cost_a = aux->target_pos - 1;
		else if (aux->target_pos > mid_a)
			aux->cost_a = (size_a - aux->target_pos + 1) * -1;
		aux = aux->next;
	}
}

t_stack	*ft_init_a(t_data *data)
{
	int	i;

	i = 0;
	data->stack_a = ft_stcknew(ft_atoi(data->arg[0]));
	while (data->arg[++i])
		ft_stckadd_back(&data->stack_a, ft_stcknew(ft_atoi(data->arg[i])));
	ft_index(data->stack_a);
	return (data->stack_a);
}
