/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:29:07 by yfang             #+#    #+#             */
/*   Updated: 2024/04/12 18:11:06 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_isredi(int c)
{
	if (c >= OUT && c <= HERE_DOC)
		return (1);
	return (0);
}

int	ft_ifredi(char c)
{
	return (c == '>' || c == '<');
}

int	ft_spandchar(char c)
{
	return (ft_isalnum(c) || c == '_' || c == '~');
}

int	ft_isspecial(char c)
{
	return (c == ' ' || c == '\"' || c == '\'' || c == '>' || c == '<'
		|| c == '|');
}

int	ft_isspace(int c)
{
	return (c == ' ');
}
