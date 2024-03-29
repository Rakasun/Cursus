/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeneizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:40:13 by yfang             #+#    #+#             */
/*   Updated: 2024/02/29 15:29:59 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_quotes(t_shell *shell, int *i)
{
	int	j;

	j = 0;
	if (shell->line[*i] == '\'')
	{
		(*i)++;
		while (shell->line[*i] && shell->line[*i] != '\'')
		{
			(*i)++;
			j++;
		}
	}
	else if (shell->line[*i] == '\"')
	{
		(*i)++;
		while (shell->line[*i] && shell->line[*i] != '\"')
		{
			(*i)++;
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
	j = ft_quotes(shell, i);
	tmp = ft_strndup(start + 1, j);
	if (*start == '\'')
		ft_init_token(shell, SIMPLE, tmp);
	else if (*start == '\"')
		ft_init_token(shell, DOUBLE, tmp);
	free(tmp);
}

int	ft_type(t_tokens *token)
{
	t_tokens	*tmp;

	tmp = ft_lasttoken(token);
	return (tmp->type);
}

void	ft_token(t_shell *shell, int *i)
{
	char	*tmp;
	char	*start;
	int		j;

	start = shell->line + *i;
	j = 0;
	while (shell->line[*i] && !ft_isspecial(shell->line[*i]))
	{
		(*i)++;
		j++;
	}
	tmp = ft_strndup(start, j);
	if (shell->tokens == NULL || ft_type(ft_lasttoken(shell->tokens)) == 9)
		ft_init_token(shell, CMD, tmp);
	else
		ft_init_token(shell, ARG, tmp);
	free(tmp);
}
