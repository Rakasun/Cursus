/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:55:30 by yfang             #+#    #+#             */
/*   Updated: 2024/01/30 16:01:19 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	ft_stacksize(t_stack *lst)
{
	int		i;
	t_stack	*cplst;

	if (!lst)
		return (0);
	i = 1;
	cplst = lst;
	while (cplst->next)
	{
		i++;
		cplst = cplst->next;
	}
	return (i);
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_stack	*ft_stcknew(int value)
{
	t_stack	*new_stack;

	new_stack = ft_calloc(1, sizeof(t_stack));
	if (!new_stack)
		return (0);
	new_stack->value = value;
	new_stack->index = 0;
	new_stack->pos = 0;
	new_stack->target_pos = 0;
	new_stack->cost_a = 0;
	new_stack->cost_b = 0;
	new_stack->next = NULL;
	return (new_stack);
}

t_stack	*ft_stcklast(t_stack *stck)
{
	t_stack	*cpstck;

	if (!stck)
		return (0);
	cpstck = stck;
	while (cpstck->next)
		cpstck = cpstck->next;
	return (cpstck);
}

void	ft_stckadd_back(t_stack **stck, t_stack *new)
{
	t_stack	*cplst;

	if (*stck != 0)
	{
		cplst = ft_stcklast(*stck);
		cplst->next = new;
	}
	else
		*stck = new;
}
