/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:20:10 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 15:16:38 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	select_pix_1(int *l, t_sprite *sprite, unsigned int *i, t_rc *rc)
{
	unsigned int	k;
	unsigned int	w;

	k = 0;
	while (k < WIDTH_RAY * 4)
	{
		if (rc->sprite_text->s1_data[*l + 3] == 0)
		{
			w = 0;
			while (w < 4)
			{
				fill_sprite(rc, l, i, sprite);
				*i = *i + 1;
				*l = *l + 1;
				k++;
				w++;
			}
		}
		else
		{
			*i = *i + 4;
			*l = *l + 4;
			k += 4;
		}
	}
}

void	which_sprite(int *l, t_sprite *sprite, unsigned int *i, t_rc *rc)
{
	if (sprite->id == 2)
		select_pix_1(l, sprite, i, rc);
	else if (sprite->id == 3)
		select_pix_2(l, sprite, i, rc);
}

void	calculate_den(t_ray *ray, t_rc *rc, t_sprite *sprite)
{
	if (ray->side == 0)
	{
		sprite->den = (sprite->x1_circle - sprite->x2_circle) *
		(rc->player->posy - ray->y_ver) - (sprite->y1_circle -
		sprite->y2_circle) * (rc->player->posx - ray->x_ver);
	}
	else
	{
		sprite->den = (sprite->x1_circle - sprite->x2_circle) *
		(rc->player->posy - ray->y_hor) - (sprite->y1_circle -
		sprite->y2_circle) * (rc->player->posx - ray->x_hor);
	}
}

void	line_inter(t_ray *ray, t_rc *rc, t_sprite *sprite)
{
	calculate_den(ray, rc, sprite);
	if (ray->side == 0)
	{
		sprite->t = ((sprite->x1_circle - rc->player->posx) *
		(rc->player->posy - ray->y_ver) -
		(sprite->y1_circle - rc->player->posy) *
		(rc->player->posx - ray->x_ver)) / sprite->den;
	}
	else
	{
		sprite->t = ((sprite->x1_circle - rc->player->posx) *
		(rc->player->posy - ray->y_hor) - (sprite->y1_circle -
		rc->player->posy) * (rc->player->posx - ray->x_hor)) / sprite->den;
	}
	sprite->u = -((sprite->x1_circle - sprite->x2_circle) *
	(sprite->y1_circle - rc->player->posy) - (sprite->y1_circle -
	sprite->y2_circle) * (sprite->x1_circle - rc->player->posx)) / sprite->den;
}

void	manage_sprite_gap(t_rc *rc, t_sprite *sprite, int r_nb)
{
	rc->frame->gap_img = (rc->p->ry / 2) - (sprite->size_s / 2);
	rc->frame->offset_row = 0;
	if (rc->frame->gap_img < 0)
	{
		rc->frame->offset_row = (rc->frame->gap_img * -1);
		rc->frame->gap_img = 0;
		sprite->size_s = rc->p->ry;
	}
	rc->frame->left_gap = WIDTH_RAY * r_nb;
	rc->frame->right_gap = rc->p->rx - rc->frame->left_gap - WIDTH_RAY;
}
