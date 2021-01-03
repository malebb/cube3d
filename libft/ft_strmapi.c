/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:42:02 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/18 16:37:24 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				str_len;
	char			*returns;
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	str_len = ft_strlen(str);
	if (!(returns = malloc(sizeof(char) * (str_len + 1))))
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		returns[i] = (*f)(i, str[i]);
		i++;
	}
	returns[i] = '\0';
	return (returns);
}
