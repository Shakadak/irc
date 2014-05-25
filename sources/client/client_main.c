/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 16:40:05 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 13:20:21 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "client.h"

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
	ft_putstr("Usage: ");
	ft_putstr(prog);
	ft_putendl(" <addr(number.number.number.number)> <port(number)>");
	return (-1);
}

int			main(int argc, char **argv)
{
	int		sock;
	char	*buff;

	buff = NULL;
	if (argc != 3 || !ft_isnum(argv[2]))
		return (usage(argv[0]));
	sock = create_client(argv[1], ft_atoi(argv[2]));
	if (sock == -1)
		return (-1);
	while (get_next_line(0, &buff) > 0)
	{
		get_next_line(0, &buff);
		if (find_cmd(sock, buff) == 0)
			break ;
	}
	close(sock);
	return (0);
}
