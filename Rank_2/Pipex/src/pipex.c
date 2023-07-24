/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:37:09 by yfang             #+#    #+#             */
/*   Updated: 2023/07/24 12:44:09 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_father(char **argv, char **envp, int *pipefd)
{
	char	*str;
	char	*path;
	char	**comand;
	int		fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	comand = ft_split(argv[3], ' ');
	str = ft_path(envp);
	path = ft_comand_filter(comand[0], str + 5);
	if (path == NULL)
		return (perror(strerror(ENOENT)));
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	close(pipefd[0]);
	close(fd);
	if (execve(path, comand, NULL) == -1)
	{
		free(path);
		ft_free2(comand);
		return (perror(argv[3]));
	}
}

void	ft_child(char **argv, char **envp, int *pipefd)
{
	char	*str;
	char	*path;
	char	**comand;
	int		fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd < 0)
		exit(1);
	comand = ft_split(argv[2], ' ');
	str = ft_path(envp);
	path = ft_comand_filter(comand[0], str + 5);
	if (path == NULL)
		return (perror(strerror(ENOENT)));
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd);
	if (execve(path, comand, NULL) == -1)
		return (perror(argv[2]));
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 5)
		ft_error(0);
	if (pipe(pipefd) == -1)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
		ft_child(argv, envp, pipefd);
	else
	{
		wait(0);
		ft_father(argv, envp, pipefd);
	}
	return (0);
}
