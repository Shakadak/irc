/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client_write.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:31:09 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 13:12:44 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "inc/server.h"
#include "libft/inc/libft.h"

void	client_write(t_env *e, int cs)
{
	ssize_t	ret;

	queue_to_buffer(BUF_SIZE, e->fds[cs].buf_write, &e->fds[cs].q);
	ret = send(cs, e->fds[cs].buf_write, ft_strlen(e->fds[cs].buf_write), 0);
	if (ret != -1)
	{
		ft_strcpy(e->fds[cs].buf_write, e->fds[cs].buf_write + ret);
	}
}
