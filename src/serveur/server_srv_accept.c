/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_srv_accept.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:45:09 by npineau           #+#    #+#             */
/*   Updated: 2015/05/09 16:35:18 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "server.h"

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
	*e->fds[cs].channel = -1;
	e->fds[cs].fr = 0;
	e->fds[cs].fw = 0;
	ft_strcpy(e->fds[cs].nick, "guest");
	ft_strcat(e->fds[cs].nick, tmp);
	ft_strdel(&tmp);
	client_add(cs, e, "Logged as: ");
	client_add(cs, e, e->fds[cs].nick);
	client_add(cs, e, "\nFor some help, use /help or /command\n");
	e->fds[cs].fct_read = client_read;
	e->fds[cs].fct_write = client_write;
}
