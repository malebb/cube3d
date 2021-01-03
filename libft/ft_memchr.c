/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:27:30 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/18 18:43:36 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*src;
	unsigned	i;

	src = (char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (char)c)
			return (&src[i]);
		i++;
	}
	return (NULL);
}
