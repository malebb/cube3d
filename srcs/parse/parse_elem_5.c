/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:54:44 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 08:28:06 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char			*is_elem_sprite(unsigned int i, char *line)
{
	if (line[i] == 'S')
	{
		i++;
		if (line[i] == ' ' || line[i] == '\0')
			return (ft_strdup("S"));
		if (line[i] == '2' && (line[i + 1] == '\0' || line[i + 1] == ' '))
			return (ft_strdup("S2"));
	}
	return (NULL);
}

unsigned int	init_resolution_reading(char *line, unsigned int *i)
{
	*i = 0;
	while (line[*i] == ' ' || line[*i] == 'R')
		*i = *i + 1;
	if (!ft_isdigit(line[*i]))
		return (ER_RESOLUTION);
	if (line[*i] < '0' || line[*i] > '9')
		return (ER_RESOLUTION);
	return (GOOD);
}

unsigned int	assign_and_free_resolution(char *rx, char *ry, t_rc *rc)
{
	rc->p->rx = ft_atoi(rx);
	rc->p->ry = ft_atoi(ry);
	if (rc->p->rx == 0 || rc->p->ry == 0)
	{
		free(rx);
		free(ry);
		return (FALSE);
	}
	free(rx);
	free(ry);
	return (TRUE);
}

unsigned int	check_nb_resolution(char *line, unsigned int i, char *rx)
{
	if (!ft_isdigit(line[i]))
	{
		free(rx);
		return (ER_RESOLUTION);
	}
	return (GOOD);
}

unsigned int	read_sprite_path(char *elem, t_parsed *parsed, char *line,
				t_rc *rc)
{
	int		error;

	error = 1;
	if (elem[0] == 'S' && elem[1] == '2')
	{
		parsed->s2 = TRUE;
		error = read_path(line, rc, elem);
	}
	if (error == 1)
	{
		if (elem[0] == 'S' && elem[1] != 'O' && elem[1] != '2')
		{
			parsed->s = TRUE;
			error = read_path(line, rc, elem);
		}
	}
	return (error);
}
