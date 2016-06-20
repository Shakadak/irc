/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client_read.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:30:54 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 18:04:16 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "inc/client.h"
#include "libft/inc/libft.h"

static void	client_leave(int cs, int r)
{
	close(cs);
	ft_putendl("\tConnection closed.");
	exit(r);
}

void		client_read(t_env *e)
{
	int	r;

	r = recv(e->sock, e->bread + e->fr, BUF_SIZE - e->fr, 0);
	x_int(-1, r, "recv");
	if (r <= 0)
		client_leave(e->sock, r);
	else
	{
		e->fr += r;
		if (!ft_strchr(e->bread, '\n') && e->fr != BUF_SIZE)
			return ;
		write(STDOUT_FILENO, e->bread, e->fr);
		ft_strclr(e->bread);
		e->fr = 0;
	}
}
