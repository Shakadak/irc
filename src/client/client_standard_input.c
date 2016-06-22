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
#include "inc/client.h"

void	standard_input(t_env *e)
{
	char	buff[BUF_SIZE + 1];
	int		r;

	if ((r = x_int(-1, read(STDIN_FILENO, buff, BUF_SIZE), "read")))
	{
		buff[r] = 0;
		if (strnequ(buff, "/connect ", 9))
			e->sock = client_connect(e->sock, buff);
		else if (e->sock == -1)
			write(STDIN_FILENO, "Please connect to a server"
					" before attempting anything else.\n", 60);
		else
			client_add(e, buff);
	}
}
