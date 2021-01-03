/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:36:36 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 20:48:50 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

unsigned int	check_line(char **line, t_parsed *parsed, int status)
{
	if (status <= 0)
	{
		free(*line);
		return (ER_NO_MAP);
	}
	if (!is_parsed(parsed))
	{
		free(*line);
		return (ER_FORMAT);
	}
	return (GOOD);
}

unsigned int	manage_map(int fd, t_rc *rc, char *line)
{
	unsigned int	error;

	error = 1;
	if ((error = parse_map(fd, rc, line)) != 1)
	{
		if (error != ER_NO_MAP)
			free_map(rc);
		return (error);
	}
	if (!rc->p->is_p || !is_map_valid(rc->p->map, rc, rc->p->px, rc->p->py))
	{
		free_map(rc);
		return (ER_MAP);
	}
	return (GOOD);
}

unsigned int	update_width(unsigned int *current_width, char *line,
				t_rc *rc, int *i)
{
	*current_width = ft_strlen(line);
	if (*current_width > rc->p->width)
		rc->p->width = *current_width;
	rc->p->height++;
	if (!(rc->p->width = stock_map(rc, line, i)))
		return (ERROR);
	return (GOOD);
}

unsigned int	manage_first_map_line(t_rc *rc, char *line, int *i)
{
	rc->p->height++;
	rc->p->width = ft_strlen(line);
	if (!(rc->p->width = stock_map(rc, line, i)))
	{
		free(line);
		return (ERROR);
	}
	return (GOOD);
}

unsigned int	fill_line(t_rc *rc, int *i, char *line)
{
	*i = *i - 1;
	if (!push_line(rc, *i, line))
	{
		free(line);
		return (ERROR);
	}
	free(line);
	return (TRUE);
}
