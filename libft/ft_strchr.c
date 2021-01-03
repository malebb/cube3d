/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:28:34 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/13 10:28:41 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str_found;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			str_found = (char *)s;
			return (&str_found[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		str_found = (char *)s;
		return (&str_found[i]);
	}
	return (0);
}
