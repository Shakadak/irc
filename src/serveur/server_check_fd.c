/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_check_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 14:38:44 by npineau           #+#    #+#             */
/*   Updated: 2015/05/09 16:16:26 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"

void	check_fd(t_env *e)
{
	int	i;
	int	used;

	i = 0;
	while ((i < e->maxfd) && (e->r > 0))
	{
		used = 0;
		if (FD_ISSET(i, &e->fd_read))
			if (e->fds[i].fct_read)
			{
				e->fds[i].fct_read(e, i);
				used = 1;
			}
		if (FD_ISSET(i, &e->fd_write))
			if (e->fds[i].fct_write)
			{
				e->fds[i].fct_write(e, i);
				used = 1;
			}
		if (used == 1)
		{
			--(e->r);
		}
		++i;
	}
}
