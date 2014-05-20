/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:31:52 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:04:48 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	unsigned int	index;
	unsigned int	length;

	length = ft_strlen(dest);
	index = 0;
	while (src[index] != 0)
	{
		dest[index + length] = src[index];
		index++;
	}
	dest[index + length] = 0;
	return (dest);
}
