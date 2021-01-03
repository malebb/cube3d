/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 10:54:39 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 17:46:47 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

unsigned int	is_parsed(t_parsed *parsed)
{
	if (!parsed->rx || !parsed->ry || !parsed->no || !parsed->so
		|| !parsed->we || !parsed->ea || !parsed->s || !parsed->f
		|| !parsed->c || !parsed->s2)
	{
		return (FALSE);
	}
	return (TRUE);
}

t_parsed		*ini_parsed(void)
{
	t_parsed	*parsed;

	if (!(parsed = malloc(sizeof(t_parsed) * (1))))
		return (ERROR);
	parsed->rx = FALSE;
	parsed->ry = FALSE;
	parsed->no = FALSE;
	parsed->so = FALSE;
	parsed->we = FALSE;
	parsed->ea = FALSE;
	parsed->s = FALSE;
	parsed->s2 = FALSE;
	parsed->f = FALSE;
	parsed->c = FALSE;
	return (parsed);
}

void			ini_parse_2(t_rc *rc)
{
	rc->p->rx = 0;
	rc->p->ry = 0;
	rc->p->no = NULL;
	rc->p->so = NULL;
	rc->p->we = NULL;
	rc->p->ea = NULL;
	rc->p->s = NULL;
	rc->p->s2 = NULL;
	rc->p->rf = 0;
	rc->p->gf = 0;
	rc->p->bf = 0;
	rc->p->rc = 0;
	rc->p->gc = 0;
	rc->p->bc = 0;
	rc->p->map = NULL;
	rc->p->px = 0;
	rc->p->py = 0;
	rc->p->is_p = 0;
	rc->p->height = 0;
	rc->p->width = 0;
	rc->p->fd = 0;
}

t_rc			*ini_parse(void)
{
	t_rc		*rc;

	if (!(rc = malloc(sizeof(t_rc) * (1))))
		return (ERROR);
	if (!(rc->p = malloc(sizeof(t_p) * (1))))
		return (ERROR);
	ini_parse_2(rc);
	return (rc);
}

void			put_error(int error)
{
	if (error == ER_PLAYER)
		ft_putstr("Error\nWrong number of player added\n");
	if (error == 0)
		ft_putstr("Error\nYour .cub file is invalid\n");
	else if (error == ER_PATH)
		ft_putstr("Error\nMissing path name\n");
	else if (error == ER_RGB)
		ft_putstr("Error\nWrong rgb format => r,g,b [0-255]\n");
	else if (error == ER_MAP)
		ft_putstr("Error\nInvalid map\n");
	else if (error == ER_FORMAT)
		ft_putstr("Error\nYour .cub file does not respect format\n");
	else if (error == ER_RESOLUTION)
		ft_putstr("Error\nInvalid resolution specified\n");
	else if (error == ER_NO_MAP)
		ft_putstr("Error\nNo map detected in file specified\n");
}
