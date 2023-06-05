/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:54:01 by yfang             #+#    #+#             */
/*   Updated: 2023/06/05 19:55:19 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*save_and_clear(char *str);
char	*ft_get_line(char *str);
char	*join_and_free(char *str, char *tmp);
char	*find_line(int fd, char *str);
size_t	ft_strlen(const char *a, int b);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);

#endif