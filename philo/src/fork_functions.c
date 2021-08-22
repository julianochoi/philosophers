/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:41:50 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/22 19:59:24 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	odd_case(t_philo *philo)
{
	t_main	*data;
	int		id;

	data = philo->data;
	id = philo->id;
	pthread_mutex_lock(&(data->forks[(id + 1) % data->n]));
	pthread_mutex_lock(&(data->forks[id]));
	if (data->lock[(id + 1) % data->n] == -1 && data->lock[id] == -1)
	{
		data->lock[(id + 1) % data->n] = id;
		data->lock[id] = id;
		print_state(philo, FORK);
		print_state(philo, FORK);
	}
	pthread_mutex_unlock(&(data->forks[(id + 1) % data->n]));
	pthread_mutex_unlock(&(data->forks[id]));
}

static void	even_case(t_philo *philo)
{
	t_main	*data;
	int		id;

	data = philo->data;
	id = philo->id;
	pthread_mutex_lock(&(data->forks[id]));
	pthread_mutex_lock(&(data->forks[(id + 1) % data->n]));
	if (data->lock[(id + 1) % data->n] == -1 && data->lock[id] == -1)
	{
		data->lock[(id + 1) % data->n] = id;
		data->lock[id] = id;
		print_state(philo, FORK);
		print_state(philo, FORK);
	}
	pthread_mutex_unlock(&(data->forks[id]));
	pthread_mutex_unlock(&(data->forks[(id + 1) % data->n]));
}

static bool	forever_alone_case(t_philo *philo)
{
	t_main	*data;
	int		id;

	data = philo->data;
	id = philo->id;
	while (true)
	{
		if (data->lock[id] == -1)
		{
			data->lock[id] = id;
			print_state(philo, FORK);
		}
		if (is_dead(philo))
			return (death_handler(philo));
		usleep(100);
	}
}

bool	get_forks(t_philo *philo)
{
	t_main	*data;
	int		id;

	data = philo->data;
	id = philo->id;
	if (data->n == 1)
		return (forever_alone_case(philo));
	while (!data->death)
	{
		if (id % 2)
			odd_case(philo);
		else
			even_case(philo);
		if (is_dead(philo))
			return (death_handler(philo));
		if (data->lock[id] == id && data->lock[(id + 1) % data->n] == id)
			return (!(data->death));
	}
	return (false);
}

/*
*	Indicates through data->lock that the i-th and (i+1)-th fork are available
*/
bool	drop_forks(t_philo *philo)
{
	t_main	*data;
	int		id;

	data = philo->data;
	id = philo->id;
	data->lock[id] = -1;
	data->lock[(id + 1) % data->n] = -1;
	return (!data->death);
}
