/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:48:11 by yfang             #+#    #+#             */
/*   Updated: 2023/05/29 17:52:03 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putptr(unsigned long long ptr, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_putunsint(unsigned int i, int *len);
void	ft_puthexa(unsigned long long nb, char x, int *len);
int		ft_printf(char const *str, ...);

#endif