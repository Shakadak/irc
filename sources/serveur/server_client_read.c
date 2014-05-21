/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client_read.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:30:54 by npineau           #+#    #+#             */
/*   Updated: 2014/05/21 17:32:13 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "server.h"
#include "libft.h"

static void	spread(int cs, t_env *e, int r)
{
	int	i;

	i = 0;
	while (i < e->maxfd)
	{
		if ((e->fds[i].type == FD_CLIENT) && (i != cs))
		{
			send(i, e->fds[cs].nick, NICK_SIZE, 0);
			send(i, ": ", 2, 0);
			send(i, e->fds[cs].buf_read, r, 0);
		}
		i++;
	}
}

void	client_read(t_env *e, int cs)
{
	int	r;

	r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
	if (r <= 0)
	{
		close(cs);
		clean_fd(&e->fds[cs]);
		printf("client #%d gone away\n", cs);
	}
	else
	{
		if (command(cs, e, r))
			return ;
		spread(cs, e, r);
	}
}
