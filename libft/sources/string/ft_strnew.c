/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 12:49:33 by npineau           #+#    #+#             */
/*   Updated: 2014/05/02 15:17:12 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Utility allocating new array of char, adding space for the terminating byte.
** It clears the memory allocated so that no garbage can parasite the calling
** process.
*/

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		size++;
		while (size)
		{
			size--;
			str[size] = 0;
		}
		return (str);
	}
	else
		return (NULL);
}
