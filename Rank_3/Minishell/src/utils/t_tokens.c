/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tokens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:30:22 by yfang             #+#    #+#             */
/*   Updated: 2024/02/14 18:24:24 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_stack	*ft_lasttoken(t_stack *token)
{
	t_stack	*cptoken;

	if (!token)
		return (0);
	cptoken = token;
	while (cptoken->next)
		cptoken = cptoken->next;
	return (cptoken);
}

void	ft_addbacktoken(t_tokens **token, t_tokens *new)
{
	t_tokens	*cptoken;

	if (*token != 0)
	{
		cptoken = ft_lasttoken(*token);
		cptoken->next = new;
	}
	else
		*token = new;
}

void	ft_addfronttoken(t_tokens **token, t_tokens *new)
{
	if (token && new)
	{
		new->next = *token;
		*token = new;
	}
}

t_tokens	*ft_newtoken(int type, char *str)
{
	t_tokens	*new_token;

	new_token = ft_calloc(1, sizeof(t_tokens));
	if (!new_token)
		return (0);
	new_token->str = ft_strdup(str);
	new_token->type = type;
	new_token->space = 0;
	new_token->next = NULL;
	return (new_token);
}
