/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_fill_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 13:54:53 by npineau           #+#    #+#             */
/*   Updated: 2014/06/14 15:18:07 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_cmd	*fill_commands(t_cmd *tab)
{
	tab[0].cmd = "/nick";
	tab[0].fct = change_nick;
	tab[1].cmd = "/msg";
	tab[1].fct = msg;
	tab[2].cmd = "/join";
	tab[2].fct = join;
	tab[3].cmd = "/leave";
	tab[3].fct = leave;
	tab[4].cmd = "/quit";
	tab[4].fct = client_leave;
	tab[5].cmd = "/who";
	tab[5].fct = who;
	tab[6].cmd = "/help";
	tab[6].fct = help;
	tab[7].cmd = "/command";
	tab[7].fct = help;
	tab[8].cmd = NULL;
	return (tab);
}
