/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_client_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 12:18:31 by npineau           #+#    #+#             */
/*   Updated: 2016/06/17 15:05:46 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"

static void	dummy_del(void *p)
{
	(void)p;
}

void		client_add(int cs, t_env *e, char *msg)
{
	rb_force_enqueue(&e->fds[cs].q, dummy_del, msg);
}
