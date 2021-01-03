/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 09:49:09 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 20:47:47 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

unsigned int	check_next_pos(char **map, t_rc *rc, unsigned int i,
				unsigned int j)
{
	if (!is_map_valid(map, rc, i, j + 1))
		return (FALSE);
	if (!is_map_valid(map, rc, i, j - 1))
		return (FALSE);
	if (!is_map_valid(map, rc, i + 1, j))
		return (FALSE);
	if (!is_map_valid(map, rc, i - 1, j))
		return (FALSE);
	return (TRUE);
}

unsigned int	is_map_valid(char **map, t_rc *rc,
				unsigned int i, unsigned int j)
{
	if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
		|| map[i][j] == 'W')
		map[i][j] = 'A';
	else
	{
		if (map[i][j] == 'A' || map[i][j] == 'R' || map[i][j] == 'G')
			return (TRUE);
	}
	if (map[i][j] == '1')
		return (TRUE);
	else if (i == 0 || j == 0 || i == rc->p->height - 1 ||
			j == rc->p->width - 1 || map[i][j] == ' ' ||
			map[i][j] == '\0')
		return (FALSE);
	else
	{
		if (map[i][j] == '2')
			map[i][j] = 'R';
		else if (map[i][j] == '3')
			map[i][j] = 'G';
		else
			map[i][j] = 'A';
	}
	return (check_next_pos(map, rc, i, j));
}

unsigned int	parse_map(int fd, t_rc *rc, char *line)
{
	int				status;
	int				i;

	status = 1;
	if (!is_line_empty(line))
	{
		free(line);
		while ((status = get_next_line(fd, &line) > 0))
		{
			if (is_line_empty(line))
				break ;
			free(line);
		}
	}
	if (status <= 0)
	{
		free(line);
		return (ER_NO_MAP);
	}
	i = 0;
	rc->p->fd = fd;
	if (!stock_map(rc, line, &i))
		return (ERROR);
	return (GOOD);
}

unsigned int	init_stockage(t_rc *rc, int *i)
{
	if (!allocate_map(rc, rc->p->height))
		return (ERROR);
	*i = rc->p->height;
	return (rc->p->width);
}

int				stock_map(t_rc *rc, char *line, int *i)
{
	unsigned int		current_width;

	if (rc->p->height == 0)
	{
		if (!manage_first_map_line(rc, line, i))
			return (ERROR);
	}
	else if (get_next_line(rc->p->fd, &line) > 0 && is_line_empty(line))
	{
		if (!update_width(&current_width, line, rc, i))
		{
			free(line);
			return (ERROR);
		}
	}
	else if (!is_line_empty(line))
	{
		free(line);
		return (init_stockage(rc, i));
	}
	if (!fill_line(rc, i, line))
		return (ERROR);
	return (rc->p->width);
}
