/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_to_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 14:10:56 by npineau           #+#    #+#             */
/*   Updated: 2016/06/13 14:11:01 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/inc/libft.h"

void	dummy_del(void *p)
{
	(void)p;
}

int		queue_to_buffer(size_t limit, char *buffer, t_rb *rb)
{
	char	*peekaboo;
	size_t	peekedsize;
	size_t	buffersize;

	rb_peek(*rb, (void**)&peekaboo);
	peekedsize = ft_strlen(peekaboo);
	buffersize = ft_strlen(buffer);
	if (peekedsize + buffersize < limit)
	{
		strcpy(peekaboo, buffer + buffersize);
		rb_drop_n(rb, dummy_del, 1);
		queue_to_buffer(limit, buffer, rb);
	}
	return (1);
}
