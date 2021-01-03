/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:44:43 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/14 16:01:36 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*begin_new_list;
	t_list			*new_elem;

	if (!lst)
		return (NULL);
	if (!(begin_new_list = ft_lstnew((*f)(lst->content))))
		return (NULL);
	new_elem = begin_new_list;
	lst = lst->next;
	while (lst != NULL)
	{
		if (!(new_elem->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&begin_new_list, del);
			return (NULL);
		}
		new_elem = new_elem->next;
		lst = lst->next;
	}
	return (begin_new_list);
}
