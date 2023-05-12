/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:56:31 by yfang             #+#    #+#             */
/*   Updated: 2023/05/12 16:06:24 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*cplst;

	if (!lst)
		return (NULL);
	newlst = 0;
	while (lst)
	{
		cplst = ft_lstnew(f(lst->content));
		if (cplst)
		{
			ft_lstadd_back(&newlst, cplst);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
	}
	return (newlst);
}
