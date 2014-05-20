/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:06:02 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:01:56 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*src;

	dst = s1;
	src = s2;
	if (s1 && s2 && n)
	{
		i = 0;
		while (i < n && src[i] != (unsigned char)c)
		{
			dst[i] = src[i];
			i++;
		}
		if (src[i] == (unsigned char)c && i < n)
		{
			dst[i] = src[i];
			return (&dst[i + 1]);
		}
	}
	return (NULL);
}
