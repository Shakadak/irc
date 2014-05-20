/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:55:31 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:09:38 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;
	size_t				index;

	dest = s1;
	src = s2;
	if (s1 && s2 && n)
	{
		index = 0;
		while (index < n)
		{
			dest[index] = src[index];
			index++;
		}
	}
	return (s1);
}
