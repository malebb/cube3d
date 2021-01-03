/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 08:49:26 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/02 08:33:14 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			init_ver(double current_ray_angle, t_rc *rc, t_ray *ray)
{
	if (current_ray_angle > PI / 2 && current_ray_angle < PI + PI / 2)
	{
		ray->y_ver = rc->player->posy + rc->frame->firsty_v;
		ray->x_ver = rc->player->posx + rc->frame->firstx_v - 1;
	}
	else
	{
		ray->y_ver = rc->player->posy + rc->frame->firsty_v;
		ray->x_ver = rc->player->posx + rc->frame->firstx_v;
	}
}

void			ray_len(t_rc *rc, t_ray *ray, double current_ray_angle)
{
	ray->angle = current_ray_angle;
	if (current_ray_angle > PI / 2 && current_ray_angle < PI + PI / 2)
		ray->x_ver++;
	if (current_ray_angle < PI)
		ray->y_hor++;
	if ((current_ray_angle > PI && current_ray_angle < PI + PI / 2) ||
		(current_ray_angle < PI && current_ray_angle > PI / 2))
		ray->v_len = line_length(rc->player->posx, rc->player->posy,
		ray->x_ver, ray->y_ver);
	else
		ray->v_len = line_length(rc->player->posx, rc->player->posy,
		ray->x_ver, ray->y_ver);
	if (current_ray_angle > 0 && current_ray_angle < PI)
		ray->h_len = line_length(rc->player->posx, rc->player->posy,
		ray->x_hor, ray->y_hor);
	else
		ray->h_len = line_length(rc->player->posx, rc->player->posy,
		ray->x_hor, ray->y_hor);
}

void			ray_vert(t_rc *rc, t_ray *ray, double angle_from_player,
			double *w_height)
{
	ray->side = 0;
	ray->r_len = ray->v_len * cos(angle_from_player);
	ray->x_ray = ray->x_ver;
	ray->y_ray = ray->y_ver;
	*w_height = (SIZE_SQUARE * rc->frame->plane_dist) / ray->r_len;
}

void			ray_hor(t_rc *rc, t_ray *ray, double angle_from_player,
			double *w_height)
{
	ray->side = 1;
	ray->r_len = ray->h_len * cos(angle_from_player);
	ray->x_ray = ray->x_hor;
	ray->y_ray = ray->y_hor;
	*w_height = (SIZE_SQUARE * rc->frame->plane_dist) / ray->r_len;
}

unsigned int	cast_rays(t_rc *rc)
{
	double			gap;
	t_ray			*ray;
	int				i;
	double			current_ray_angle;

	i = 0;
	current_ray_angle = init_casting(rc, &gap);
	while (i < rc->frame->nb_ray)
	{
		ray = NULL;
		if (!init_data_casting(rc, &ray, current_ray_angle))
			return (ER_RC);
		ray_len(rc, ray, current_ray_angle);
		draw_ray(rc, ray, i);
		current_ray_angle -= gap;
		current_ray_angle = adjust_angle(current_ray_angle);
		free_sprite(rc);
		free(ray);
		i++;
	}
	if (save_or_display(rc) != 1)
		return (ER_SAVE);
	return (GOOD);
}
