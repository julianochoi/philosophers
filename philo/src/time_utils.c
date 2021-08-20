/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:53:04 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/17 23:52:52 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	Returns the time difference between now and the argument start_time.
**	@param start_time: Required to be in milliseconds since Epoch.
*/
int64_t	time_diff(int64_t start_time)
{
	return ((time_now() - start_time));
}

/*
**	Returns elapsed time from Epoch in milliseconds.
*/
int64_t	time_now(void)
{
	t_tv	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/*
**	@param time: Sleep time in milliseconds
*/
int64_t	msleep(int64_t time)
{
	return (usleep(time * 1000));
}
