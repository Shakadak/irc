/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 17:16:31 by npineau           #+#    #+#             */
/*   Updated: 2014/05/23 12:38:25 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include "server.h"
#include "libft.h"

static char	*clean_str(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (*tmp == '\t')
			*tmp = ' ';
		tmp++;
	}
	return (str);
}

static void	change_nick(int cs, t_env *e, char *nick)
{
	if (nick == NULL)
	{
		ft_strcat(e->fds[cs].buf_write, "Nickname missinig.\n");
		return ;
	}
	ft_strncpy(e->fds[cs].nick, nick, NICK_SIZE);
	ft_strcat(e->fds[cs].buf_write, "Nickname changed to: ");
	ft_strcat(e->fds[cs].buf_write, e->fds[cs].nick);
	ft_strcat(e->fds[cs].buf_write, ".\n");
}

int			command(int cs, t_env *e, int r)
{
	char	**aarg;

	if (*(e->fds[cs].buf_read) != '/')
		return (0);
	e->fds[cs].buf_read[r - 1] = 0;
	aarg = ft_strsplit(clean_str(e->fds[cs].buf_read), ' ');
	if (ft_strnequ(aarg[0], "/nick", 6))
		change_nick(cs, e, aarg[1]);
	else if (ft_strnequ(aarg[0], "/join", 7))
		join(cs, e, aarg[1]);
	else if (ft_strnequ(aarg[0], "/leave", 5))
		leave(cs, e, aarg[1]);
	else if (ft_strequ(aarg[0], "/who"))
		who(cs, e);
	else
		ft_strcat(e->fds[cs].buf_write, "Unknown command.\n");
	ft_array_free((void ***)&aarg);
	return (1);
}
