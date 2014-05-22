/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_srv_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:17:59 by npineau           #+#    #+#             */
/*   Updated: 2014/05/22 15:18:33 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include "libft.h"
#include "server.h"

static void		print_server(int sock)
{
	struct sockaddr_in	sin;
	socklen_t			len;

	len = sizeof(sin);
	getsockname(sock, (struct sockaddr *)&sin, &len);
	ft_putstr("server reachable at port ");
	ft_putnbr(ntohs(sin.sin_port));
	ft_putchar('\n');
}

void			srv_create(t_env *e, int port)
{
	int					s;
	struct sockaddr_in	sin;
	struct protoent		*p;

	p = (struct protoent*)x_void(NULL, getprotobyname("tcp"), "getprotobyname");
	s = x_int(-1, socket(PF_INET, SOCK_STREAM, pe->p_proto), "socket");
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);
	x_int(-1, bind(s, (struct sockaddr*)&sin, sizeof(sin)), "bind");
	x_int(-1, listen(s, 42), "listen");
	e->fds[s].type = FD_SERV;
	e->fds[s].fct_read = srv_accept;
	print_server(s);
}
