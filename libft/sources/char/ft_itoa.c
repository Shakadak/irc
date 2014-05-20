/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:43:05 by npineau           #+#    #+#             */
/*   Updated: 2014/05/06 12:59:54 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_initiate(int n)
{
	char	*new;

	if (n < 0)
	{
		new = ft_strnew(3);
		new[0] = '-';
		new[1] = -n + '0';
	}
	else
	{
		new = ft_strnew(2);
		new[0] = n + '0';
	}
	return (new);
}

char		*ft_itoa(int n)
{
	char	*new;
	char	*tmp;
	int		mod;

	mod = n % 10;
	if (mod < 0)
		mod = -mod;
	if (n / 10 == 0)
	{
		new = ft_initiate(n);
		return (new);
	}
	else
	{
		tmp = ft_itoa(n / 10);
		if (tmp == NULL)
			return (NULL);
		new = ft_strnew(ft_strlen(tmp) + 1);
		new = ft_strcpy(new, tmp);
		new[ft_strlen(tmp)] = mod + '0';
		ft_strdel(&tmp);
		return (new);
	}
}
