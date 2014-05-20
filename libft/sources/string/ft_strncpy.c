/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:09:44 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:07:20 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *copy, const char *src, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n && src[index] != 0)
	{
		copy[index] = src[index];
		index++;
	}
	while (index < n)
	{
		copy[index] = 0;
		index++;
	}
	return (copy);
}
