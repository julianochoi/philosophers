/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:00:03 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/22 20:21:31 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_ptr)
{
	t_philo	*philo;
	int		cycles;

	philo = (t_philo *)philo_ptr;
	cycles = philo->data->cycles;
	while (cycles--)
	{
		if (!get_forks(philo))
			break ;
		if (!eat_cycle(philo))
			break ;
		if (!drop_forks(philo))
			break ;
		if (!sleep_cycle(philo))
			break ;
		print_state(philo, THINK);
		usleep(1000);
	}
	free(philo_ptr);
	return (NULL);
}

bool	eat_cycle(t_philo *philo)
{
	int64_t	time;

	time = timer();
	philo->meal_time = time;
	print_state(philo, EAT);
	while (time_diff(time) < philo->data->time_to_eat)
	{
		if (is_dead(philo))
			return (death_handler(philo));
		if (philo->data->death)
			return (false);
		usleep(100);
	}
	return (true);
}

bool	sleep_cycle(t_philo *philo)
{
	int64_t	time;

	time = timer();
	print_state(philo, SLEEP);
	while (time_diff(time) < philo->data->time_to_sleep)
	{
		if (is_dead(philo))
			return (death_handler(philo));
			//should the id be index+1?
		if (philo->data->death)
			return (false);
		usleep(100);
	}
	return (true);
}

void	print_state(t_philo *philo, char *state)
{
	pthread_mutex_lock(&(philo->data->dead_mutex));
	if (!philo->data->death)
	{
		if (!ft_strcmp(state, FORK)
			|| !ft_strcmp(state, EAT)
			|| !ft_strcmp(state, SLEEP)
			|| !ft_strcmp(state, THINK))
			printf("%.4ld %d %s\n", timer(), philo->id + 1, state);
	}
	pthread_mutex_unlock(&(philo->data->dead_mutex));
}
