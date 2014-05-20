/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:53:31 by npineau           #+#    #+#             */
/*   Updated: 2014/05/06 12:56:20 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '\t')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == '\v')
		return (1);
	else if (c == '\f')
		return (1);
	else if (c == '\r')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *src)
{
	int	res;
	int	i;
	int	mult;

	res = 0;
	i = 0;
	mult = 1;
	while (ft_isspace(src[i]))
		i++;
	if (src[i] == '+')
		i++;
	else if (src[i] == '-')
	{
		mult = -1;
		i++;
	}
	while ('0' <= src[i] && src[i] <= '9')
	{
		res = res * 10 + src[i] - '0';
		i++;
	}
	return (mult * res);
}
