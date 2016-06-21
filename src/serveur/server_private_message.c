/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_private_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:27:19 by npineau           #+#    #+#             */
/*   Updated: 2015/05/09 16:29:15 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"

int		get_dest(t_env *e, char *target)
{
	int	i;

	i = 0;
	while (i < e->maxfd)
	{
		if (ft_strequ(e->fds[i].nick, target))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	msg(int cs, t_env *e, char **arg)
{
	int		dest;
	int		i;
	char	nuff[BUF_SIZE + 1];

	if (arg[1] == NULL)
		client_add(cs, e, "Destination and message missing.\n");
	else if (arg[2] == NULL)
		client_add(cs, e, "Message mising.\n");
	else
	{
		if ((dest = get_dest(e, arg[1])) == -1)
			client_add(cs, e, "Invalid nickname.\n");
		else
		{
			i = 2;
			ft_strcat(ft_strcat(nuff, "from "), e->fds[cs].nick);
			ft_strcat(nuff, ":");
			while (arg[i])
			{
				ft_strcat(ft_strcat(nuff, " "), arg[i++]);
			}
			client_add(dest, e, ft_strcat(nuff, "\n"));
		}
	}
}
