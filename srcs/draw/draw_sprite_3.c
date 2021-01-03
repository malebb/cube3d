/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:22:21 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 15:21:27 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			apply_offset_value_sprite(t_rc *rc, int *l, t_sprite *sprite)
{
	unsigned int	w;

	w = 0;
	if (sprite->id == 2)
	{
		while (w < (rc->frame->offset_value_sprite))
		{
			*l = *l + rc->sprite_text->w_s1 * 4;
			w++;
		}
	}
	else if (sprite->id == 3)
	{
		while (w < (rc->frame->offset_value_sprite))
		{
			*l = *l + rc->sprite_text->w_s2 * 4;
			w++;
		}
	}
}

double			offset_row_sprite(t_rc *rc, t_sprite *sprite)
{
	double		line_skipped;

	line_skipped = 0;
	if (sprite->id == 2)
	{
		line_skipped = (rc->sprite_text->h_s1 -
		(rc->frame->offset_value_sprite * 2)) * rc->frame->perc_row;
	}
	else if (sprite->id == 3)
	{
		line_skipped = (rc->sprite_text->h_s2 -
		(rc->frame->offset_value_sprite * 2)) * rc->frame->perc_row;
	}
	return (line_skipped);
}

void			skip_line_sprite(int *l, t_rc *rc, double line_skipped,
		t_sprite *sprite)
{
	if (sprite->id == 2)
	{
		while (*l / (rc->sprite_text->w_s1 * 4) <
			rc->frame->offset_value_sprite + line_skipped)
			*l += rc->sprite_text->w_s1 * 4;
	}
	else if (sprite->id == 3)
	{
		while (*l / (rc->sprite_text->w_s2 * 4) <
			rc->frame->offset_value_sprite + line_skipped)
			*l += rc->sprite_text->w_s2 * 4;
	}
}

void			fill_sprite(t_rc *rc, int *l, unsigned int *i,
				t_sprite *sprite)
{
	if (sprite->id == 2)
	{
		if (*l > rc->sprite_text->w_s1 * rc->sprite_text->h_s1 * 4)
			*l = *l - rc->sprite_text->w_s2 * 4;
		rc->frame->rays[*i] = rc->sprite_text->s1_data[*l];
	}
	else if (sprite->id == 3)
	{
		if (*l > rc->sprite_text->w_s2 * rc->sprite_text->h_s2 * 4)
			*l = *l - rc->sprite_text->w_s2 * 4;
		rc->frame->rays[*i] = rc->sprite_text->s2_data[*l];
	}
}

void			select_pix_2(int *l, t_sprite *sprite,
				unsigned int *i, t_rc *rc)
{
	unsigned int	k;
	unsigned int	w;

	k = 0;
	while (k < WIDTH_RAY * 4)
	{
		if (rc->sprite_text->s2_data[*l + 3] == 0)
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
