/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:16:44 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 16:17:52 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_rc		*parse(t_rc **rc, int fd)
{
	t_parsed			*parsed;
	unsigned int		error;

	parsed = ini_parsed();
	if ((error = parse_elem(parsed, fd, *rc)) != GOOD)
	{
		free(parsed);
		free_path(*rc);
		free((*rc)->p);
		free(*rc);
		put_error(error);
		return (ERROR);
	}
	free(parsed);
	return (*rc);
}
