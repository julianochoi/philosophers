/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:50:27 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/15 22:59:39 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isspace(int c)
{
	return ((c == ' ')
		|| (c == '\n')
		|| (c == '\t')
		|| (c == '\r')
		|| (c == '\f')
		|| (c == '\v'));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int64_t	ft_atoi(const char *str)
{
	int		sign;
	int64_t	num;
	size_t	pos;

	if (!str)
		return (0);
	sign = 1;
	num = 0;
	pos = 0;
	while (str[pos] && ft_isspace(str[pos]))
		pos++;
	if (str[pos] && (str[pos] == '+' || str[pos] == '-'))
	{
		if (str[pos] == '-')
			sign = -1;
		pos++;
	}
	while (str[pos] && ft_isdigit(str[pos]))
	{
		num = (num * 10) + (str[pos] - '0');
		pos++;
	}
	return (num * sign);
}
