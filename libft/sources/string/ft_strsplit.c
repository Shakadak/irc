/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:59:23 by npineau           #+#    #+#             */
/*   Updated: 2014/05/06 13:08:29 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_todo(const char *s, char c)
{
	int	i;
	int	cp;

	i = 0;
	cp = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			cp++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
		if (s[i] != 0)
			i++;
	}
	return (cp);
}

static int	ft_modlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	tab = NULL;
	i = 0;
	j = 0;
	if (s == NULL)
		return (tab);
	tab = (char **)malloc(sizeof(char *) * (ft_todo(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			tab[j] = ft_strsub(s, i, ft_modlen(&s[i], c));
			j++;
			i += ft_modlen(&s[i], c) - 1;
		}
		i++;
	}
	tab[ft_todo(s, c)] = NULL;
	return (tab);
}
