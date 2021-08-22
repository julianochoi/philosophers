/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 00:13:47 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/22 19:21:17 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include "utils.h"
# include "error.h"

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"

typedef struct timeval	t_tv;

typedef struct s_main
{
	int					n;
	int64_t				time_to_die;
	int64_t				time_to_eat;
	int64_t				time_to_sleep;
	int64_t				*start_time;
	int					cycles;
	int					*lock;
	bool				death;
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		dead_mutex;
}			t_main;

typedef struct s_philo
{
	t_main	*data;
	int		id;
	int64_t	meal_time;
}				t_philo;

bool	create_threads(t_main *data);
bool	join_threads(t_main *data);
void	destroy_mutexes(t_main *data);

void	free_data(t_main *data);
void	error_exit(t_main *data, char *msg);

void	*routine(void *philo);
bool	eat_cycle(t_philo *philo);
bool	sleep_cycle(t_philo *philo);
void	print_state(t_philo *philo, char *state);

bool	get_forks(t_philo *philo);
bool	drop_forks(t_philo *philo);

bool	is_dead(t_philo *philo);
bool	death_handler(t_philo *philo);

#endif
