/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:46:02 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:06:55 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	index;
	size_t	length;

	length = ft_strlen(dest);
	index = 0;
	while (index < n && src[index] != 0)
	{
		dest[index + length] = src[index];
		index++;
	}
	dest[index + length] = 0;
	return (dest);
}
