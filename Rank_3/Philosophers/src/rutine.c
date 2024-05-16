/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:14:46 by yfang             #+#    #+#             */
/*   Updated: 2024/05/16 20:07:54 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_hand(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		ft_msg(philo, "has taken a fork", ORANGE);
		pthread_mutex_lock(philo->r_fork);
		ft_msg(philo, "has taken a fork", ORANGE);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		ft_msg(philo, "has taken a fork", ORANGE);
		pthread_mutex_lock(philo->l_fork);
		ft_msg(philo, "has taken a fork", ORANGE);
	}
}

void	ft_eat(t_philo *philo)
{
	t_master	*master;

	master = philo->master;
	ft_hand(philo);
	ft_msg(philo, "is eating", GREEN);
	pthread_mutex_lock(philo->mutex_last_eat);
	philo->last_eat = ft_time(philo);
	pthread_mutex_unlock(philo->mutex_last_eat);
	philo->nbr_eat++;
	pthread_mutex_lock(master->mutex_finish);
	if (philo->nbr_eat == master->nb_must_eat)
		master->finish++;
	pthread_mutex_unlock(master->mutex_finish);
	ft_usleep(philo, master, philo->last_eat + master->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	ft_sleep(t_philo *philo)
{
	long long	time;

	time = ft_time(philo) + philo->master->time_to_sleep;
	ft_msg(philo, "is sleeping", BLUE);
	ft_usleep(philo, philo->master, time);
}

void	ft_think(t_philo *philo)
{
	long long	time;
	t_master	*tmp;

	tmp = philo->master;
	time = (tmp->time_to_die - (tmp->time_to_eat + tmp->time_to_sleep)) / 4;
	ft_msg(philo, "is thinking", YELLOW);
	ft_usleep(philo, philo->master, ft_time(philo) + time);
}

void	*ft_rutine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (ft_time(philo) < 0)
	{
		pthread_mutex_lock(philo->mutex_last_eat);
		philo->last_eat = ft_time(philo);
		pthread_mutex_unlock(philo->mutex_last_eat);
		usleep(20);
	}
	if (philo->id % 2 == 0)
		usleep(50);
	while (ft_all_ok(philo->master))
	{
		if (ft_all_ok(philo->master))
			ft_eat(philo);
		if (ft_all_ok(philo->master))
			ft_sleep(philo);
		if (ft_all_ok(philo->master))
			ft_think(philo);
	}
	return (NULL);
}
