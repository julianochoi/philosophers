/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 00:13:28 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/22 20:06:02 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	build_data(t_main *data, int argc, char **argv)
{
	int	i;

	data->n = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->cycles = ft_atoi(argv[5]);
	data->threads = ft_calloc(data->n, sizeof(pthread_t));
	data->forks = ft_calloc(data->n, sizeof(pthread_mutex_t));
	data->lock = ft_calloc(data->n, sizeof(int));
	data->start_time = ft_calloc(data->n, sizeof(int64_t));
	if (!(data->threads && data->forks && data->lock))
		return (false);
	i = 0;
	while (i < data->n)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
			return (false);
		data->lock[i] = -1;
		i++;
	}
	if (pthread_mutex_init(&(data->dead_mutex), NULL) != 0)
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_main	data;

	ft_bzero(&data, sizeof(t_main));
	data.cycles = -1;
	arg_validation(argc, argv);
	if (!build_data(&data, argc, argv))
		error_exit(&data, "Error building data");
	if (!(create_threads(&data) && (join_threads(&data))))
		error_exit(&data, NULL);
	destroy_mutexes(&data);
	free_data(&data);
	return (0);
}
