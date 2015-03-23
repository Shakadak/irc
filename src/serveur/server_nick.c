/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_nick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 18:52:31 by npineau           #+#    #+#             */
/*   Updated: 2014/06/14 15:36:31 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void	change_nick(int cs, t_env *e, char **nick)
{
	if (nick[1] == NULL)
		client_add(cs, e, "Nickname missing.\n");
	else if (!ft_isx(nick[1], ft_isalnum))
		client_add(cs, e, "Invalid nickname. (alphanumeric character only)\n");
	else if (get_dest(e, nick[1]) != -1)
		client_add(cs, e, "Nickname unavailable.\n");
	else
	{
		spread(cs, e, e->fds[cs].nick, 0);
		ft_strncpy(e->fds[cs].nick, nick[1], NICK_SIZE);
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
