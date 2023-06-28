/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:25:01 by yfang             #+#    #+#             */
/*   Updated: 2023/05/09 19:28:21 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*cplst;

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
