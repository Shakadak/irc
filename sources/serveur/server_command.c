/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 17:16:31 by npineau           #+#    #+#             */
/*   Updated: 2014/06/03 15:53:36 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	help(int cs, t_env *e)
{
	client_add(cs, e, "\n/nick <nickname(max 9 characters,\
otherwise will be truncated)>\n/join <#chan>\n/leave [#currentchan]\n\
/msg <nick> <message>\n/who\n\n");
}

static void	unkown_command(int cs, t_env *e, char *cmd)
{
	client_add(cs, e, "Unknown command: ");
	client_add(cs, e, cmd);
	client_add(cs, e, "\n");
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
	else if (ft_strequ(aarg[0], "/msg"))
		msg(cs, e, aarg);
	else if (ft_strequ(aarg[0], "/join"))
		join(cs, e, aarg[1]);
	else if (ft_strequ(aarg[0], "/leave"))
		leave(cs, e, aarg[1]);
	else if (ft_strequ(aarg[0], "/quit"))
		client_leave(cs, e);
	else if (ft_strequ(aarg[0], "/who"))
		who(cs, e);
	else if (ft_strequ(aarg[0], "/help") || ft_strequ(aarg[0], "/command"))
		help(cs, e);
	else
		unkown_command(cs, e, aarg[0]);
	ft_array_free((void **)aarg);
	return (1);
}
