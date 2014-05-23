/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client_read.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:30:54 by npineau           #+#    #+#             */
/*   Updated: 2014/05/23 17:44:20 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "server.h"
#include "libft.h"

void	spread(int cs, t_env *e, char *chan, char *msg)
{
	int	i;

	if (*e->fds[cs].channel < 0)
	{
		ft_strcat(e->fds[cs].buf_write, "Please, join a channel.\n");
		return ;
	}
	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT && ft_strequ(e->fds[i].channel, chan))
			ft_strcat(e->fds[i].buf_write, msg);
		i++;
	}
}

void	client_read(t_env *e, int cs)
{
	int	r;

	r = x_int(-1, recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0), "recv");
	if (r <= 0)
	{
		close(cs);
		clean_fd(&e->fds[cs]);
		printf("client #%d gone away\n", cs);
	}
	else
	{
		if (!command(cs, e, r))
		{
			spread(cs, e, e->fds[cs].channel, e->fds[cs].nick);
			spread(cs, e, e->fds[cs].channel, ": ");
			spread(cs, e, e->fds[cs].channel, e->fds[cs].buf_read);
		}
		ft_strclr(e->fds[cs].buf_read);
	}
}
