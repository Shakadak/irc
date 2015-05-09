/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 17:16:31 by npineau           #+#    #+#             */
/*   Updated: 2015/05/09 16:35:13 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "server.h"

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

void		help(int cs, t_env *e, char **aarg)
{
	(void)aarg;
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
	char			**aarg;
	static t_cmd	tab[9];
	void			(*cmd)();

	cmd = NULL;
	if (*(e->fds[cs].buf_read) != '/')
		return (0);
	e->fds[cs].buf_read[r - 1] = 0;
	aarg = ft_strsplit(clean_str(e->fds[cs].buf_read), ' ');
	if (tab[0].cmd == NULL)
		fill_commands(tab);
	cmd = get_command(tab, aarg[0]);
	if (cmd)
		cmd(cs, e, aarg);
	else
		unkown_command(cs, e, aarg[0]);
	ft_freesplit((void **)aarg);
	return (1);
}
