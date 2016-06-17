/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 15:19:39 by npineau           #+#    #+#             */
/*   Updated: 2015/05/09 16:32:28 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/select.h>
# include "libft.h"

# define FD_FREE	0
# define FD_SERV	1
# define FD_CLIENT	2

# define BUF_SIZE	4096
# define NICK_SIZE	9
# define CHAN_SIZE	200

typedef struct	s_cmd
{
	char		*cmd;
	void		(*fct)();
}				t_cmd;

typedef struct	s_fd
{
	int			type;
	char		nick[NICK_SIZE + 1];
	char		channel[CHAN_SIZE + 1];
	void		(*fct_read)();
	void		(*fct_write)();
	char		buf_read[BUF_SIZE + 1];
	int			fr;
	int			fw;
	char		buf_write[BUF_SIZE + 1];
}				t_fd;

typedef struct	s_env
{
	t_fd		*fds;
	int			port;
	int			maxfd;
	int			max;
	int			r;
	fd_set		fd_read;
	fd_set		fd_write;
}				t_env;

void			init_env(t_env *e);
void			get_opt(t_env *e, int ac, char **av);
void			main_loop(t_env *e);
void			srv_create(t_env *e, int port);
void			srv_accept(t_env *e, int s);
void			client_read(t_env *e, int cs);
void			client_write(t_env *e, int cs);
void			clean_fd(t_fd *fd);
int				x_int(int err, int res, char *str);
void			*x_void(void *err, void *res, char *str);
void			init_fd(t_env *e);
void			do_select(t_env *e);
void			check_fd(t_env *e);
int				command(int cs, t_env *e, int r);
void			spread(int cs, t_env *e, char *msg, int first);
void			client_add(int cs, t_env *e, char *msg);

t_cmd			*fill_commands(t_cmd *tab);
void			*get_command(t_cmd *tab, char *cmd);

void			help(int cs, t_env *e);
void			join(int cs, t_env *e, char **aarg);
void			leave(int cs, t_env *e, char **aarg);
void			client_leave(int cs, t_env *e, char **aarg);
void			who(int cs, t_env *e, char **aarg);
int				get_dest(t_env *e, char *target);
void			msg(int cs, t_env *e, char **arg);
void			change_nick(int cs, t_env *e, char **aarg);

#endif
