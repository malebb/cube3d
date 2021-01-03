/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:09:00 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/02 10:55:50 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		keyrelease(int keycode, t_rc *rc)
{
	if (keycode == 119)
		rc->player->go = 0;
	else if (keycode == 115)
		rc->player->go = 0;
	else if (keycode == 97)
		rc->player->turn = 0;
	else if (keycode == 100)
		rc->player->turn = 0;
	else if (keycode == L_ARROW)
		rc->player->turn_l = 0;
	else if (keycode == R_ARROW)
		rc->player->turn_r = 0;
	else if (keycode == SHIFT)
	{
		if (rc->map == 0)
			rc->map = 1;
		else
			rc->map = 0;
	}
	else if (keycode == R_KEY)
		run(rc);
	return (GOOD);
}

int		keypressed(int keycode, void *data)
{
	t_rc		*rc;

	rc = (t_rc *)data;
	if (keycode == UP)
		rc->player->go = 1;
	else if (keycode == DOWN)
		rc->player->go = -1;
	else if (keycode == LEFT)
		rc->player->turn = -1;
	else if (keycode == RIGHT)
		rc->player->turn = 1;
	else if (keycode == L_ARROW)
		rc->player->turn_l = 1;
	else if (keycode == R_ARROW)
		rc->player->turn_r = 1;
	else if (keycode == ESC)
		rc->esc = 1;
	else if (keycode == U_ARROW)
		rc->player->look += 5;
	else if (keycode == D_ARROW)
		rc->player->look -= 5;
	return (GOOD);
}
