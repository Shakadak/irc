/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 16:40:05 by npineau           #+#    #+#             */
/*   Updated: 2014/06/14 12:42:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/inc/libft.h"
#include "inc/client.h"

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

static int	usage(char *prog)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(prog, 2);
	ft_putendl_fd(" <addr(number.number.number.number)> <port(number)>", 2);
	return (-1);
}

int			main(int argc, char **argv)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	e.sock = -1;
	if ((argc == 3 && !ft_isnum(argv[2])) || argc > 3)
		return (usage(argv[0]));
	else if (argc == 3)
		if ((e.sock = create_client(argv[1], ft_atoi(argv[2]))) == -1)
			return (-1);
	main_loop(&e);
	close(e.sock);
	return (0);
}
