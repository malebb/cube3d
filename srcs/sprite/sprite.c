/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:47:53 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 15:25:04 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

unsigned int		add_closest(t_rc *rc, t_sprite **h_sprite,
					t_sprite **v_sprite)
{
	t_sprite	*error;

	error = 0;
	if ((*h_sprite)->len_inter <= (*v_sprite)->len_inter)
	{
		add_sprite(&rc->frame->b_sprite, (error = dup_sprite(*h_sprite)));
		if (!error)
			return (ERROR);
		if ((*h_sprite)->x_mid == (*v_sprite)->len_inter
				&& (*h_sprite)->y_mid == (*v_sprite)->y_mid)
		{
			(*h_sprite) = (*h_sprite)->next;
			(*v_sprite) = (*v_sprite)->next;
		}
		else
			(*h_sprite) = (*h_sprite)->next;
	}
	else
	{
		add_sprite(&rc->frame->b_sprite, (error = dup_sprite(*v_sprite)));
		if (!error)
			return (ERROR);
		(*v_sprite) = (*v_sprite)->next;
	}
	return (GOOD);
}

unsigned int		add_closest_vert(t_rc *rc, t_sprite **v_sprite)
{
	t_sprite	*error;

	error = NULL;
	add_sprite(&rc->frame->b_sprite, (error = dup_sprite(*v_sprite)));
	if (!error)
		return (ERROR);
	(*v_sprite) = (*v_sprite)->next;
	return (GOOD);
}

unsigned int		add_closest_hor(t_rc *rc, t_sprite **h_sprite)
{
	t_sprite	*error;

	error = NULL;
	add_sprite(&rc->frame->b_sprite, (error = dup_sprite(*h_sprite)));
	if (!error)
		return (ERROR);
	(*h_sprite) = (*h_sprite)->next;
	return (GOOD);
}

unsigned int		join_sprite(t_rc *rc)
{
	t_sprite		*h_sprite;
	t_sprite		*v_sprite;

	h_sprite = rc->frame->b_h_sprite;
	v_sprite = rc->frame->b_v_sprite;
	while (h_sprite != NULL || v_sprite != NULL)
	{
		if (h_sprite != NULL && v_sprite != NULL)
		{
			if (!add_closest(rc, &h_sprite, &v_sprite))
				return (ERROR);
		}
		else if (v_sprite != NULL)
		{
			if (!add_closest_vert(rc, &v_sprite))
				return (ERROR);
		}
		else if (h_sprite != NULL)
		{
			if (!add_closest_hor(rc, &h_sprite))
				return (ERROR);
		}
	}
	return (GOOD);
}

t_sprite			*dup_sprite(t_sprite *sprite)
{
	t_sprite	*new_sprite;

	if (!(new_sprite = malloc(sizeof(t_sprite) * (1))))
		return (ERROR);
	new_sprite->x_mid = sprite->x_mid;
	new_sprite->y_mid = sprite->y_mid;
	new_sprite->len_main = sprite->len_main;
	new_sprite->len_inter = sprite->len_inter;
	new_sprite->angle_to_rot = sprite->angle_to_rot;
	new_sprite->r_len = sprite->r_len;
	new_sprite->x1_circle = sprite->x1_circle;
	new_sprite->y1_circle = sprite->y1_circle;
	new_sprite->x2_circle = sprite->x2_circle;
	new_sprite->y2_circle = sprite->y2_circle;
	new_sprite->id = sprite->id;
	new_sprite->next = 0;
	return (new_sprite);
}
