/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:26:23 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 17:45:11 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	apply_offset_value_image(t_rc *rc, double offset_value_img,
		int *l, t_ray *ray)
{
	unsigned int	w;

	if (!apply_offset_value_image_no_so(ray, rc, l, offset_value_img))
	{
		w = 0;
		if (ray->side == 0 && ray->angle > PI / 2 && ray->angle < PI + PI / 2)
		{
			while (w < (offset_value_img))
			{
				*l = *l + rc->text->w_we * 4;
				w++;
			}
		}
		else
		{
			while (w < (offset_value_img))
			{
				*l = *l + rc->text->w_ea * 4;
				w++;
			}
		}
	}
}

void	manage_gap(t_rc *rc, int r_nb, unsigned int *size_w)
{
	rc->frame->gap_img = ((rc->p->ry / 2) - (*size_w / 2));
	rc->frame->offset_row = 0;
	if (rc->frame->gap_img < 0)
	{
		rc->frame->offset_row = (rc->frame->gap_img * -1);
		rc->frame->gap_img = 0;
		*size_w = rc->p->ry;
	}
	rc->frame->left_gap = WIDTH_RAY * r_nb;
	rc->frame->right_gap = rc->p->rx - rc->frame->left_gap - WIDTH_RAY;
}

void	manage_offset(int *l, t_ray *ray, t_rc *rc, unsigned int size_w)
{
	*l = 0;
	*l = *l + offset_column(ray, rc) * 4;
	rc->frame->offset_value_img = offset_value_image(rc->frame->offset_row,
	size_w, rc, ray);
	apply_offset_value_image(rc, rc->frame->offset_value_img, l, ray);
}

void	browse_width_ray(t_rc *rc, int *l, int *i, t_ray *ray)
{
	int		k;

	k = 0;
	while (k < WIDTH_RAY * 4)
	{
		fill_texture(rc, *l, *i, ray);
		*i = *i + 1;
		*l = *l + 1;
		k++;
	}
}

void	draw_texture(t_rc *rc, int r_nb, unsigned int size_w, t_ray *ray)
{
	int					i;
	unsigned int		j;
	int					l;
	double				perc_row;
	double				row_nb;

	manage_gap(rc, r_nb, &size_w);
	manage_offset(&l, ray, rc, size_w);
	i = 0;
	i += rc->frame->gap_img * rc->p->rx * 4;
	row_nb = rc->frame->offset_value_img;
	j = 0;
	while (j < size_w && j < rc->p->ry)
	{
		perc_row = (double)j / (double)size_w;
		rc->frame->line_skipped = offset_row_img(rc,
		rc->frame->offset_value_img, perc_row, ray);
		skip_line(&l, rc, ray);
		i += rc->frame->left_gap * 4;
		browse_width_ray(rc, &l, &i, ray);
		i += rc->frame->right_gap * 4;
		l -= WIDTH_RAY * 4;
		j++;
	}
}
