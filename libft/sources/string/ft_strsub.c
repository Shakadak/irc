/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:28:03 by npineau           #+#    #+#             */
/*   Updated: 2014/02/05 12:08:37 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *src, unsigned int start, size_t n)
{
	char	*new;

	new = ft_strnew(n + 1);
	if (!src || !new)
		return (new);
	new = ft_strncpy(new, &src[start], n);
	return (new);
}
