/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:34:37 by yfang             #+#    #+#             */
/*   Updated: 2023/05/12 15:18:54 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*cplst;

	if (!lst || !del)
		return ;
	del(lst->content);
	cplst = lst;
	lst = cplst->next;
	free(cplst);
	lst = 0;
}
