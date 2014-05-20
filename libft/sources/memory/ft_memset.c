/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:36:46 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:03:11 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *dest, int c, size_t length)
{
	unsigned char	*dst;
	size_t			i;

	i = 0;
	dst = (unsigned char *)dest;
	if (length && dest)
	{
		while (i < length)
		{
			dst[i] = (unsigned char)c;
			i++;
		}
	}
	return (dest);
}
