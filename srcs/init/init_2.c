/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:49:47 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/02 10:20:45 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_rot(t_rc *rc)
{
	if (rc->p->p == 'N')
		rc->player->rot = PI / 2;
	else if (rc->p->p == 'S')
		rc->player->rot = -(PI / 2);
	else if (rc->p->p == 'E')
		rc->player->rot = 0;
	else if (rc->p->p == 'W')
		rc->player->rot = PI;
}

t_pix	*init_pixel(int r, int g, int b)
{
	t_pix	*pixel;

	if (!(pixel = malloc(sizeof(t_pix) * (1))))
		return (NULL);
	pixel->r = r;
	pixel->g = g;
	pixel->b = b;
	return (pixel);
}

void	init_player(t_rc *rc)
{
	int		t;
	char	*data_player;
	t_pix	*pixel;

	rc->p_map = mlx_new_image(rc->mlx, 3, 3);
	data_player = mlx_get_data_addr(rc->p_map, &t, &t, &t);
	pixel = init_pixel(250, 0, 0);
	fill_pixel(data_player, pixel, 3, 3);
	free(pixel);
}

void	init_bg(t_rc *rc)
{
	int		t;
	int		m_w;
	int		m_h;
	char	*img;
	t_pix	*pixel;

	m_w = 10 * rc->p->width;
	m_h = 10 * rc->p->height;
	rc->m_bg = mlx_new_image(rc->mlx, m_w, m_h);
	img = mlx_get_data_addr(rc->m_bg, &t, &t, &t);
	pixel = init_pixel(75, 180, 5);
	fill_pixel(img, pixel, m_w, m_h);
	free(pixel);
}

void	init_m_map(t_rc *rc)
{
	int		size_w;
	char	*img;
	int		t;
	t_pix	*pixel;

	size_w = SIZE_SQUARE;
	rc->map = 0;
	rc->m_map = mlx_new_image(rc->mlx, size_w, size_w);
	img = mlx_get_data_addr(rc->m_map, &t, &t, &t);
	pixel = init_pixel(25, 250, 100);
	fill_pixel(img, pixel, size_w, size_w);
	free(pixel);
}
