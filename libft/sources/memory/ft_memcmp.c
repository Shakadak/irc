/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:29:21 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:02:22 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	int					cmp;
	size_t				i;

	cmp = 0;
	s1 = str1;
	s2 = str2;
	if (str1 && str2 && n)
	{
		i = 0;
		while (i < n && (cmp = s1[i] - s2[i]) == 0)
			i++;
	}
	return (cmp);
}
