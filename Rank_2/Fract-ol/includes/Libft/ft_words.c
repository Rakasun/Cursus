/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:16:27 by yfang             #+#    #+#             */
/*   Updated: 2023/07/19 12:04:33 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *len)
{
	if (*len == -1)
		return ;
	if (write(1, &c, 1) == -1)
		(*len) = -2;
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)", len));
	while (str[i])
		ft_putchar(str[i++], len);
}
