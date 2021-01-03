/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:42:38 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/18 16:31:40 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	size_sub_str;
	unsigned int	size_str;
	unsigned int	i;
	char			*sub_str;
	char			*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	if (start >= ft_strlen((str)))
		return (ft_strdup(""));
	size_str = ft_strlen(str);
	size_sub_str = size_str - start;
	if (size_sub_str > len)
		size_sub_str = len;
	if (!(sub_str = malloc(sizeof(char) * size_sub_str + 1)))
		return (NULL);
	i = 0;
	while (str[i + start] != '\0' && i < len)
	{
		sub_str[i] = str[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
