/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:03:39 by npineau           #+#    #+#             */
/*   Updated: 2014/05/02 15:45:52 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		len;
	int		len2;

	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = ft_strnew(len + len2);
	if (!new)
		return (NULL);
	if (len)
		ft_strcpy(new, s1);
	if (len2)
		ft_strcpy(new + len, s2);
	return (new);
}
