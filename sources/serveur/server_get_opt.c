/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_get_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:44:27 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 18:45:16 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "server.h"

static int	ft_isnum(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	get_opt(t_env *e, int ac, char **av)
{
	if (ac != 2 || !ft_isnum(av[1]))
	{
		fprintf(stderr, "Usage: %s port\n", av[0]);
		exit(1);
	}
	e->port = ft_atoi(av[1]);
}
