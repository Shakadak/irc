#include <unistd.h>
#include <stdlib.h>
#include "inc/client.h"
#include "libft/inc/libft.h"

int	client_connect(int sock, char *command)
{
	int		new_sock;
	t_lst	*toks;
	t_lst	*addr;
	t_lst	*port;

	new_sock = -1;
	if (sock != -1)
		close(sock);
	toks = split_when(ft_isspace, command);
	if ((addr = ft_lstind(toks, 1)) != NULL)
	{
		if ((port = ft_lstind(toks, 2)) != NULL)
		{
			if (ft_isx(port->content, ft_isdigit))
				new_sock = create_client(addr->content, ft_atoi(port->content));
			else
				ft_putendl("port is not a number");
		}
		else
			ft_putendl("port is missing");
	}
	else
		ft_putendl("address and port missing");
	ft_lstdel(&toks, free);
	return (new_sock);
}
