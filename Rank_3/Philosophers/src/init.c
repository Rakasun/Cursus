/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:14:48 by yfang             #+#    #+#             */
/*   Updated: 2024/05/16 17:37:57 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_init_thread(t_master *master, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < master->nbr_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, ft_rutine, &philo[i]) != 0)
			ft_error(3);
		i++;
	}
	ft_loop(master, philo);
	ft_free(master, philo);
}

void	ft_init_mutex_philo(t_philo *philo)
{
	philo->mutex_last_eat = malloc(sizeof(pthread_mutex_t));
	if (!philo->mutex_last_eat)
		ft_error(2);
	if (pthread_mutex_init(philo->mutex_last_eat, NULL) != 0)
		ft_error(0);
}

void	ft_init_philo(t_master *master, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < master->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].last_eat = 0;
		philo[i].nbr_eat = 0;
		if (philo[i].id == master->nbr_philo)
		{
			philo[i].l_fork = &master->forks[i];
			philo[i].r_fork = &master->forks[0];
		}
		else
		{
			philo[i].l_fork = &master->forks[i];
			philo[i].r_fork = &master->forks[i + 1];
		}
		ft_init_mutex_philo(&philo[i]);
		philo[i].master = master;
	}
}

void	ft_init_mutex_master(t_master *master)
{
	master->forks = malloc(sizeof(pthread_mutex_t) * master->nbr_philo);
	master->mutex_dead = malloc(sizeof(pthread_mutex_t));
	master->mutex_finish = malloc(sizeof(pthread_mutex_t));
	master->mutex_print = malloc(sizeof(pthread_mutex_t));
	if (!master->forks || !master->mutex_dead
		|| !master->mutex_finish || !master->mutex_print)
		ft_error(2);
	if (pthread_mutex_init(master->mutex_dead, NULL) != 0)
		ft_error(0);
	if (pthread_mutex_init(master->mutex_finish, NULL) != 0)
		ft_error(0);
	if (pthread_mutex_init(master->mutex_print, NULL) != 0)
		ft_error(0);
}

void	ft_init_master(t_master *master, char **av)
{
	int	i;

	i = 0;
	master->nbr_philo = ft_atol(av[1]);
	master->time_to_die = ft_atol(av[2]);
	master->time_to_eat = ft_atol(av[3]);
	master->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		master->nb_must_eat = ft_atol(av[5]);
	else
		master->nb_must_eat = -1;
	master->start_time = get_time() + master->nbr_philo * 20;
	ft_init_mutex_master(master);
	master->dead = 0;
	master->finish = 0;
	while (i < master->nbr_philo)
	{
		if (pthread_mutex_init(&master->forks[i++], NULL) != 0)
		{
			ft_free_forks(master);
			free(0);
		}
	}
}
