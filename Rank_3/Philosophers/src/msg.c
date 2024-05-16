/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:34:55 by yfang             #+#    #+#             */
/*   Updated: 2024/05/16 15:04:30 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

long long	ft_t(t_philo *philo)
{
	return (get_time() - philo->master->start_time);
}

void	ft_msg(t_philo *philo, char *str, char *color)
{
	if (!ft_strcmp(color, RED))
		printf("%s%lld %d %s%s\n", color, ft_t(philo), philo->id, str, END);
	else if (ft_all_ok(philo->master))
		printf("%s%lld %d %s%s\n", color, ft_t(philo), philo->id, str, END);
}

void	ft_error(int i)
{
	if (i == 1)
		printf("Arguments Error\n");
	else if (i == 2)
		printf("Failed to allocate memory\n");
	else
		printf("Failed to create mutex\n");
	exit(1);
}
