/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:07:29 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 16:01:27 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

unsigned int		read_text_2(t_rc *rc)
{
	int		w_we;
	int		h_we;
	int		w_ea;
	int		h_ea;
	int		t;

	if (!(rc->text->text_we = mlx_xpm_file_to_image(rc->mlx, rc->p->we,
		(int *)&w_we, (int *)&h_we)))
		return (ERROR);
	if (!(rc->text->text_we_data = mlx_get_data_addr(rc->text->text_we,
		&t, &t, &t)))
		return (ERROR);
	if (!(rc->text->text_ea = mlx_xpm_file_to_image(rc->mlx, rc->p->ea,
		(int *)&w_ea, (int *)&h_ea)))
		return (ERROR);
	if (!(rc->text->text_ea_data = mlx_get_data_addr(rc->text->text_ea,
		&t, &t, &t)))
		return (ERROR);
	rc->text->w_we = w_we;
	rc->text->h_we = h_we;
	rc->text->w_ea = w_ea;
	rc->text->h_ea = h_ea;
	return (GOOD);
}

unsigned int		read_sprite(t_rc *rc)
{
	int		t;
	int		w_s1;
	int		h_s1;
	int		w_s2;
	int		h_s2;

	if (!(rc->sprite_text->s1 = mlx_xpm_file_to_image(rc->mlx, rc->p->s,
		(int *)&w_s1, (int *)&h_s1)))
		return (ERROR);
	if (!(rc->sprite_text->s1_data = mlx_get_data_addr(rc->sprite_text->s1,
		&t, &t, &t)))
		return (ERROR);
	if (!(rc->sprite_text->s2 = mlx_xpm_file_to_image(rc->mlx, rc->p->s2,
		(int *)&w_s2, (int *)&h_s2)))
		return (ERROR);
	if (!(rc->sprite_text->s2_data = mlx_get_data_addr(rc->sprite_text->s2,
		&t, &t, &t)))
		return (ERROR);
	rc->sprite_text->w_s1 = w_s1;
	rc->sprite_text->h_s1 = h_s1;
	rc->sprite_text->w_s2 = w_s2;
	rc->sprite_text->h_s2 = h_s2;
	return (GOOD);
}

void				init_move(t_rc *rc)
{
	rc->player->turn = 0;
	rc->player->turn_l = 0;
	rc->player->turn_r = 0;
	rc->player->go = 0;
	if (rc->p->rx < 250 || rc->p->ry < 150)
		rc->player->vel = 0.25;
	else if (rc->p->rx <= 500 || rc->p->ry < 250)
		rc->player->vel = 0.5;
	else if (rc->p->rx <= 1000 || rc->p->ry <= 500)
		rc->player->vel = 1.5;
	else if (rc->p->rx < 1500 || rc->p->ry < 750)
		rc->player->vel = 2;
	else
		rc->player->vel = 3;
	rc->player->posy = (floor(rc->p->px) * SIZE_SQUARE) + SIZE_SQUARE / 2;
	rc->player->posx = (floor(rc->p->py) * SIZE_SQUARE) + SIZE_SQUARE / 2;
	rc->player->rot_s = from_deg_to_rad(10);
}

unsigned int		init_frame(t_rc *rc)
{
	int		t;

	rc->player->fov = (66 * PI / 180);
	if (!(rc->frame = malloc(sizeof(t_frame) * (1))))
		return (ERROR);
	rc->frame->nb_ray = 0;
	if (!(rc->frame->rect = mlx_new_image(rc->mlx, rc->p->rx, rc->p->ry)))
		return (ERROR);
	if (!(rc->frame->rays = mlx_get_data_addr(rc->frame->rect,
		&rc->frame->bpp_rays, &t, &t)))
		return (ERROR);
	rc->frame->plane_dist = (rc->p->rx / 2) / tan(rc->player->fov / 2);
	rc->frame->b_h_sprite = NULL;
	rc->frame->b_v_sprite = NULL;
	rc->frame->b_sprite = NULL;
	return (GOOD);
}

unsigned int		init_rc(t_rc *rc)
{
	rc->esc = 0;
	init_struct(rc);
	if (!(rc->text = malloc(sizeof(t_text) * (1))))
		return (ERROR);
	init_img_text(rc);
	if (!(rc->sprite_text = malloc(sizeof(t_sprite_text) * (1))))
		return (ERROR);
	init_img_sprite(rc);
	if (!read_text(rc) || !read_text_2(rc) || !read_sprite(rc))
		return (ERROR);
	if (!(rc->player = malloc(sizeof(t_player) * (1))))
		return (ERROR);
	if (!init_frame(rc))
		return (ERROR);
	init_move(rc);
	init_bg(rc);
	init_m_map(rc);
	init_player(rc);
	init_rot(rc);
	init_dir(rc);
	return (GOOD);
}
