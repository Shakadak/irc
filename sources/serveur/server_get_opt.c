/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_get_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:44:27 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 10:36:33 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

void	get_opt(t_env *e, int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s port\n", av[0]);
		exit(1);
	}
	e->port = atoi(av[1]);
}
