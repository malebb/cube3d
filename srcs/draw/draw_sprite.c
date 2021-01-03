/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:17:37 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 15:20:41 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			init_sprite_data(int *l, t_sprite *sprite, t_rc *rc, int r_nb)
{
	double		offset_col_pix;
	double		offset_col_perc;

	sprite->size_s = (SIZE_SQUARE * rc->frame->plane_dist) / sprite->r_len;
	sprite->inter_x = sprite->x1_circle + sprite->t *
	(sprite->x2_circle - sprite->x1_circle);
	sprite->inter_y = sprite->y1_circle + sprite->t *
	(sprite->y2_circle - sprite->y1_circle);
	offset_col_pix = line_length(sprite->x1_circle, sprite->y1_circle,
	sprite->inter_x, sprite->inter_y);
	offset_col_perc = (double)((double)offset_col_pix / (double)SIZE_SQUARE);
	manage_sprite_gap(rc, sprite, r_nb);
	*l = 0;
	*l = *l + (offset_col_perc * (double)rc->sprite_text->w_s1);
	*l = *l * 4;
	rc->frame->offset_value_sprite =
	offset_value_sprite(rc->frame->offset_row, sprite->size_s, rc, sprite);
	apply_offset_value_sprite(rc, l, sprite);
}

void			update_canvas(unsigned int *i, int *l,
				t_sprite *sprite, t_rc *rc)
{
	*i = *i + rc->frame->left_gap * 4;
	which_sprite(l, sprite, i, rc);
	*i = *i + rc->frame->right_gap * 4;
	*l = *l - WIDTH_RAY * 4;
}

t_sprite		*reverse_sprite(t_sprite *b_sprite)
{
	t_sprite	*previous_sprite;
	t_sprite	*next_sprite;
	t_sprite	*sprite;
	int			i;

	i = 0;
	sprite = b_sprite;
	while (sprite != NULL)
	{
		next_sprite = sprite->next;
		if (i == 0)
			sprite->next = 0;
		else
			sprite->next = previous_sprite;
		previous_sprite = sprite;
		sprite = next_sprite;
		i++;
	}
	return (previous_sprite);
}

unsigned int	collide_sprite(t_sprite *sprite)
{
	if (sprite->t >= 0 && sprite->t <= 1 && sprite->u >= 0 && sprite->u < 1)
		return (TRUE);
	return (FALSE);
}

void			draw_sprite(t_rc *rc, int r_nb, t_ray *ray)
{
	unsigned int		i;
	unsigned int		j;
	int					l;
	t_sprite			*sprite;

	sprite = reverse_sprite(rc->frame->b_sprite);
	rc->frame->b_sprite = sprite;
	while (sprite != NULL)
	{
		line_inter(ray, rc, sprite);
		if (collide_sprite(sprite))
		{
			init_sprite_data(&l, sprite, rc, r_nb);
			i = rc->frame->gap_img * rc->p->rx * 4;
			j = -1;
			while (++j < sprite->size_s && j < rc->p->ry)
			{
				rc->frame->perc_row = (double)j / (double)sprite->size_s;
				rc->frame->line_skipped = offset_row_sprite(rc, sprite);
				skip_line_sprite(&l, rc, rc->frame->line_skipped, sprite);
				update_canvas(&i, &l, sprite, rc);
			}
		}
		sprite = sprite->next;
	}
}
