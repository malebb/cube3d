/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:54:01 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/02 09:32:06 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		redcross(void *data)
{
	t_rc	*rc;

	rc = (t_rc *)data;
	free_mem(rc);
	exit(0);
	return (GOOD);
}

void	check_resolution(t_rc *rc)
{
	int		width;
	int		height;

	mlx_get_screen_size(rc->mlx, &width, &height);
	if (rc->p->rx > (unsigned int)width)
		rc->p->rx = width;
	if (rc->p->ry > (unsigned int)height)
		rc->p->ry = height;
}

void	put_rc_error(unsigned int error)
{
	if (error == ER_SAVE)
		ft_putstr("Error\nFirst image could not be saved\n");
	else if (error == ER_RC)
		ft_putstr("Error\nRaycasting went wrong\n");
}

int		detect_file_error(int argc, char **argv)
{
	if (argc <= 1 || argc > 3)
	{
		put_file_error(ER_NOFILE);
		return (ER_FILE);
	}
	if (!check_file_ext(argv[1]))
	{
		put_file_error(ER_FILENAME);
		return (ER_FILE);
	}
	return (GOOD);
}
