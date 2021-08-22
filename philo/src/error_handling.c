/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 00:55:16 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/20 17:08:36 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_main *data)
{
	if (!data)
		return ;
	if (data->threads)
		free(data->threads);
	if (data->forks)
		free(data->forks);
	if (data->lock)
		free(data->lock);
	if (data->start_time)
		free(data->start_time);
}

void	print_error_msg(char *msg)
{
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
}

void	error_exit(t_main *data, char *msg)
{
	write(2, "Error\n", 6);
	print_error_msg(msg);
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}
