/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:42:20 by npineau           #+#    #+#             */
/*   Updated: 2014/05/06 13:06:27 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	unsigned int	length;
	unsigned int	index;
	char			*copy;

	length = ft_strlen(src);
	index = 0;
	copy = (char *)malloc((1 + length) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (index < length)
	{
		copy[index] = src[index];
		index++;
	}
	copy[index] = 0;
	return (copy);
}
