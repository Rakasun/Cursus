/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:00:12 by yfang             #+#    #+#             */
/*   Updated: 2024/05/16 18:01:25 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_free(t_master *master, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < master->nbr_philo)
	{
		pthread_join(philo[i].thread, NULL);
		pthread_mutex_destroy(philo[i].mutex_last_eat);
		free(philo[i].mutex_last_eat);
		i++;
	}
	ft_free_forks(master);
	pthread_mutex_destroy(master->mutex_dead);
	pthread_mutex_destroy(master->mutex_finish);
	pthread_mutex_destroy(master->mutex_print);
	free(master->mutex_dead);
	free(master->mutex_finish);
	free(master->mutex_print);
	free(philo);
}

void	ft_free_forks(t_master *master)
{
	int	i;

	i = -1;
	while (++i < master->nbr_philo)
		pthread_mutex_destroy(&master->forks[i]);
	free(master->forks);
}
