/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_standard_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 17:46:39 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 18:06:25 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "client.h"

void	standard_input(t_env *e)
{
	char	buff[BUF_SIZE + 1];
	int		r;

	if ((r = x_int(-1, read(STDIN_FILENO, buff, BUF_SIZE), "read")))
	{
		buff[r] = 0;
		client_add(e, buff);
	}
}
