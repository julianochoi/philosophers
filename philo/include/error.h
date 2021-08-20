/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 22:55:57 by jchoi-ro          #+#    #+#             */
/*   Updated: 2021/08/19 23:21:22 by jchoi-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <errno.h>
# include "text_colors.h"

# define ERR_ARG_COUNT "Wrong number of arguments."
# define ERR_BAD_ARG "Argument is badly formatted."
# define ERR_NEG_ARG "Argument is negative."
# define ERR_THD_CREAT	"pthread_create error."
# define ERR_THD_JOIN	"pthread_join error."

void	print_error_msg(char *msg);
bool	arg_validation(int argc, char **argv);
void	error_exit(t_main *data, char *msg);

#endif
