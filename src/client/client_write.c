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
#include "inc/client.h"
#include "libft/inc/libft.h"

void	client_write(t_env *e)
{
	ssize_t	ret;

	ret = send(e->sock, e->bwrite, ft_strlen(e->bwrite), 0);
	if (ret != -1)
	{
		ft_strcpy(e->bwrite, e->bwrite + ret);
	}
}
