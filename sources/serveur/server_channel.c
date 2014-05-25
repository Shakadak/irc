/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_channel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:43:21 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 12:36:36 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void	join(int cs, t_env *e, char *chan)
{
	if (chan == NULL)
		client_add(cs, e, "Channel missing.\n");
	else if (*chan != '#')
		client_add(cs, e, "Invalid channel. (eg: #bananez)\n");
	else
	{
		ft_strncpy(e->fds[cs].channel, chan, CHAN_SIZE);
		spread(cs, e, e->fds[cs].nick, 1);
		spread(cs, e, " joined the channel.\n", 0);
	}
}

void	who(int cs, t_env *e)
{
	int		i;
	char	*chan;

	chan = e->fds[cs].channel;
	i = 0;
	if (*chan < 0)
	{
		client_add(cs, e, "Please, join a channel.\n");
		return ;
	}
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT && ft_strequ(e->fds[i].channel, chan))
		{
			if (i == cs)
				client_add(cs, e, "You : ");
			client_add(cs, e, e->fds[i].nick);
			client_add(cs, e, "\n");
		}
		i++;
	}
}

void	leave(int cs, t_env *e, char *chan)
{
	if (chan)
	{
		if (!ft_strequ(e->fds[cs].channel, chan))
		{
			client_add(cs, e, "Can't leave this channel: ");
			client_add(cs, e, chan);
			client_add(cs, e, "\n");
			return ;
		}
	}
	spread(cs, e, e->fds[cs].nick, 1);
	spread(cs, e, " left the channel.\n", 0);
	*e->fds[cs].channel = -1;
}
