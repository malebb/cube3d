/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:02:53 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 15:14:37 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_map(t_rc *rc)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		k;
	unsigned int		l;
	int					size_w;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	size_w = SIZE_SQUARE;
	while (i < rc->p->height)
	{
		j = 0;
		k = 0;
		while (j < rc->p->width)
		{
			if ((rc->p->map)[i][j] == '1')
				mlx_put_image_to_window(rc->mlx, rc->win, rc->m_map, k, l);
			k += size_w;
			j++;
		}
		i++;
		l += size_w;
	}
}

void	update_map(t_rc *rc)
{
	draw_bg(rc);
	draw_map(rc);
	draw_player(rc);
}
