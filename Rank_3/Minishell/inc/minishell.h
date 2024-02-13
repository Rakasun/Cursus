/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:40:30 by yfang             #+#    #+#             */
/*   Updated: 2024/02/13 18:06:22 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*---------------------------------   LIBS   ---------------------------------*/
# include "Libft/libft.h"
// Global
# include <readline/readline.h>
# include <readline/history.h>

/*--------------------------------   MACROS   --------------------------------*/
// Types
# define BUILTING 0
# define ARG 1
# define TEX 2
# define DOUBLE 3
# define SIMPLE 4
# define OUT 5
# define IN 6
# define APPEND 7
# define INSOURCE 8
# define PIPE 9

// Std
# define STDIN 0
# define STDOUT 1

// Colors
# define RESET "\033[0;m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"

/*--------------------------------   STRUCTS   -------------------------------*/
typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_tokens
{
	char			*str;
	int				type;
	int				space;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_shell
{
	t_env			*env;
	t_tokens		*tokens;
	char			**envp;
	char			*line;
}	t_shell;

/*-------------------------------   FUNCTIONS   ------------------------------*/
//	Init
//		init
void	ft_init(t_shell	*shell, char **envp);
//	Utils
//		messages
void	ft_welcome(void);
//		is
int		ft_isspace(int c);
//		libftplus
char	*ft_strndup(const char *s, size_t n);

#endif