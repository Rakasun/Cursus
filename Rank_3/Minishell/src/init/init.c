/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:18:27 by yfang             #+#    #+#             */
/*   Updated: 2024/02/13 17:01:39 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_init(t_shell	*shell, char **envp)
{
	shell->env = ft_calloc(1, sizeof(t_env));
	shell->tokens = NULL;
	if (!shell || !shell->tokens || !shell->env)
		return (EXIT_FAILURE);
	shell->line = NULL;
/* 	ft_dupenvp(shell, envp);
	ft_env(shell->env, shell->envp); */
}
