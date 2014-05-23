/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_channel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:43:21 by npineau           #+#    #+#             */
/*   Updated: 2014/05/23 12:02:17 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void	join(int cs, t_env *e, char *chan)
{
	if (chan == NULL)
		ft_strcat(e->fds[cs].buf_write, "Channel missing.\n");
	else if (*chan != '#')
		ft_strcat(e->fds[cs].buf_write, "Invalid channel.\n");
	else
	{
		ft_strncpy(e->fds[cs].channel, chan, CHAN_SIZE);
		ft_strcpy(e->fds[cs].buf_read, "joined the channel\n");
		spread(cs, e, 19, e->fds[cs].channel);
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
	ft_strcpy(e->fds[cs].buf_read, "left the channel.\n");
	spread(cs, e, 18, e->fds[cs].channel);
	*e->fds[cs].channel = -1;
}
