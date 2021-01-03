/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:04:55 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 07:39:34 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	run(t_rc *rc)
{
	if (rc->player->run == 1)
	{
		rc->player->vel /= 2;
		rc->player->run = 0;
	}
	else
	{
		rc->player->vel *= 2;
		rc->player->run = 1;
	}
}

void	turn(t_rc *rc)
{
	if (rc->player->turn_r)
		rc->player->rot -= rc->player->rot_s;
	if (rc->player->turn_l)
		rc->player->rot += rc->player->rot_s;
}

void	move_up_down(t_rc *rc)
{
	int		new_posx;
	int		new_posy;
	int		step;

	step = (rc->player->turn * rc->player->vel + 3) * rc->player->go;
	rc->player->step = rc->player->go * rc->player->vel;
	new_posx = (rc->player->posx + cos(rc->player->rot) * step) / SIZE_SQUARE;
	new_posy = (rc->player->posy - sin(rc->player->rot) * step) / SIZE_SQUARE;
	if ((rc->p->map)[(int)rc->player->posy / SIZE_SQUARE][new_posx] != '1')
		rc->player->posx += cos(rc->player->rot) * rc->player->step;
	if ((rc->p->map)[new_posy][(int)rc->player->posx / SIZE_SQUARE] != '1')
		rc->player->posy -= sin(rc->player->rot) * rc->player->step;
}

void	move_left_right(t_rc *rc)
{
	int		new_posx;
	int		new_posy;
	int		step;

	if (rc->player->turn == -1)
		step = rc->player->turn * rc->player->vel - 3;
	else
		step = rc->player->turn * rc->player->vel + 3;
	new_posx = (int)((rc->player->posx + cos(rc->player->rot -
	from_deg_to_rad(90)) * step)) / SIZE_SQUARE;
	new_posy = (int)((rc->player->posy - sin(rc->player->rot -
	from_deg_to_rad(90)) * step)) / SIZE_SQUARE;
	rc->player->step = rc->player->turn * rc->player->vel;
	if ((rc->p->map)[(int)rc->player->posy / (SIZE_SQUARE)][new_posx] != '1')
		rc->player->posx += cos(rc->player->rot - from_deg_to_rad(90)) *
		rc->player->step;
	if ((rc->p->map)[new_posy][(int)rc->player->posx / (SIZE_SQUARE)] != '1')
		rc->player->posy -= sin(rc->player->rot - from_deg_to_rad(90)) *
		rc->player->step;
}

void	move(t_rc *rc)
{
	if (rc->player->go != 0)
		move_up_down(rc);
	else if (rc->player->go == 0 && rc->player->turn != 0)
		move_left_right(rc);
}
