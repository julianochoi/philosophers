/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:41:51 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/20 18:21:28 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
*	Checks if the arguments provided are only comprised of digits.
*/
static bool	input_validation(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-')
		{
			j++;
			if (!ft_isdigit(argv[i][j]))
				return (false);
		}
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j])
			return (false);
		i++;
	}
	return (true);
}

/*
*	Handles error management for wrong number of arguments, and negative inputs.
*/
bool	arg_validation(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		error_exit(NULL, ERR_ARG_COUNT);
	if (!input_validation(argv))
		error_exit(NULL, ERR_BAD_ARG);
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 0)
			error_exit(NULL, ERR_NEG_ARG);
		i++;
	}
	return (true);
}
