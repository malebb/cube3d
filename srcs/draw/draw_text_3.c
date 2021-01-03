/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:31:18 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 15:22:11 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double			offset_value_image(int offset_row, unsigned int size_w,
				t_rc *rc, t_ray *ray)
{
	double		offset_r;
	double		offset_value_img;
	double		offset_value;

	offset_value = offset_row;
	offset_r = offset_value / (size_w + offset_value * 2);
	if (ray->side == 1 && ray->angle < PI)
		offset_value_img = rc->text->h_no * offset_r;
	else if (ray->side == 1)
		offset_value_img = rc->text->h_so * offset_r;
	else if (ray->side == 0 && ray->angle > PI / 2 && ray->angle < PI + PI / 2)
		offset_value_img = rc->text->h_we * offset_r;
	else
		offset_value_img = rc->text->h_ea * offset_r;
	return (offset_value_img);
}

unsigned int	apply_perc_col(t_ray *ray, t_rc *rc, double perc_col)
{
	if (ray->side == 1 && ray->angle < PI)
		return ((rc->text->w_no) * perc_col);
	else if (ray->side == 1)
		return ((rc->text->w_so) * perc_col);
	else if (ray->side == 0 && ray->angle > PI / 2 && ray->angle < PI + PI / 2)
		return ((rc->text->w_we) * perc_col);
	else
		return ((rc->text->w_ea) * perc_col);
}
