/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:19:56 by isporras          #+#    #+#             */
/*   Updated: 2024/07/04 13:20:35 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

// Imprime en la salida STDERR 1 o 2 mensajes enviados como argumento
// y un salto de línea.
void	ft_error_msg(char *s1, char *s2)
{
	if (!s1)
		return ;
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(s1, 2);
	if (s2)
		ft_putstr_fd(s2, 2);
	ft_putstr_fd("\n", 2);
}
