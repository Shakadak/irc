/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 16:15:08 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 18:25:07 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "inc/client.h"
#include "libft/inc/libft.h"

static void	init_fd(t_env *e)
{
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	FD_SET(STDIN_FILENO, &e->fd_read);
	if (e->sock != -1)
	{
		FD_SET(e->sock, &e->fd_read);
		if (*e->bwrite != 0)
			FD_SET(e->sock, &e->fd_write);
	}
}

static void	do_select(t_env *e)
{
	select(imax(e->sock + 1, 3), &e->fd_read, &e->fd_write, NULL, NULL);
}

static void	check_fd(t_env *e)
{
	if (FD_ISSET(STDIN_FILENO, &e->fd_read))
		standard_input(e);
	if (e->sock != -1)
	{
		if (FD_ISSET(e->sock, &e->fd_read))
			client_read(e);
		if (FD_ISSET(e->sock, &e->fd_write))
			client_write(e);
	}
}

void		main_loop(t_env *e)
{
	while (1)
	{
		init_fd(e);
		do_select(e);
		check_fd(e);
	}
}
