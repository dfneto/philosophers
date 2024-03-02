/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:34:11 by davifern          #+#    #+#             */
/*   Updated: 2024/03/02 10:45:35 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_god t_god;
typedef struct s_philo
{
	int				id;
	int				times_eaten;
	long long		fasting;
	pthread_t		td;
	pthread_mutex_t	m_fasting;
	t_god			*god;
}   t_philo;

typedef struct s_god
{
	int				all_alive;
	int				n_times_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_philo;
	long long		start;
	pthread_mutex_t	m_print;
	pthread_mutex_t	mutex_all_alive;
	pthread_mutex_t	*mutex_fork;
	t_philo			*philo;
}	t_god;

typedef enum
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
} status;

void			*routine(void *philo_data);
void			create_philos_and_start_threads(t_god *god, void *routine(void *));
int				define_left_fork(t_philo *philo);
void			clean_and_destroy(t_god *god);
void			wait_threads(t_god *god);
void			print(t_philo *philo, int status);
int             ft_atoi(const char *str);
int             check_input(int argc, char **argv);
int				philosopher_died(t_philo *philo);
int				all_alive(t_god *god);
long long		get_time(long long start);
long long		get_start_time(void);
t_god			*create_god(char **argv);
void		 	set_philo_to_start(t_philo *philo);
#endif