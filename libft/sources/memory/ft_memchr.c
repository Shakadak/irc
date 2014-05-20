/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:20:29 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:02:08 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char	*src;
	size_t				i;

	src = (const unsigned char *)ptr;
	if (n && ptr)
	{
		i = 0;
		while (i < n)
		{
			if (src[i] == (unsigned char)c)
				return ((void *)&src[i]);
			i++;
		}
	}
	return (NULL);
}
