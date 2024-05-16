/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:13:57 by yfang             #+#    #+#             */
/*   Updated: 2024/05/16 17:28:09 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_usleep(t_philo *philo, t_master *master, long long time_to)
{
	while (ft_all_ok(master) && ft_t(philo) < time_to)
		usleep(50);
}

int	ft_all_ok(t_master *master)
{
	int	i;

	pthread_mutex_lock(master->mutex_dead);
	pthread_mutex_lock(master->mutex_finish);
	if (master->finish == master->nbr_philo || master->dead == 1)
		i = 0;
	else
		i = 1;
	pthread_mutex_unlock(master->mutex_dead);
	pthread_mutex_unlock(master->mutex_finish);
	return (i);
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == 1)
		printf("gettimeofay() failure\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_check_av(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 6)
		if (ft_atol(av[5]) < 0)
			return (0);
	if (ac == 5 || ac == 6)
	{
		if (ft_atol(av[1]) > 200 || ft_atol(av[1]) < 1 || ft_atol(av[2]) < 0
			|| ft_atol(av[3]) < 0 || ft_atol(av[4]) < 0)
			return (0);
		while (av[++i])
		{
			if (!ft_is_num(av[i]))
				return (0);
		}
	}
	else
		return (0);
	return (1);
}
