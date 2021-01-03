/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:43:42 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/26 15:03:46 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

unsigned int	insert_sprite_ver(t_sprite *sprite, int sprite_id,
				t_rc *rc, t_ray *ray)
{
	if (!(sprite = new_sprite()))
		return (ERROR);
	sprite->id = sprite_id;
	if (!rc->frame->b_v_sprite)
		rc->frame->b_v_sprite = sprite;
	add_sprite(&(rc->frame->b_v_sprite), sprite);
	sprite_v_data(ray, sprite, rc);
	return (GOOD);
}

unsigned int	find_coor_inter_ver(t_rc *rc, t_ray *ray,
				double current_ray_angle)
{
	t_sprite	*sprite;
	int			sprite_id;

	init_ver(current_ray_angle, rc, ray);
	sprite = NULL;
	if (rc->frame->deltax_v != 0)
	{
		while (ray->y_ver >= 0 && ray->y_ver < SIZE_SQUARE * rc->p->height
		&& ray->x_ver >= 0 && ray->x_ver < SIZE_SQUARE * rc->p->width)
		{
			sprite_id = 0;
			if ((sprite_id = is_sprite(rc, ray->x_ver / SIZE_SQUARE,
			ray->y_ver / SIZE_SQUARE)) != 0)
			{
				if (!insert_sprite_ver(sprite, sprite_id, rc, ray))
					return (ERROR);
			}
			if (is_wall(rc, ray->x_ver / SIZE_SQUARE,
			ray->y_ver / SIZE_SQUARE))
				break ;
			ray->y_ver += rc->frame->deltay_v;
			ray->x_ver += rc->frame->deltax_v;
		}
	}
	return (GOOD);
}

void			draw_ray(t_rc *rc, t_ray *ray, int ray_nb)
{
	double			w_height;
	double			angle_from_player;

	angle_from_player = rc->frame->gap * ray_nb;
	if (angle_from_player > rc->player->fov / 2)
		angle_from_player = (angle_from_player - (rc->player->fov / 2));
	else
		angle_from_player = rc->player->fov / 2 - (angle_from_player);
	if (ray->v_len < ray->h_len)
	{
		ray_vert(rc, ray, angle_from_player, &w_height);
		calculate_offset_w_h(ray_nb, rc, ray);
		draw_texture(rc, ray_nb, w_height, ray);
		if (rc->frame->b_sprite != NULL && rc->frame->b_sprite->r_len != -1)
			draw_sprite(rc, ray_nb, ray);
	}
	else
	{
		ray_hor(rc, ray, angle_from_player, &w_height);
		calculate_offset_w_v(ray_nb, rc, ray);
		draw_texture(rc, ray_nb, w_height, ray);
		if (rc->frame->b_sprite != NULL && rc->frame->b_sprite->r_len != -1)
			draw_sprite(rc, ray_nb, ray);
	}
}

double			init_casting(t_rc *rc, double *gap)
{
	double		current_ray_angle;

	clear_image(rc);
	current_ray_angle = rc->player->rot + (rc->player->fov / 2);
	current_ray_angle = adjust_angle(current_ray_angle);
	rc->frame->nb_ray = rc->p->rx / WIDTH_RAY;
	*gap = rc->player->fov / rc->frame->nb_ray;
	rc->frame->gap = *gap;
	return (current_ray_angle);
}

void			lst_clear(t_sprite **sprite, void (*del)(void *))
{
	t_sprite	*previous_elem;

	if (!sprite || !(*sprite) || !del)
		return ;
	previous_elem = *sprite;
	while ((*sprite) != 0)
	{
		previous_elem = *sprite;
		(*sprite) = (*sprite)->next;
		free(previous_elem);
	}
	(*sprite) = 0;
}
