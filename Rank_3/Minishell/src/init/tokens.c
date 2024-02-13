/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:22:15 by yfang             #+#    #+#             */
/*   Updated: 2024/02/13 18:05:33 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* void	ft_init_token()
{
	
} */

void	ft_token(t_shell *shell, char *str)
{
	int		i;
	char	*tmp;
	char	*start;

	i = 0;
	start = str;
	while (*str && !ft_isspecial(*str))
	{
		str++;
		i++;
	}
	tmp = ft_strndup(*start, i);
	ft_init_token(shell, ARG, )

}

t_tokens	*ft_tokenizer(t_shell *shell)
{
	char	*tmp;

	tmp = shell->line;
	while (*tmp)
	{
		if ((!ft_isspecial(*tmp)))
			ft_token(shell, &tmp);
		else if (ft_isspace(*tmp))
			ft_token_in_space(shell, &tmp);
		tmp++;
	}
}
