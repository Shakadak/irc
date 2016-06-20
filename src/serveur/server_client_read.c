/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client_read.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:30:54 by npineau           #+#    #+#             */
/*   Updated: 2014/06/14 15:40:59 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "inc/server.h"
#include "libft/inc/libft.h"

void		spread(int cs, t_env *e, char *msg, int first)
{
	int		i;
	char	*chan;

	if (*e->fds[cs].channel < 0)
	{
		if (first)
			client_add(cs, e, "Please, join a channel.\n");
		return ;
	}
	chan = e->fds[cs].channel;
	i = 0;
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT && ft_strequ(e->fds[i].channel, chan))
			client_add(i, e, msg);
		i++;
	}
}

void		client_leave(int cs, t_env *e, char **aarg)
{
	(void)aarg;
	close(cs);
	rb_free(&e->fds[cs].q);
	clean_fd(&e->fds[cs]);
	printf("client #%d gone away\n", cs);
}

void		client_read(t_env *e, int cs)
{
	int	r;
	int	count;

	count = e->fds[cs].fr;
	r = recv(cs, e->fds[cs].buf_read + count, MSG_SIZE - count, 0);
	x_int(-1, r, "recv");
	if (r <= 0)
		client_leave(cs, e, NULL);
	else
	{
		e->fds[cs].fr += r;
		if (!ft_strchr(e->fds[cs].buf_read, '\n') && e->fds[cs].fr != MSG_SIZE)
			return ;
		if (!command(cs, e, e->fds[cs].fr))
		{
			spread(cs, e, e->fds[cs].nick, 1);
			spread(cs, e, ": ", 0);
			spread(cs, e, e->fds[cs].buf_read, 0);
		}
		ft_strclr(e->fds[cs].buf_read);
		e->fds[cs].fr = 0;
	}
}
