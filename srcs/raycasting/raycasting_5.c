/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:41:53 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 15:08:20 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			data_rays(t_rc *rc, double current_ray_angle)
{
	first_hor_inter(rc, current_ray_angle);
	first_ver_inter(rc, current_ray_angle);
	delta_hor(rc, current_ray_angle);
	first_inter_dir(rc, current_ray_angle);
	delta_ver(rc, current_ray_angle);
	delta_dir(rc, current_ray_angle);
}

void			calculate_offset_w_h(int ray_nb, t_rc *rc, t_ray *ray)
{
	if (ray_nb == 0)
	{
		if (rc->frame->no_dir == 1 || rc->frame->so_dir == 1)
			rc->frame->offset_w = (int)((SIZE_SQUARE * rc->p->height)
			- ray->y_ver) % SIZE_SQUARE;
		else
			rc->frame->offset_w = (int)(ray->y_ver) % SIZE_SQUARE;
	}
}

void			calculate_offset_w_v(int ray_nb, t_rc *rc, t_ray *ray)
{
	if (ray_nb == 0)
	{
		if (rc->frame->no_dir == 1 || rc->frame->ne_dir == 1)
			rc->frame->offset_w = (int)(ray->x_hor) % SIZE_SQUARE;
		else
			rc->frame->offset_w = (int)((SIZE_SQUARE * rc->p->width)
			- ray->x_hor) % SIZE_SQUARE;
	}
}

void			delta_hor(t_rc *rc, double current_ray_angle)
{
	rc->frame->deltay_h = SIZE_SQUARE;
	if (current_ray_angle < PI)
		rc->frame->deltax_h = rc->frame->deltay_h / tan(current_ray_angle);
	else if (current_ray_angle > PI + PI / 2)
		rc->frame->deltax_h = rc->frame->deltay_h /
			tan((2 * PI) - current_ray_angle);
	else if (current_ray_angle > PI && current_ray_angle < PI + PI / 2)
		rc->frame->deltax_h = rc->frame->deltay_h /
			tan(current_ray_angle - PI);
	else
		rc->frame->deltax_h = rc->frame->deltax_h /
			tan(PI - current_ray_angle);
}

void			delta_ver(t_rc *rc, double current_ray_angle)
{
	rc->frame->deltax_v = SIZE_SQUARE;
	if (current_ray_angle < PI)
		rc->frame->deltay_v = rc->frame->deltax_v * tan(current_ray_angle);
	else if (current_ray_angle > PI + PI / 2)
		rc->frame->deltay_v = rc->frame->deltax_v *
			tan((2 * PI) - current_ray_angle);
	else if (current_ray_angle > PI && current_ray_angle < PI + PI / 2)
		rc->frame->deltay_v = rc->frame->deltax_v *
			tan(current_ray_angle - PI);
	else
		rc->frame->deltay_v = rc->frame->deltax_v *
			tan(PI - current_ray_angle);
}
