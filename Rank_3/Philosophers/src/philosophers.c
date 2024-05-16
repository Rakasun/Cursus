/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:46:59 by yfang             #+#    #+#             */
/*   Updated: 2024/05/16 19:45:56 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_dead(t_master *master, t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(philo->mutex_last_eat);
	time = ft_time(philo) - philo->last_eat;
	pthread_mutex_unlock(philo->mutex_last_eat);
	if (time >= master->time_to_die)
	{
		ft_msg(philo, "died", RED);
		pthread_mutex_lock(master->mutex_dead);
		master->dead = 1;
		pthread_mutex_unlock(master->mutex_dead);
		return (1);
	}
	return (0);
}

void	ft_loop(t_master *master, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < master->nbr_philo)
		{
			if (ft_dead(master, &philo[i]))
				break ;
			i++;
		}
		if (!ft_all_ok(master))
			break ;
	}
}

int	main(int ac, char **av)
{
	t_master	master;
	t_philo		*philo;

	if (!ft_check_av(ac, av))
		ft_error(1);
	ft_init_master(&master, av);
	philo = malloc(sizeof(t_philo) * master.nbr_philo);
	if (!philo)
		ft_error(2);
	ft_init_philo(&master, philo);
	ft_init_thread(&master, philo);
	return (0);
}
