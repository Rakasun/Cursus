/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:46:57 by yfang             #+#    #+#             */
/*   Updated: 2024/05/16 17:36:27 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*---------------------------------   LIBS   ---------------------------------*/
// Global
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

/*--------------------------------   MACROS   --------------------------------*/
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;96m"
# define GREEN "\033[0;32m"
# define ORANGE "\033[0;33m"
# define RED "\033[0;31m"
# define END "\033[0m"

# define MAX_INT 2147483647

/*--------------------------------   STRUCTS   -------------------------------*/
typedef struct s_master
{
	int					nbr_philo;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	int					nb_must_eat;
	long long			start_time;
	int					dead;
	int					finish;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*mutex_dead;
	pthread_mutex_t		*mutex_finish;
	pthread_mutex_t		*mutex_print;
}	t_master;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	long long			last_eat;
	int					nbr_eat;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*mutex_last_eat;
	t_master			*master;
}	t_philo;

/*-------------------------------   FUNCTIONS   ------------------------------*/
void		ft_loop(t_master *master, t_philo *philo);

//	philosophers_utils.c
int			ft_check_av(int ac, char **av);
size_t		get_time(void);
int			ft_all_ok(t_master *master);
void		ft_usleep(t_philo *philo, t_master *master, long long time_to);

//	minilibft.c
long		ft_atol(const char *str);
int			ft_is_num(char *a);
int			ft_strcmp(const char *s1, const char *s2);

//	init.c
void		ft_init_master(t_master *master, char **av);
void		ft_init_philo(t_master *master, t_philo *philo);
void		ft_init_thread(t_master *master, t_philo *philo);

//	rutine.c
void		*ft_rutine(void *arg);

//	msg.c
void		ft_error(int i);
void		ft_msg(t_philo *philo, char *str, char *color);
long long	ft_t(t_philo *philo);

//	free.c
void		ft_free_forks(t_master *master);
void		ft_free(t_master *master, t_philo *philo);

#endif
