/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 10:19:46 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 08:34:50 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

unsigned int	parse_elem(t_parsed *parsed, int fd, t_rc *rc)
{
	char				*line;
	char				*elem;
	int					status;
	unsigned int		error;

	while ((status = get_next_line(fd, &line)) > 0 && !is_parsed(parsed)
			&& is_elem_here(line))
	{
		if (!(elem = which_elem(line, parsed)))
		{
			free(line);
			return (ERROR);
		}
		if ((error = read_elem(elem, line, parsed, rc)) != GOOD)
		{
			free(line);
			return (error);
		}
		free(line);
	}
	if ((error = check_line(&line, parsed, status)) != 1)
		return (error);
	if ((error = manage_map(fd, rc, line)) != 1)
		return (error);
	return (GOOD);
}

unsigned int	is_elem_here(char *line)
{
	unsigned int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] != 'R' && line[i] != 'N' && line[i] != 'S'
		&& line[i] != 'W' && line[i] != 'E' && line[i] != 'F'
		&& line[i] != 'C' && line[i] != '\0')
		return (FALSE);
	if (line[i] == '\0' && i != 0)
		return (FALSE);
	return (TRUE);
}

unsigned int	read_elem(char *elem, char *line,
				t_parsed *parsed, t_rc *rc)
{
	int		error;

	error = GOOD;
	if ((error = read_cardinal_point(parsed, rc, elem, line)) != GOOD)
	{
		free(elem);
		return (error);
	}
	error = read_other_elem(parsed, rc, elem, line);
	free(elem);
	return (error);
}

unsigned int	read_other_elem(t_parsed *parsed, t_rc *rc,
				char *elem, char *line)
{
	int		error;

	error = GOOD;
	if ((error = read_sprite_path(elem, parsed, line, rc)) != 1)
		return (error);
	if (elem[0] == 'R')
	{
		parsed->rx = TRUE;
		parsed->ry = TRUE;
		error = read_resolution(line, rc);
	}
	else if (elem[0] == 'F')
	{
		parsed->f = TRUE;
		error = read_rgb(line, rc, elem);
	}
	else if (elem[0] == 'C')
	{
		parsed->c = TRUE;
		error = read_rgb(line, rc, elem);
	}
	return (error);
}

unsigned int	read_cardinal_point(t_parsed *parsed, t_rc *rc,
				char *elem, char *line)
{
	if (elem[0] == 'N' && elem[1] == 'O')
	{
		parsed->no = TRUE;
		return (read_path(line, rc, elem));
	}
	if (elem[0] == 'S' && elem[1] == 'O')
	{
		parsed->so = TRUE;
		return (read_path(line, rc, elem));
	}
	if (elem[0] == 'W' && elem[1] == 'E')
	{
		parsed->we = TRUE;
		return (read_path(line, rc, elem));
	}
	if (elem[0] == 'E' && elem[1] == 'A')
	{
		parsed->ea = TRUE;
		return (read_path(line, rc, elem));
	}
	return (GOOD);
}
