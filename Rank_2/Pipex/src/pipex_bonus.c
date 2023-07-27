/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:11:44 by yfang             #+#    #+#             */
/*   Updated: 2023/07/25 14:41:36 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_daddy(int *pipefd)
{
	waitpid(-1, NULL, 0);
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
}

void	ft_here_doc(char *limit, int argc)
{
	pid_t	pid;
	int		pipefd[2];
	char	*str;

	if (argc < 6)
		ft_error(1);
	if (pipe(pipefd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		close(pipefd[0]);
		str = get_next_line(0);
		while (ft_strncmp(str, limit, (ft_strlen(str) - 1)) != 0)
		{
			ft_putstr_fd(str, pipefd[1]);
			str = get_next_line(0);
		}
		exit(EXIT_SUCCESS);
	}
	ft_daddy(pipefd);
}

void	ft_son(char *comand, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		ft_exec_bonus(comand, envp);
	}
	else
		ft_daddy(pipefd);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 2;
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
			ft_here_doc(argv[2], argc);
		}
		else
		{
			i = 1;
			infile = open(argv[1], O_RDONLY, 0777);
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			dup2(infile, STDIN_FILENO);
		}
		while (i < argc - 2)
			ft_son(argv[++i], envp);
		dup2(outfile, STDOUT_FILENO);
		ft_exec_bonus(argv[argc - 2], envp);
	}
	return (0);
}
