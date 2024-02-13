/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:39:05 by yfang             #+#    #+#             */
/*   Updated: 2024/02/13 16:19:50 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_loop(t_shell *shell)
{
	while (1)
	{
		shell->line = readline("marinashell-0.1$ ");
/* 		if (ft_strncmp(shell->line, "\0", 1))
			add_history(shell->line); */
		shell->tokens = ft_tokenize(shell);
/* 		if (!ft_whitespace(shell->line))
			ft_builtins(shell); */
		ft_free_loop(shell);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_shell	*shell;

	(void)argv;
	if (argc == 1)
	{
		ft_welcome();
		shell = ft_calloc(1, sizeof(t_shell));
		ft_init(shell, envp);
		ft_loop(shell);
	}
	return (EXIT_SUCCESS);
}
