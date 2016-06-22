/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 18:24:07 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 18:19:05 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>

# define BUF_SIZE	4096

typedef struct	s_env
{
	int			sock;
	fd_set		fd_read;
	fd_set		fd_write;
	char		bread[BUF_SIZE + 1];
	char		bwrite[BUF_SIZE + 1];
	int			fr;
	int			fw;
}				t_env;

void			main_loop(t_env *e);
void			client_read(t_env *e);
void			client_write(t_env *e);
int				client_connect(int sock, char *command);
void			standard_input(t_env *e);
int				x_int(int err, int res, char *str);
void			*x_void(void *err, void *res, char *str);
int				create_client(char *addr, int port);
void			client_add(t_env *e, char *msg);
void			client_leave(int cs, int r);

#endif
