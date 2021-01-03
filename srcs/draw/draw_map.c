/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:33:08 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 16:38:35 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_bg(t_rc *rc)
{
	mlx_put_image_to_window(rc->mlx, rc->win, rc->m_bg, 0, 0);
}

void	draw_player(t_rc *rc)
{
	mlx_put_image_to_window(rc->mlx, rc->win, rc->p_map,
	(int)rc->player->posx, (int)rc->player->posy);
}
