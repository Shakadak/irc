/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 13:35:17 by npineau           #+#    #+#             */
/*   Updated: 2014/05/18 16:34:10 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "libft.h"
#include "client.h"

static void	send_ls(int sock)
{
	char	message;
	char	buff[512];
	int		r;

	message = LS;
	send(sock, &message, 1, 0);
	while ((r = recv(sock, buff, 511, 0)))
	{
		if (buff[0] == SUCCESS && r == 1)
			break;
		buff[r] = 0;
		ft_putstr(buff);
	}
}

int	find_cmd(int sock, char *buff)
{
	char	*tmp;

	tmp = ft_strtrim(buff);
	if (ft_strequ(tmp, "quit"))
	{
		ft_strdel(&tmp);
		return (0);
	}
	else if (ft_strequ(tmp, "ls"))
		send_ls(sock);
	else
		ft_putendl_fd(buff, sock);
	ft_strdel(&tmp);
	return (1);
}
