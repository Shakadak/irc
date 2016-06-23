/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 16:47:47 by npineau           #+#    #+#             */
/*   Updated: 2014/05/25 18:00:48 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"
#include "inc/client.h"

void	client_add(t_env *e, char *msg)
{
	int	len;

	len = ft_strlen(msg);
	if (len + e->fw < BUF_SIZE)
	{
		ft_strcpy(e->bwrite + e->fw, msg);
		e->fw += len;
	}
}
