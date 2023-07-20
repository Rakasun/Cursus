/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:13:15 by yfang             #+#    #+#             */
/*   Updated: 2023/07/20 16:12:11 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free2(char **dst)
{
	int	i;

	i = 0;
	while (dst[i])
		free(dst[i++]);
	free(dst);
}

char	*ft_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	return (envp[i]);
}

char	*ft_comand_filter(char *comd, char *str)
{
	char	**path;
	int		i;
	int		find;
	char	*aux;
	char	*tmp;

	path = ft_split(str, ':');
	i = 0;
	find = 1;
	while (path[i] && find != 0)
	{
		tmp = ft_strjoin(path[i++], "/");
		aux = ft_strjoin(tmp, comd);
		find = access(aux, F_OK);
		free(aux);
	}
	tmp = ft_strjoin(path[--i], "/");
	aux = ft_strjoin(tmp, comd);
	free(tmp);
	tmp = ft_strdup(aux);
	free(aux);
	ft_free2(path);
	return (tmp);
}

void	ft_error(int i)
{
	if (i == 0)
		perror("Error: nº incorrecto de argumentos.\n"
			"Ejemplo: ./pipex infile cmd1 cmd2 outfile");
	if (i == 1)
		perror("Error minimo 6 argumentos.\n"
			"Ej.: ./pipex_bonus here_doc LIMITER cmd1 cmd2 outfile");
}

void	ft_exec_bonus(char *argv, char **envp)
{
	char	*str;
	char	*path;
	char	**comand;

	comand = ft_split(argv, ' ');
	str = ft_path(envp);
	path = ft_comand_filter(comand[0], str + 5);
	if (path == NULL)
		perror(strerror(ENOENT));
	if (execve(path, comand, NULL) == -1)
		perror(argv);
}
