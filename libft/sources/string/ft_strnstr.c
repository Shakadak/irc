/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:54:34 by npineau           #+#    #+#             */
/*   Updated: 2014/05/06 13:07:36 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dest, const char *mod, size_t n)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = ft_strlen(mod);
	if (length > 0)
	{
		if (length <= n)
		{
			while (dest[i] != 0 && i < n)
			{
				if (dest[i] == mod[0] && i + length <= n)
				{
					if (!ft_strncmp(&dest[i], mod, length))
						return ((char *)&dest[i]);
				}
				i++;
			}
		}
		return (NULL);
	}
	else
		return ((char *)dest);
}
