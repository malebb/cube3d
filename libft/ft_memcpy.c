/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:27:58 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/18 18:33:18 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*desti;
	char			*source;

	if (!dst && !src)
		return (NULL);
	desti = (char *)dst;
	source = (char *)src;
	i = 0;
	while (i < n)
	{
		desti[i] = source[i];
		i++;
	}
	return (desti);
}
