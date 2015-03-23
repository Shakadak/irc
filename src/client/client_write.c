/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 18:05:00 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 18:06:05 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <unistd.h>
#include "client.h"
#include "libft.h"

void	client_write(t_env *e)
{
	if (e->fw)
	{
		send(e->sock, e->bwrite, e->fw, 0);
		e->fw = 0;
		ft_bzero(e->bwrite, BUF_SIZE);
	}
}
