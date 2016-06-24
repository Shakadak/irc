/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 16:40:35 by npineau           #+#    #+#             */
/*   Updated: 2014/06/12 17:50:37 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "libft/inc/libft.h"
#include "inc/client.h"

int	create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*p;
	struct sockaddr_in	sin;

	if (ft_strequ(addr, "localhost"))
		ft_strcpy(addr, "127.0.0.1");
	p = (struct protoent*)x_void(NULL, getprotobyname("tcp"), "getprotobyname");
	if (p == NULL)
		return (-1);
	sock = x_int(-1, socket(PF_INET, SOCK_STREAM, p->p_proto), "socket");
	if (sock == -1)
		return (-1);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		fprintf(stderr, "%s error: %s\n", "connect", strerror(errno));
		close(sock);
		return (-1);
	}
	return (sock);
}
