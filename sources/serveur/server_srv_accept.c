/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_srv_accept.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:45:09 by npineau           #+#    #+#             */
/*   Updated: 2014/05/21 17:48:38 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "server.h"
#include "libft.h"

void			srv_accept(t_env *e, int s)
{
	int					cs;
	struct sockaddr_in	csin;
	socklen_t			csin_len;
	char				*tmp;

	csin_len = sizeof(csin);
	cs = x_int(-1, accept(s, (struct sockaddr*)&csin, &csin_len), "accept");
	printf("New client #%d from %s:%d\n", cs,
			inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
	clean_fd(&e->fds[cs]);
	e->fds[cs].type = FD_CLIENT;
	tmp = ft_itoa(cs);
	ft_strcpy(e->fds[cs].nick, "guest");
	ft_strcat(e->fds[cs].nick, tmp);
	ft_strdel(&tmp);
	send(cs, "logged as: ", 11, 0);
	send(cs, e->fds[cs].nick, ft_strlen(e->fds[cs].nick), 0);
	send(cs, "\n", 1, 0);
	e->fds[cs].fct_read = client_read;
	e->fds[cs].fct_write = client_write;
}
