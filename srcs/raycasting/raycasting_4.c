/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 08:57:04 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 15:07:48 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

unsigned int	is_wall(t_rc *rc, int x, int y)
{
	if ((rc->p->map)[y][x] == '1')
		return (TRUE);
	return (FALSE);
}

double			from_deg_to_rad(double deg)
{
	return (deg * (PI / 180));
}

unsigned int	save_or_display(t_rc *rc)
{
	if (rc->save == 0)
		mlx_put_image_to_window(rc->mlx, rc->win, rc->frame->rect, 0, 0);
	else
	{
		if (save(rc) != 1)
			return (ER_SAVE);
		free_mem(rc);
		exit(0);
	}
	return (GOOD);
}

unsigned int	init_data_casting(t_rc *rc, t_ray **ray,
				double current_ray_angle)
{
	if (!(*ray = init_ray()))
		return (ER_RC);
	data_rays(rc, current_ray_angle);
	if (!find_coor_inter_hor(rc, *ray, current_ray_angle) ||
			!find_coor_inter_ver(rc, *ray, current_ray_angle)
			|| !join_sprite(rc))
		return (ER_RC);
	return (GOOD);
}
