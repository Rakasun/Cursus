/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:22:15 by yfang             #+#    #+#             */
/*   Updated: 2024/02/14 18:17:03 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_init_token(t_shell *shell, int type, char *str)
{
	t_tokens	*temp;
	tmp = ft_newtoken(type, str)
	if (!shell->tokens)
		ft_addfronttoken(&shell->tokens, tmp);
	else
		ft_addbacktoken(&shell->tokens, tmp);
}

void	ft_token(t_shell *shell, int *i)
{
	char	*tmp;
	char	*start;

	while (shell->line[*i] && !ft_isspecial(shell->line[*i]))
		*i++;
	tmp = ft_strndup(*start, *i);
	ft_init_token(shell, ARG, tmp);
	free(tmp);
}

t_tokens	*ft_tokenizer(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->line[i])
	{
		if ((!ft_isspecial(shell->line[i])))
			ft_token(shell, &i);
		else if (ft_isspace(shell->line[i]))
			ft_token_in_space(shell, &i);
		i++;
	}
}
