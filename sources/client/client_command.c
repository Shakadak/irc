/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 13:35:17 by npineau           #+#    #+#             */
/*   Updated: 2014/05/23 18:05:16 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "libft.h"
#include "client.h"

int	find_cmd(int sock, char *buff)
{
	char	*tmp;

	tmp = ft_strtrim(buff);
	if (ft_strequ(tmp, "/quit"))
	{
		ft_strdel(&tmp);
		return (0);
	}
	else
		ft_putendl_fd(buff, sock);
	ft_strdel(&tmp);
	return (1);
}
