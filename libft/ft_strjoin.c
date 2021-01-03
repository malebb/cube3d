/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:41:42 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/18 19:51:38 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*joined_strs;
	unsigned int	s1_size;
	unsigned int	s2_size;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (!(joined_strs = malloc(sizeof(char) * (s1_size + s2_size + 1))))
		return (0);
	i = 0;
	while (i < s1_size)
	{
		joined_strs[i] = s1[i];
		i++;
	}
	j = -1;
	while (++j < s2_size)
		joined_strs[i + j] = s2[j];
	joined_strs[i + j] = '\0';
	return (joined_strs);
}
