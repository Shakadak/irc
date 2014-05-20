/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:51:29 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:07:06 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 && s2 && n)
	{
		while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
			i++;
		return (s1[i] - s2[i]);
	}
	return (0);
}
