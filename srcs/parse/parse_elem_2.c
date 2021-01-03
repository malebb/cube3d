/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 10:23:09 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 08:23:52 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char			*is_cardinal_point(unsigned int i, char *line)
{
	if (line[i] == 'N')
	{
		i++;
		if (line[i] == 'O' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			return (ft_strdup("NO"));
	}
	else if (line[i] == 'S')
	{
		i++;
		if (line[i] == 'O' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			return (ft_strdup("SO"));
	}
	else if (line[i] == 'W')
	{
		i++;
		if (line[i] == 'E' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			return (ft_strdup("WE"));
	}
	else if (line[i] == 'E')
	{
		i++;
		if (line[i] == 'A' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			return (ft_strdup("EA"));
	}
	return (NULL);
}

char			*is_other_elem(unsigned int i, char *line)
{
	char	*elem;

	if ((elem = is_elem_sprite(i, line)) != NULL)
		return (elem);
	else if (line[i] == 'F')
	{
		i++;
		if (line[i] == ' ' || line[i] == '\0')
			return (ft_strdup("F"));
	}
	else if (line[i] == 'C')
	{
		i++;
		if (line[i] == ' ' || line[i] == '\0')
			return (ft_strdup("C"));
	}
	else if (line[i] == 'R')
	{
		i++;
		if (line[i] == ' ' || line[i] == '\0')
			return (ft_strdup("R"));
	}
	return (NULL);
}

char			*which_elem(char *line, t_parsed *parsed)
{
	unsigned int	i;
	char			*elem;

	i = 0;
	while (line[i] == ' ')
		i++;
	if ((elem = is_cardinal_point(i, line)) != NULL)
		return (check_elem(elem, parsed));
	while (line[i] == ' ')
		i++;
	if ((elem = is_other_elem(i, line)) != NULL)
		return (check_elem(elem, parsed));
	else if (line[i] == '\0')
		return (ft_strdup("BL"));
	return (FALSE);
}

unsigned int	skip_start(char *line, unsigned int *i)
{
	while (line[*i] == ' ')
		*i = *i + 1;
	while ((line[*i] >= 'A' && line[*i] <= 'Z') || (line[*i] >= '0'
	&& line[*i] <= '9'))
		*i = *i + 1;
	while (line[*i] == ' ')
		*i = *i + 1;
	if (line[*i] == '\0')
		return (ER_PATH);
	return (GOOD);
}

unsigned int	read_path(char *line, t_rc *rc, char *elem)
{
	unsigned int	i;
	unsigned int	size_path;
	unsigned int	error;

	error = 1;
	i = 0;
	if (skip_start(line, &i) != 1)
		return (ER_PATH);
	size_path = path_len(line, i);
	if (elem[0] == 'N' && elem[1] == 'O')
		error = allocate_and_fill(&rc->p->no, size_path, line, i);
	else if (elem[0] == 'S' && elem[1] == 'O')
		error = allocate_and_fill(&rc->p->so, size_path, line, i);
	else if (elem[0] == 'W' && elem[1] == 'E')
		error = allocate_and_fill(&rc->p->we, size_path, line, i);
	else if (elem[0] == 'E' && elem[1] == 'A')
		error = allocate_and_fill(&rc->p->ea, size_path, line, i);
	else if (elem[0] == 'S' && elem[1] == '2')
		error = allocate_and_fill(&rc->p->s2, size_path, line, i);
	else if (elem[0] == 'S')
		error = allocate_and_fill(&rc->p->s, size_path, line, i);
	return (error);
}
