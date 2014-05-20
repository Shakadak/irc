/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:49:27 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:03:02 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		tmp[n];
	char		*dest;
	const char	*src;

	dest = s1;
	src = s2;
	if (s1 && s2 && n)
	{
		ft_memcpy(tmp, src, n);
		if (s1 > s2)
		{
			while (n > 0)
			{
				dest[n - 1] = tmp[n - 1];
				n--;
			}
		}
		else
			ft_memcpy(dest, tmp, n);
	}
	return (s1);
}
