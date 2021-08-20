/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 00:13:47 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/19 23:29:38 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "utils.h"
# include "error.h"

# define FORK	" has taken a fork"
# define EAT	" is eating"
# define SLEEP	" is eating"
# define THINK	" is thinking"
# define DIE	" died"

typedef struct timeval	t_tv;

typedef struct s_main
{
	int					n;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					cycles;
	int					*lock;
	bool				death;
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		dead;
}			t_main;

typedef struct s_philo
{
	t_main	*data;
	int		id;
	int64_t	meal_time;
}				t_philo;

bool	create_threads(t_main *data);
bool	join_threads(t_main *data);

#endif
