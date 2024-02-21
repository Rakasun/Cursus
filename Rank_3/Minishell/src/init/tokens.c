/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:22:15 by yfang             #+#    #+#             */
/*   Updated: 2024/02/21 17:47:35 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_init_token(t_shell *shell, int type, char *str)
{
	t_tokens	*tmp;

	tmp = ft_newtoken(type, str);
	ft_addbacktoken(&shell->tokens, tmp);
}

int	ft_quotes(t_shell *shell, int **i)
{
	int	j;

	j = 0;
	if (shell->line[**i] == '\'')
	{
		while (shell->line[**i] && shell->line[**i] != '\'')
		{
			(**i)++;
			j++;
		}
	}
	else if (shell->line[**i] == '"')
	{
		while (shell->line[**i] && shell->line[**i] != '"')
		{
			(**i)++;
			j++;
		}
	}
	return (j);
}

void	ft_token_in_quotes(t_shell *shell, int *i)
{
	char	*tmp;
	char	*start;
	int		j;

	start = shell->line + *i;
	j = ft_quotes(shell, &i);
	tmp = ft_strndup(start, j);
	if (*start == '\'')
		ft_init_token(shell, SIMPLE, tmp);
	else if (*start == '"')
		ft_init_token(shell, DOUBLE, tmp);
	free(tmp);
}

void	ft_tokenizer(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->line[i])
	{
		if ((!ft_isspecial(shell->line[i])))
			ft_token(shell, &i);
		else if (shell->line[i] == '\'' || shell->line[i] == '"')
			ft_token_in_quotes(shell, &i);
		i++;
	}
}
