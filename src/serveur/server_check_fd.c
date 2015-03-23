/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_check_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 14:38:44 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 15:13:34 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	check_fd(t_env *e)
{
	int	i;

	i = 0;
	while ((i < e->maxfd) && (e->r > 0))
	{
		if (FD_ISSET(i, &e->fd_read))
		{
			if (e->fds[i].fct_read)
				e->fds[i].fct_read(e, i);
		}
		if (FD_ISSET(i, &e->fd_write))
		{
			if (e->fds[i].fct_write)
				e->fds[i].fct_write(e, i);
		}
		if (FD_ISSET(i, &e->fd_read) || FD_ISSET(i, &e->fd_write))
			e->r--;
		i++;
	}
}
