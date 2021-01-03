/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:30:39 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/14 16:00:40 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char			*str;
	int				len;

	str = (char *)s;
	len = ft_strlen(str);
	if (c == '\0')
		return (&str[len]);
	while (len >= 0)
	{
		if (s[len] == c)
			return (&str[len]);
		len--;
	}
	return (0);
}
