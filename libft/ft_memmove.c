/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:28:10 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/18 19:50:55 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*des;
	char		*source;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	des = (char *)dst;
	source = (char *)src;
	if (des > source)
	{
		while (len > 0)
		{
			des[len - 1] = source[len - 1];
			len--;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			des[i] = source[i];
	}
	return (des);
}
