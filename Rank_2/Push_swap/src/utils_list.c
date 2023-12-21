/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:55:30 by yfang             #+#    #+#             */
/*   Updated: 2023/12/21 18:28:35 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*lstnew(int content)
{
	t_stack	*new_list;

	new_list = malloc(sizeof(t_stack));
	if (!new_list)
		return (0);
	new_list->value = content;
	new_list->next = NULL;
	return (new_list);
}

t_stack	*lstlast(t_stack *lst)
{
	t_stack	*cplst;

	if (!lst)
		return (0);
	cplst = lst;
	while (cplst->next)
		cplst = cplst->next;
	return (cplst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*cplst;

	if (*lst != 0)
	{
		cplst = lstlast(*lst);
		cplst->next = new;
	}
	else
		*lst = new;
}
