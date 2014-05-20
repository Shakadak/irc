/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:48:17 by npineau           #+#    #+#             */
/*   Updated: 2014/05/06 13:02:20 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_elemdel(void *content, size_t size)
{
	(void)size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = NULL;
	if (lst)
	{
		new = ft_lstnew((f(lst))->content, lst->content_size);
		if (!new)
			return (NULL);
		if (lst->next)
		{
			new->next = ft_lstmap(lst->next, f);
			if (new->next == NULL)
				ft_lstdel(&new, &ft_elemdel);
		}
	}
	return (new);
}
