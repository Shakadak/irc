/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_get_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:09:33 by npineau           #+#    #+#             */
/*   Updated: 2015/05/09 16:35:07 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"server.h"

void	*get_command(t_cmd *tab, char *cmd)
{
	while (tab->cmd)
	{
		if (ft_strequ(tab->cmd, cmd))
			return (tab->fct);
		tab++;
	}
	return (NULL);
}
