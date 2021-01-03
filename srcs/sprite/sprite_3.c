/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:58:39 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 15:25:58 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

unsigned int	is_sprite(t_rc *rc, int x, int y)
{
	if ((rc->p->map)[y][x] == 'R')
		return (2);
	else if ((rc->p->map)[y][x] == 'G')
		return (3);
	return (FALSE);
}

t_sprite		*last_sprite(t_sprite *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void			add_sprite(t_sprite **alst, t_sprite *new)
{
	t_sprite	*last_elem;

	if (!alst || !new)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		new->next = 0;
	}
	else
	{
		last_elem = last_sprite(*alst);
		last_elem->next = new;
		new->next = 0;
	}
}

t_sprite		*new_sprite(void)
{
	t_sprite	*sprite;

	if (!(sprite = malloc(sizeof(t_sprite) * (1))))
		return (ERROR);
	sprite->next = NULL;
	return (sprite);
}

void			sprite_v_data(t_ray *ray, t_sprite *sprite, t_rc *rc)
{
	sprite->len_inter = line_length(rc->player->posx, rc->player->posy,
	ray->x_ver, ray->y_ver);
	sprite->x_mid = (floor(ray->x_ver / SIZE_SQUARE) * SIZE_SQUARE)
	+ SIZE_SQUARE / 2;
	sprite->y_mid = (floor(ray->y_ver / SIZE_SQUARE) * SIZE_SQUARE)
	+ SIZE_SQUARE / 2;
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
