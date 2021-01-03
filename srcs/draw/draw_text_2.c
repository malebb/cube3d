/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:28:56 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 17:44:54 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

unsigned int	offset_column(t_ray *ray, t_rc *rc)
{
	double		offset_col;
	double		perc_col;
	int			i;

	if (ray->side == 0)
	{
		i = ray->y_ray / SIZE_SQUARE;
		if (ray->angle < PI / 2 || ray->angle > PI + PI / 2)
			offset_col = (ray->y_ray - SIZE_SQUARE * i);
		else
			offset_col = SIZE_SQUARE - (ray->y_ray - SIZE_SQUARE * i);
		perc_col = offset_col / SIZE_SQUARE;
	}
	else
	{
		i = ray->x_ray / SIZE_SQUARE;
		if (ray->angle > PI)
			offset_col = SIZE_SQUARE - (ray->x_ray - SIZE_SQUARE * i);
		else
			offset_col = ray->x_ray - SIZE_SQUARE * i;
		perc_col = offset_col / SIZE_SQUARE;
	}
	return (apply_perc_col(ray, rc, perc_col));
}

double			offset_row_img(t_rc *rc, double offset_value_img,
			double perc_row, t_ray *ray)
{
	double		line_skipped;

	if (ray->side == 1 && ray->angle < PI)
		line_skipped = (rc->text->h_no - (offset_value_img * 2)) * perc_row;
	else if (ray->side == 1)
		line_skipped = (rc->text->h_so - (offset_value_img * 2)) * perc_row;
	else if (ray->side == 0 && ray->angle > PI / 2 && ray->angle < PI + PI / 2)
		line_skipped = (rc->text->h_we - (offset_value_img * 2)) * perc_row;
	else
		line_skipped = (rc->text->h_ea - (offset_value_img * 2)) * perc_row;
	return (line_skipped);
}

void			skip_line(int *l, t_rc *rc, t_ray *ray)
{
	if (ray->side == 1 && ray->angle < PI)
	{
		while (*l / (rc->text->w_no * 4) < rc->frame->offset_value_img +
		rc->frame->line_skipped)
			*l += rc->text->w_no * 4;
	}
	else if (ray->side == 1)
	{
		while (*l / (rc->text->w_so * 4) < rc->frame->offset_value_img +
				rc->frame->line_skipped)
			*l += rc->text->w_so * 4;
	}
	else if (ray->side == 0 && ray->angle > PI / 2 && ray->angle < PI + PI / 2)
	{
		while (*l / (rc->text->w_we * 4) < rc->frame->offset_value_img +
			rc->frame->line_skipped)
			*l += rc->text->w_we * 4;
	}
	else
	{
		while (*l / (rc->text->w_ea * 4) < rc->frame->offset_value_img +
			rc->frame->line_skipped)
			*l += rc->text->w_ea * 4;
	}
}

void			fill_texture(t_rc *rc, int l, int i, t_ray *ray)
{
	if (ray->side == 1 && ray->angle < PI)
	{
		if (l > rc->text->w_no * rc->text->h_no * 4)
			l -= rc->text->w_no * 4;
		rc->frame->rays[i] = rc->text->text_no_data[l];
	}
	else if (ray->side == 1)
	{
		if (l > rc->text->w_so * rc->text->h_so * 4)
			l -= rc->text->w_so * 4;
		rc->frame->rays[i] = rc->text->text_so_data[l];
	}
	else if (ray->side == 0 && ray->angle > PI / 2 && ray->angle < PI + PI / 2)
	{
		if (l > rc->text->w_we * rc->text->h_we * 4)
			l -= rc->text->w_we * 4;
		rc->frame->rays[i] = rc->text->text_we_data[l];
	}
	else
	{
		if (l > rc->text->w_ea * rc->text->h_ea * 4)
			l -= rc->text->w_ea * 4;
		rc->frame->rays[i] = rc->text->text_ea_data[l];
	}
}

unsigned int	apply_offset_value_image_no_so(t_ray *ray, t_rc *rc, int *l,
				double offset_value_img)
{
	unsigned int	w;

	w = 0;
	if (ray->side == 1 && ray->angle < PI)
	{
		while (w < (offset_value_img))
		{
			*l = *l + rc->text->w_no * 4;
			w++;
		}
		return (TRUE);
	}
	else if (ray->side == 1)
	{
		while (w < (offset_value_img))
		{
			*l = *l + rc->text->w_so * 4;
			w++;
		}
		return (TRUE);
	}
	return (FALSE);
}
