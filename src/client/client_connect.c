#include <unistd.h>
#include <stdlib.h>
#include "inc/client.h"
#include "libft/inc/libft.h"

int	client_connect(int sock, char *command)
{
	int		new_sock;
	t_list	*toks;
	char	*addr;
	char	*port;

	new_sock = -1;
	if (sock != -1)
		close(sock);
	toks = split_when(ft_isspace, command);
	ft_lstdel(&toks, free);
	return (new_sock);
}
