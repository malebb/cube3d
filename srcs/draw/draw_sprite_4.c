/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:24:25 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 14:25:09 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double		offset_value_sprite(int offset_row, unsigned int size_s,
			t_rc *rc, t_sprite *sprite)
{
	double		offset_r;
	double		offset_value_img;
	double		offset_value;

	offset_value = offset_row;
	offset_r = offset_value / (size_s + offset_value * 2);
	offset_value_img = 0;
	if (sprite->id == 2)
		offset_value_img = rc->sprite_text->h_s1 * offset_r;
	else if (sprite->id == 3)
		offset_value_img = rc->sprite_text->h_s2 * offset_r;
	return (offset_value_img);
}
