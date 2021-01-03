/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:42:28 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/18 16:33:37 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_char_in_set(char c, char *set)
{
	int			i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		ft_str_trimmed_len(char *s1, char *set, int str_len)
{
	int		len;
	int		i;

	len = 0;
	while (s1[len] != '\0' && ft_char_in_set(s1[len], set))
		len++;
	i = str_len - 1;
	while (i >= 0 && ft_char_in_set(s1[i], set))
	{
		len++;
		i--;
	}
	return (len);
}

static int		ft_set_to_add(char *str1, char *set, int i)
{
	int		to_trim;
	int		k;

	to_trim = 1;
	k = i + 1;
	to_trim = 1;
	while (str1[k] != '\0')
	{
		if (!ft_char_in_set(str1[k], set))
		{
			to_trim = 0;
			break ;
		}
		k++;
	}
	return (to_trim);
}

static void		ft_fill_trimmed_str(char *str_trimmed, char *str1, char *set)
{
	int		i;
	int		j;
	int		to_trim;

	i = 0;
	while (str1[i] != '\0' && ft_char_in_set(str1[i], set))
		i++;
	j = -1;
	while (str1[i] != '\0')
	{
		if (ft_char_in_set(str1[i], set))
		{
			to_trim = 1;
			to_trim = ft_set_to_add(str1, set, i);
			if (to_trim == 0)
				str_trimmed[++j] = str1[i];
		}
		else
			str_trimmed[++j] = str1[i];
		i++;
	}
	str_trimmed[++j] = '\0';
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char			*str_trimmed;
	int				size_trimmed_str;
	int				str_len;
	char			*str1;
	char			*the_set;

	if (!s1 || !set)
		return (NULL);
	str1 = (char *)s1;
	the_set = (char *)set;
	str_len = ft_strlen(str1);
	size_trimmed_str = ft_str_trimmed_len(str1, the_set, str_len);
	if (size_trimmed_str >= str_len)
		size_trimmed_str = 0;
	else
		size_trimmed_str = str_len - size_trimmed_str;
	if (!(str_trimmed = malloc(sizeof(char) * (size_trimmed_str + 1))))
		return (0);
	ft_fill_trimmed_str(str_trimmed, str1, the_set);
	return (str_trimmed);
}
