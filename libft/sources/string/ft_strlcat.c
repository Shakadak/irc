/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:50:04 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:06:20 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t buf)
{
	size_t	index;
	size_t	l;

	l = ft_strlen(dest);
	index = 0;
	if (buf > l)
	{
		while (index < buf - l - 1 && src[index] != 0)
		{
			dest[index + l] = src[index];
			index++;
		}
		dest[l + index] = 0;
	}
	else
		return (buf + ft_strlen(src));
	return (l + ft_strlen(src));
}
