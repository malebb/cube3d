/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 10:56:49 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 19:43:52 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void			assign_player(t_rc *rc, char *line,
				unsigned int i, unsigned int j)
{
	rc->p->p = line[j];
	rc->p->px = i;
	rc->p->py = j;
}

unsigned int	push_line(t_rc *rc, int i, char *line)
{
	unsigned int			j;
	static unsigned int		player_found = 0;

	if (!((rc->p->map)[i] = malloc(sizeof(char) * (rc->p->width + 1))))
		return (ERROR);
	j = -1;
	while (line[++j] != '\0')
	{
		if (line[j] == 'N' || line[j] == 'S' || line[j] == 'W'
			|| line[j] == 'E')
		{
			if (player_found == 1)
				return (ERROR);
			player_found = 1;
			rc->p->is_p = TRUE;
			assign_player(rc, line, i, j);
		}
		else if (line[j] != ' ' && line[j] != '0' && line[j] !=
		'1' && line[j] != '2' && line[j] != '3' && line[j] != 'S')
			return (ERROR);
		(rc->p->map)[i][j] = line[j];
	}
	fill_with_space(i, j, rc);
	return (GOOD);
}

unsigned int	is_line_empty(char *line)
{
	if (line[0] == '\0')
		return (FALSE);
	return (TRUE);
}

unsigned int	allocate_map(t_rc *rc, int height)
{
	int				i;

	if (!(rc->p->map = malloc(sizeof(char **) * (height + 1))))
		return (ERROR);
	i = 0;
	while (i < height)
	{
		(rc->p->map)[i] = NULL;
		i++;
	}
	rc->p->h_map = height;
	return (GOOD);
}

void			fill_with_space(unsigned int i,
		unsigned int j, t_rc *rc)
{
	while (j < rc->p->width)
	{
		(rc->p->map)[i][j] = ' ';
		j++;
	}
	(rc->p->map)[i][j] = '\0';
}
