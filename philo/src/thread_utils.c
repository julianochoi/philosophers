/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:46:17 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/22 20:05:36 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_main *data, int i)
{
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->data = data;
	philo->id = i;
	return (philo);
}

bool	create_threads(t_main *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->n)
	{
		philo = init_philo(data, i);
		if (!philo)
			return (false);
		if (pthread_create(&data->threads[i], NULL, &routine,
			(void *)philo) != 0)
		{
			print_error_msg(ERR_THD_CREAT);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	join_threads(t_main *data)
{
	int	i;

	i = 0;
	while (i < data->n)
	{
		if (pthread_join(data->threads[i], NULL) != 0)
		{
			print_error_msg(ERR_THD_JOIN);
			return (false);
		}
		i++;
	}
	return (true);
}

void	destroy_mutexes(t_main *data)
{
	int	i;

	i = 0;
	while (i < data->n)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&data->dead_mutex);
}
