/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:27:11 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/18 18:35:26 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*desti;
	char			*source;
	unsigned int	i;

	desti = (char *)dst;
	source = (char *)src;
	i = 0;
	while (i < n)
	{
		desti[i] = source[i];
		if (source[i] == (char)c)
			return (&desti[i + 1]);
		i++;
	}
	return (NULL);
}
