/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 07:33:08 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 08:05:55 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

unsigned int	is_elem_parsed(char *elem, t_parsed *parsed)
{
	unsigned int		size_elem;

	size_elem = ft_strlen(elem);
	if (size_elem == 2 && !ft_strncmp(elem, "NO", 2) && parsed->no)
		return (TRUE);
	else if (size_elem == 2 && !ft_strncmp(elem, "SO", 2) && parsed->so)
		return (TRUE);
	else if (size_elem == 2 && !ft_strncmp(elem, "WE", 2) && parsed->we)
		return (TRUE);
	else if (size_elem == 2 && !ft_strncmp(elem, "EA", 2) && parsed->ea)
		return (TRUE);
	else if (size_elem == 1 && !ft_strncmp(elem, "S", 2) && parsed->s)
		return (TRUE);
	else if (size_elem == 2 && !ft_strncmp(elem, "S2", 2) && parsed->s2)
		return (TRUE);
	else if (size_elem == 1 && !ft_strncmp(elem, "F", 2) && parsed->f)
		return (TRUE);
	else if (size_elem == 1 && !ft_strncmp(elem, "C", 2) && parsed->c)
		return (TRUE);
	else if (size_elem == 2 && !ft_strncmp(elem, "RX", 2) && parsed->rx)
		return (TRUE);
	else if (size_elem == 2 && !ft_strncmp(elem, "RY", 2) && parsed->ry)
		return (TRUE);
	return (FALSE);
}

char			*check_elem(char *elem, t_parsed *parsed)
{
	if (is_elem_parsed(elem, parsed))
	{
		free(elem);
		return (FALSE);
	}
	return (elem);
}

unsigned int	check_rgb_end(char *line, unsigned int i)
{
	if (line[i] != '\0')
		return (ERROR);
	return (GOOD);
}
