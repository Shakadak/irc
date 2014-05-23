/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_private_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 11:27:19 by npineau           #+#    #+#             */
/*   Updated: 2014/05/23 14:43:02 by npineau          ###   ########.fr       */
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
		ft_strcat(e->fds[cs].buf_write, "Destination and message mising.\n");
	else if (arg[2] == NULL)
		ft_strcat(e->fds[cs].buf_write, "Message mising.\n");
	else
	{
		if ((dest = get_dest(e, arg[1])) == -1)
			ft_strcat(e->fds[cs].buf_write, "Invalid nickname.\n");
		else
		{
			i = 2;
			ft_strcat(e->fds[dest].buf_write, "from ");
			ft_strcat(e->fds[dest].buf_write, e->fds[cs].nick);
			ft_strcat(e->fds[dest].buf_write, " : ");
			while (arg[i])
			{
				ft_strcat(e->fds[dest].buf_write, arg[i++]);
				ft_strcat(e->fds[dest].buf_write, " ");
			}
			ft_strcat(e->fds[dest].buf_write, "\n");
		}
	}
}
