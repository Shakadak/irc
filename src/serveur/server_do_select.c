/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_do_select.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:44:14 by npineau           #+#    #+#             */
/*   Updated: 2015/05/08 16:48:19 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "inc/server.h"
#include "libft/inc/libft.h"

void	do_select(t_env *e)
{
	struct timeval	t;

	t.tv_sec = time(NULL);
	t.tv_usec = 5;
	e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, NULL);
	if (e->r == 0)
		ft_putstr("timout ");
}
