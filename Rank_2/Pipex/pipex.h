/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:53:19 by yfang             #+#    #+#             */
/*   Updated: 2023/07/20 16:11:41 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "Libft/libft.h"

char	*ft_comand_filter(char *comd, char *str);
char	*ft_path(char **envp);
void	ft_free2(char **dst);
void	ft_error(int i);
void	ft_exec_bonus(char *argv, char **envp);

#endif