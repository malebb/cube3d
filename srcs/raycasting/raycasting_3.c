/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 08:52:16 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 15:07:00 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double			adjust_angle(double current_ray_angle)
{
	if (current_ray_angle < 0)
	{
		while (current_ray_angle < 0 || current_ray_angle < -0.001000)
			current_ray_angle += (2 * PI);
	}
	if (current_ray_angle >= (2 * PI))
	{
		while (current_ray_angle >= (2 * PI))
			current_ray_angle -= (2 * PI);
	}
	return (current_ray_angle);
}

t_ray			*init_ray(void)
{
	t_ray		*ray;

	if (!(ray = malloc(sizeof(t_ray) * 1)))
		return (ERROR);
	ray->x_hor = 0;
	ray->y_hor = 0;
	ray->x_ver = 0;
	ray->y_ver = 0;
	ray->v_len = 0;
	ray->h_len = 0;
	ray->r_len = 0;
	ray->x_ray = 0;
	ray->y_ray = 0;
	return (ray);
}

void			first_hor_inter_under_pi(t_rc *rc, double current_ray_angle)
{
	rc->frame->firsty_h = rc->player->posy - (floor(rc->player->posy /
	SIZE_SQUARE) * SIZE_SQUARE);
	if (current_ray_angle == PI / 2)
		rc->frame->firstx_h = rc->player->posx;
	if (current_ray_angle < PI / 2)
		rc->frame->firstx_h = (rc->frame->firsty_h) /
			tan(current_ray_angle);
	else
		rc->frame->firstx_h = (rc->frame->firsty_h) /
			tan(PI - current_ray_angle);
}

void			first_hor_inter(t_rc *rc, double current_ray_angle)
{
	if (current_ray_angle < PI)
		first_hor_inter_under_pi(rc, current_ray_angle);
	else
	{
		rc->frame->firsty_h = (ceil(rc->player->posy / SIZE_SQUARE) *
		SIZE_SQUARE) - rc->player->posy;
		if (current_ray_angle < PI + PI / 2)
			rc->frame->firstx_h = rc->frame->firsty_h /
			tan(current_ray_angle - PI);
		else
		{
			rc->frame->firstx_h = rc->frame->firsty_h /
			tan((2 * PI) - current_ray_angle);
		}
	}
}

void			first_ver_inter(t_rc *rc, double current_ray_angle)
{
	if (current_ray_angle < PI / 2 || current_ray_angle > PI + PI / 2)
	{
		rc->frame->firstx_v = (ceil(rc->player->posx / SIZE_SQUARE) *
		SIZE_SQUARE) - rc->player->posx;
		if (current_ray_angle < PI / 2)
			rc->frame->firsty_v = ((rc->frame->firstx_v) *
			tan(current_ray_angle));
		if (current_ray_angle > PI + PI / 2)
			rc->frame->firsty_v = ((rc->frame->firstx_v) *
			tan((2 * PI) - current_ray_angle));
	}
	else
	{
		rc->frame->firstx_v = rc->player->posx - (floor(rc->player->posx /
		SIZE_SQUARE) * SIZE_SQUARE);
		if (current_ray_angle > PI && current_ray_angle < PI + PI / 2)
			rc->frame->firsty_v = ((rc->frame->firstx_v) *
			tan(current_ray_angle - PI));
		else
			rc->frame->firsty_v = ((rc->frame->firstx_v) *
			tan(PI - current_ray_angle));
	}
}
