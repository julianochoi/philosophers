/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:53:45 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/19 22:54:26 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	mem_size;

	mem_size = nmemb * size;
	array = malloc(mem_size);
	if (!array)
		return (NULL);
	ft_bzero(array, mem_size);
	return (array);
}
