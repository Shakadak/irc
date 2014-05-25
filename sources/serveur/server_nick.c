/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_nick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 18:52:31 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 18:52:54 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

static int	ft_isnick(char *str)
{
	while (*str)
	{
		if (!ft_isalnum(*str))
			return (0);
		str++;
	}
	return (1);
}

void	change_nick(int cs, t_env *e, char *nick)
{
	if (nick == NULL)
		client_add(cs, e, "Nickname missing.\n");
	else if (!ft_isnick(nick))
		client_add(cs, e, "Invalid nickname. (alphanumeric character only)\n");
	else if (get_dest(e, nick) != -1)
		client_add(cs, e, "Nickname unavailable.\n");
	else
	{
		spread(cs, e, e->fds[cs].nick, 0);
		ft_strncpy(e->fds[cs].nick, nick, NICK_SIZE);
		spread(cs, e, " changed his nickname to: ", 0);
		spread(cs, e, e->fds[cs].nick, 0);
		spread(cs, e, ".\n", 0);
		if (*e->fds[cs].channel == -1)
		{
			client_add(cs, e, "Nickname changed to: ");
			client_add(cs, e, e->fds[cs].nick);
			client_add(cs, e, ".\n");
		}
	}
}
