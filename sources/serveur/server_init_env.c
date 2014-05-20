/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_init_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 17:44:33 by npineau           #+#    #+#             */
/*   Updated: 2014/05/20 17:44:35 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/resource.h>

void		init_env(t_env *e)
{
  int		i;
  struct rlimit	rlp;

  X(-1, getrlimit(RLIMIT_NOFILE, &rlp), "getrlimit");
  e->maxfd = rlp.rlim_cur;
  e->fds = (t_fd*)Xv(NULL, malloc(sizeof(*e->fds) * e->maxfd), "malloc");
  i = 0;
  while (i < e->maxfd)
    {
      clean_fd(&e->fds[i]);
      i++;
    }
}
