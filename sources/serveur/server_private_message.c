/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_private_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:27:19 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 13:03:59 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

int		get_dest(t_env *e, char *target)
{
	int	i;

	i = 0;
	while (i < e->maxfd)
	{
		if (ft_strequ(e->fds[i].nick, target))
			return (i);
		i++;
	}
	return (-1);
}

void	msg(int cs, t_env *e, char **arg)
{
	int	dest;
	int	i;

	if (arg[1] == NULL)
		client_add(cs, e, "Destination and message mising.\n");
	else if (arg[2] == NULL)
		client_add(cs, e, "Message mising.\n");
	else
	{
		if ((dest = get_dest(e, arg[1])) == -1)
			client_add(cs, e, "Invalid nickname.\n");
		else
		{
			i = 2;
			client_add(dest, e, "from ");
			client_add(dest, e, e->fds[cs].nick);
			client_add(dest, e, " : ");
			while (arg[i])
			{
				client_add(dest, e, arg[i++]);
				client_add(dest, e, " ");
			}
			client_add(dest, e, "\n");
		}
	}
}
