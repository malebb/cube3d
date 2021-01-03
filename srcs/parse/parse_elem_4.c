/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 10:58:38 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 08:05:09 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

unsigned int	allocate_and_fill(char **path, unsigned int size_path,
				char *line, unsigned int i)
{
	if (!((*path) = malloc(sizeof(char) * (size_path + 1))))
		return (ERROR);
	strcpy_n_from(path, line, size_path, i);
	return (GOOD);
}

unsigned int	nb_len(char *line, unsigned int i)
{
	unsigned int	size_nb;

	size_nb = 0;
	while (ft_isdigit(line[i]))
	{
		size_nb++;
		i++;
	}
	return (size_nb);
}

void			fill_rgb_elem(t_rc *rc, char *elem, unsigned int j,
				unsigned int value)
{
	if (elem[0] == 'F')
	{
		if (j == 0)
			rc->p->rf = value;
		else if (j == 1)
			rc->p->gf = value;
		else if (j == 2)
			rc->p->bf = value;
	}
	else
	{
		if (j == 0)
			rc->p->rc = value;
		else if (j == 1)
			rc->p->gc = value;
		else if (j == 2)
			rc->p->bc = value;
	}
}

char			*read_color(char *line, unsigned int *size_nb, unsigned int i)
{
	char		*color;

	*size_nb = nb_len(line, i);
	if (!(color = malloc(sizeof(char) * (*size_nb + 1))))
		return (ERROR);
	strcpy_n_from(&color, line, *size_nb, i);
	return (color);
}

unsigned int	read_rgb(char *line, t_rc *rc, char *elem)
{
	unsigned int			i;
	unsigned int			j;
	unsigned int			size_nb;
	char					*color;
	long long int			value;

	i = 0;
	while (line[i] == ' ' || line[i] == 'F' || line[i] == 'C')
		i++;
	j = -1;
	while (++j < 3)
	{
		if (!ft_isdigit(line[i]))
			return (ER_RGB);
		color = read_color(line, &size_nb, i);
		value = ft_atoi(color);
		free(color);
		if (value < 0 || value > 255)
			return (ER_RGB);
		fill_rgb_elem(rc, elem, j, value);
		i += size_nb;
		if (line[i] == ',')
			i++;
	}
	return (check_rgb_end(line, i));
}
