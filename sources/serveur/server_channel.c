/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_channel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:43:21 by npineau           #+#    #+#             */
/*   Updated: 2014/05/23 17:33:41 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void	join(int cs, t_env *e, char *chan)
{
	if (chan == NULL)
		ft_strcat(e->fds[cs].buf_write, "Channel missing.\n");
	else if (*chan != '#')
		ft_strcat(e->fds[cs].buf_write, "Invalid channel. (eg: #bananez)\n");
	else
	{
		ft_strncpy(e->fds[cs].channel, chan, CHAN_SIZE);
		spread(cs, e, e->fds[cs].channel, e->fds[cs].nick);
		spread(cs, e, e->fds[cs].channel, " joined the channel.\n");
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
		ft_strcat(e->fds[cs].buf_write, "Please, join a channel.\n");
		return ;
	}
	while (i < e->maxfd)
	{
		if (e->fds[i].type == FD_CLIENT && ft_strequ(e->fds[i].channel, chan))
		{
			if (i == cs)
				ft_strcat(e->fds[cs].buf_write, "You : ");
			ft_strcat(e->fds[cs].buf_write, e->fds[i].nick);
			ft_strcat(e->fds[cs].buf_write, "\n");
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
			ft_strcat(e->fds[cs].buf_write, "Can't leave this channel.\n");
			return ;
		}
	}
	spread(cs, e, e->fds[cs].channel, e->fds[cs].nick);
	spread(cs, e, e->fds[cs].channel, " left the channel.\n");
	*e->fds[cs].channel = -1;
}
