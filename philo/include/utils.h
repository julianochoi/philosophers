/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 00:17:20 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/19 22:54:50 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

int64_t	ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

int64_t	time_diff(int64_t start_time);
int64_t	time_now(void);
int64_t	msleep(int64_t time);

#endif
