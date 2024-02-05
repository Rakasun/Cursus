/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:40:52 by yfang             #+#    #+#             */
/*   Updated: 2024/01/30 18:25:17 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*aux;

	node = *stack;
	while (node)
	{
		aux = node->next;
		free(node);
		node = aux;
	}
}

void	ft_free2(char **dst)
{
	int	i;

	i = 0;
	while (dst[i])
		free(dst[i++]);
	free(dst);
}
