/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 08:51:52 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 15:03:24 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			first_inter_dir(t_rc *rc, double current_ray_angle)
{
	if (current_ray_angle < PI && current_ray_angle > PI / 2)
	{
		if (rc->frame->firstx_h >= 0)
			rc->frame->firstx_h *= -1;
		if (rc->frame->firsty_h >= 0)
			rc->frame->firsty_h *= -1;
		if (rc->frame->firstx_v >= 0)
			rc->frame->firstx_v *= -1;
		if (rc->frame->firsty_v >= 0)
			rc->frame->firsty_v *= -1;
	}
	else if (current_ray_angle < PI)
	{
		if (rc->frame->firsty_h >= 0)
			rc->frame->firsty_h *= -1;
		if (rc->frame->firsty_v >= 0)
			rc->frame->firsty_v *= -1;
	}
	else if (current_ray_angle > PI && current_ray_angle < PI + PI / 2)
	{
		if (rc->frame->firstx_h >= 0)
			rc->frame->firstx_h *= -1;
		if (rc->frame->firstx_v >= 0)
			rc->frame->firstx_v *= -1;
	}
}

void			delta_dir(t_rc *rc, double current_ray_angle)
{
	if (current_ray_angle < PI && current_ray_angle > PI / 2)
	{
		if (rc->frame->deltax_h >= 0)
			rc->frame->deltax_h *= -1;
		if (rc->frame->deltay_h >= -1)
			rc->frame->deltay_h *= -1;
		if (rc->frame->deltax_v >= 0)
			rc->frame->deltax_v *= -1;
		if (rc->frame->deltay_v >= 0)
			rc->frame->deltay_v *= -1;
	}
	else if (current_ray_angle < PI)
	{
		if (rc->frame->deltay_h >= -1)
			rc->frame->deltay_h *= -1;
		if (rc->frame->deltay_v >= 0)
			rc->frame->deltay_v *= -1;
	}
	else if (current_ray_angle > PI && current_ray_angle < PI + PI / 2)
	{
		if (rc->frame->deltax_h >= 0)
			rc->frame->deltax_h *= -1;
		if (rc->frame->deltax_v >= 0)
			rc->frame->deltax_v *= -1;
	}
}

void			sprite_h_data(t_ray *ray, t_sprite *sprite, t_rc *rc)
{
	sprite->len_inter = line_length(rc->player->posx, rc->player->posy,
			ray->x_hor, ray->y_hor);
	sprite->x_mid = (floor(ray->x_hor / SIZE_SQUARE) * SIZE_SQUARE) +
		SIZE_SQUARE / 2;
	sprite->y_mid = (floor(ray->y_hor / SIZE_SQUARE) * SIZE_SQUARE) +
		SIZE_SQUARE / 2;
	sprite->len_main = line_length(rc->player->posx, rc->player->posy,
			sprite->x_mid, sprite->y_mid);
	sprite->x1_circle = sprite->x_mid + cos(rc->player->rot +
			from_deg_to_rad(90)) * SIZE_SQUARE / 2;
	sprite->y1_circle = sprite->y_mid - sin(rc->player->rot +
			from_deg_to_rad(90)) * SIZE_SQUARE / 2;
	sprite->x2_circle = sprite->x_mid + cos(rc->player->rot +
			from_deg_to_rad(90)) * -SIZE_SQUARE / 2;
	sprite->y2_circle = sprite->y_mid - sin(rc->player->rot +
			from_deg_to_rad(90)) * -SIZE_SQUARE / 2;
	sprite->r_len = sprite->len_main;
}

void			init_hor(double current_ray_angle, t_rc *rc, t_ray *ray)
{
	if (current_ray_angle < PI)
	{
		ray->y_hor = rc->player->posy + rc->frame->firsty_h - 1;
		ray->x_hor = rc->player->posx + rc->frame->firstx_h;
	}
	else
	{
		ray->y_hor = rc->player->posy + rc->frame->firsty_h;
		ray->x_hor = rc->player->posx + rc->frame->firstx_h;
	}
}

unsigned int	find_coor_inter_hor(t_rc *rc, t_ray *ray,
				double current_ray_angle)
{
	t_sprite		*sprite;
	unsigned int	sprite_id;

	init_hor(current_ray_angle, rc, ray);
	while (ray->y_hor >= 0 && ray->y_hor < SIZE_SQUARE * rc->p->height &&
			ray->x_hor >= 0 && ray->x_hor < SIZE_SQUARE * rc->p->width)
	{
		sprite_id = 0;
		if ((sprite_id = is_sprite(rc, ray->x_hor / SIZE_SQUARE, ray->y_hor /
						SIZE_SQUARE)) != 0)
		{
			if (!(sprite = new_sprite()))
				return (ERROR);
			sprite->id = sprite_id;
			if (!rc->frame->b_h_sprite)
				rc->frame->b_h_sprite = sprite;
			add_sprite(&(rc->frame->b_h_sprite), sprite);
			sprite_h_data(ray, sprite, rc);
		}
		if (is_wall(rc, ray->x_hor / SIZE_SQUARE, ray->y_hor / SIZE_SQUARE))
			break ;
		ray->y_hor += rc->frame->deltay_h;
		ray->x_hor += rc->frame->deltax_h;
	}
	return (GOOD);
}
