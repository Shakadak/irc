/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 12:14:47 by npineau           #+#    #+#             */
/*   Updated: 2014/05/23 12:22:42 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_free(void ***array)
{
	while (*array)
	{
		ft_memdel(*array);
		(*array)++;
	}
	ft_memdel(*array);
}
