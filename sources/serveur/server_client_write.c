/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client_write.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:31:09 by npineau           #+#    #+#             */
/*   Updated: 2014/05/22 17:48:09 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "server.h"
#include "libft.h"

void	client_write(t_env *e, int cs)
{
	if (*e->fds[cs].buf_write)
	{
		send(cs, e->fds[cs].buf_write, ft_strlen(e->fds[cs].buf_write), 0);
		ft_strclr(e->fds[cs].buf_write);
	}
}
