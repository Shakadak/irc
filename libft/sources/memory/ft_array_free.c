/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 12:14:47 by npineau           #+#    #+#             */
/*   Updated: 2014/05/23 13:26:50 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_array_free(void **array)
{
	void	*tmp;

	tmp = array;
	while (*array)
	{
		free(*array);
		(array)++;
	}
	free(tmp);
}
