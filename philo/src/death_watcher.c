/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_watcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:53:48 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/22 20:08:52 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
*	Handles locking and printing death message for the first dead Philo.
*	For the rest, it simply unlocks and returns.
*/
bool	death_handler(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->death)
		pthread_mutex_unlock(&philo->data->dead_mutex);
	else
	{
		philo->data->death = true;
		printf("%.4ld %d has died\n", timer(), philo->id + 1);
		pthread_mutex_unlock(&philo->data->dead_mutex);
	}
	return (false);
}

/*
*	Checks if the philosopher given in pointer is dead.
*/
bool	is_dead(t_philo *philo)
{
	int64_t	time_to_die;
	int64_t	time_from_last_meal;

	time_from_last_meal = timer() - (philo)->meal_time;
	time_to_die = (philo)->data->time_to_die;
	return (time_from_last_meal > time_to_die);
}
