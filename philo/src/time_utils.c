/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:53:04 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/22 16:23:55 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Returns elapsed time since the function first call, in milliseconds.
*/
int64_t	timer(void)
{
	t_tv			current_time;
	static int64_t	start_time_sec = 0;
	static int64_t	start_time_usec = 0;

	gettimeofday(&current_time, NULL);
	if (!start_time_sec)
	{
		start_time_sec = current_time.tv_sec;
		start_time_usec = current_time.tv_usec;
	}	
	return ((current_time.tv_sec - start_time_sec) * 1000
		+ (current_time.tv_usec - start_time_usec) / 1000);
}

/*
**	@param time: Sleep time in milliseconds
*/
int64_t	msleep(int64_t time)
{
	return (usleep(time * 1000));
}

/*
**	Returns the time difference between the input the timer function.
**	@param start_time Initial time, in milliseconds.
*/
int64_t	time_diff(int64_t start_time)
{
	return (timer() - start_time);
}
