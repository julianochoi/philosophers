/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 00:13:28 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/19 23:39:09 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	testing(t_main *data)
{
	int				ret;
	struct timeval	tv;
	int64_t			start;
	int64_t			diff;

	(void) data;
	ret = gettimeofday(&tv, NULL);
	if (ret == -1)
		error_exit(data, "Unable to retrieve time.");
	start = time_now();
	msleep(2000);
	diff = time_diff(start);
	printf("start: %ld\ntime_diff: %ld\n", start, diff);
}

int	main(int argc, char **argv)
{
	t_main	data;

	ft_bzero(&data, sizeof(t_main));
	arg_validation(argc, argv);
	testing(&data);
}
//TODO function to set the forks as mutexes
//TODO implement deadlock preventions
//TODO implement death check
