/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:43:03 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/01 14:05:02 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlength(char *str)
{
	int		i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

void	ft_strncat(char *dest, char *src, int n)
{
	int		size_dest;
	int		i;

	size_dest = 0;
	while (dest[size_dest] != '\0')
		size_dest++;
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
}

void	ft_strcpy_from(char *dest, char *src, int j)
{
	int		size_dest;
	int		i;

	size_dest = 0;
	while (src && src[size_dest + j] != '\0')
		size_dest++;
	i = 0;
	while (i < size_dest)
	{
		dest[i] = src[j + i];
		i++;
	}
	dest[i] = '\0';
}

int		ft_update_line(char **line, int j, char *buffer)
{
	char	*tmp;

	if (!(tmp = malloc(sizeof(char) * (ft_strlength(*line) + j + 1))))
		return (-1);
	ft_strcpy_from(tmp, *line, 0);
	ft_strncat(tmp, buffer, j);
	free(*line);
	if (!(*line = malloc(sizeof(char) * (ft_strlength(tmp) + 1))))
	{
		free(tmp);
		return (-1);
	}
	ft_strcpy_from(*line, tmp, 0);
	free(tmp);
	return (1);
}
