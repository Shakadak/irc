/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 18:24:07 by npineau           #+#    #+#             */
/*   Updated: 2014/05/22 15:25:24 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <netdb.h>

typedef enum	e_cmd
{
	ERROR,
	SUCCESS,
	LS,
	CD,
	PWD
}				t_cmd;

int		create_client(char *addr, int port);
int		find_cmd(int port, char *buff);

#endif
