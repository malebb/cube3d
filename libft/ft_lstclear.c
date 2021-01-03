/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:43:28 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/14 09:11:21 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*previous_elem;

	if (!lst || !(*lst) || !del)
		return ;
	previous_elem = *lst;
	while ((*lst) != 0)
	{
		previous_elem = *lst;
		(*del)((*lst)->content);
		(*lst) = (*lst)->next;
		free(previous_elem);
	}
	(*lst) = 0;
}
