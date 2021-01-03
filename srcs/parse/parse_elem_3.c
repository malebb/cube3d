/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 10:27:12 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 07:58:33 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

unsigned int	path_len(char *line, int i)
{
	unsigned int	size;

	size = 0;
	while (ft_isascii(line[i]) && line[i] != ' ' && line[i] != '\0')
	{
		i++;
		size++;
	}
	return (size);
}

void			strcpy_n_from(char **dest, char *src, unsigned int n,
				unsigned int from)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[0][i] = src[i + from];
		i++;
	}
	dest[0][i] = '\0';
}

char			*read_rx(char *line, unsigned int i, unsigned int *size_nb)
{
	char			*rx;

	*size_nb = nb_len(line, i);
	if (!(rx = malloc(sizeof(char) * (*size_nb + 1))))
		return (ERROR);
	strcpy_n_from(&rx, line, *size_nb, i);
	return (rx);
}

char			*read_ry(char *line, unsigned int i)
{
	int			size_nb;
	char		*ry;

	size_nb = nb_len(line, i);
	if (!(ry = malloc(sizeof(char) * size_nb + 1)))
		return (ERROR);
	strcpy_n_from(&ry, line, size_nb, i);
	if (line[size_nb + i] != '\0')
	{
		free(ry);
		return (ERROR);
	}
	return (ry);
}

unsigned int	read_resolution(char *line, t_rc *rc)
{
	unsigned int	i;
	unsigned int	size_nb;
	char			*rx;
	char			*ry;

	i = 0;
	if (init_resolution_reading(line, &i) != 1)
		return (ER_RESOLUTION);
	if (!(rx = read_rx(line, i, &size_nb)))
		return (ERROR);
	i += size_nb;
	while (line[i] == ' ')
		i++;
	if (check_nb_resolution(line, i, rx) != 1)
		return (ER_RESOLUTION);
	if (!(ry = read_ry(line, i)))
	{
		free(rx);
		free(ry);
		return (ERROR);
	}
	if (!assign_and_free_resolution(rx, ry, rc))
		return (ER_RESOLUTION);
	return (GOOD);
}
