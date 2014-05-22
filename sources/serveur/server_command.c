/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 17:16:31 by npineau           #+#    #+#             */
/*   Updated: 2014/05/22 15:10:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "server.h"
#include "libft.h"

static void	change_nick(int cs, t_env *e)
{
	ft_strncpy(e->fds[cs].nick, e->fds[cs].buf_read + 6, NICK_SIZE);
	send(cs, "Nickname changed to: ", 21, 0);
	send(cs, e->fds[cs].nick, ft_strlen(e->fds[cs].nick), 0);
	send(cs, ".\n", 2, 0);
}

static void	join(int cs, t_env *e, int channel)
{
	char	*chan;

	if (channel < 0)
	{
		send(cs, "Can't join negative channel.\n", 29, 0);
		return ;
	}
	e->fds[cs].channel = channel;
	chan = ft_itoa(e->fds[cs].channel);
	send(cs, "Channel changed to: ", 20, 0);
	send(cs, chan, ft_strlen(chan), 0);
	send(cs, ".\n", 2, 0);
	ft_strdel(&chan);
}

static void	who(int cs, t_env *e)
{
	int		i;
	int		chan;

	chan = e->fds[cs].channel;
	i = 0;
	if (chan < 0)
	{
		send(cs, "Please, join a channel.\n", 24, 0);
		return ;
	}
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT && e->fds[i].channel == chan)
		{
			if (i == cs)
				send(cs, "You", 3, 0);
			else
				send(cs, e->fds[i].nick, NICK_SIZE, 0);
			send(cs, "\n", 1, 0);
		}
		i++;
	}
}

static void	leave(int cs, t_env *e)
{
	int		chan;

	chan = e->fds[cs].channel;
	if (e->fds[cs].buf_read[6] == ' ')
		chan = ft_atoi(e->fds[cs].buf_read + 7);
	else if (e->fds[cs].buf_read[6] != 0)
		return ;
	if (e->fds[cs].channel != chan)
	{
		send(cs, "Can't leave a channel you aren't in\n", 36, 0);
		return ;
	}
	e->fds[cs].channel = -1;
	send(cs, "Channel left.\n", 14, 0);
}

int			command(int cs, t_env *e, int r)
{
	if (*(e->fds[cs].buf_read) != '/')
		return (0);
	e->fds[cs].buf_read[r - 1] = 0;
	if (!strncmp(e->fds[cs].buf_read, "/nick ", 6))
		change_nick(cs, e);
	else if (!strncmp(e->fds[cs].buf_read, "/join ", 6))
		join(cs, e, ft_atoi(e->fds[cs].buf_read + 6));
	else if (!strncmp(e->fds[cs].buf_read, "/leave", 5))
		leave(cs, e);
	else if (!strcmp(e->fds[cs].buf_read, "/who"))
		who(cs, e);
	else
		send(cs, "Unknown command.\n", 17, 0);
	return (1);
}
