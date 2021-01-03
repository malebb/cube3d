/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:25:30 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/18 19:11:06 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	char			*mem_area;

	if (!(mem_area = malloc(size * (count))))
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		mem_area[i] = 0;
		i++;
	}
	return (mem_area);
}
