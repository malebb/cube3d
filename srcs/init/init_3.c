/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:52:16 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 16:29:15 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			init_dir(t_rc *rc)
{
	rc->frame->no_dir = 0;
	rc->frame->so_dir = 0;
	rc->frame->ne_dir = 0;
	rc->frame->se_dir = 0;
}

unsigned int	read_text(t_rc *rc)
{
	int		w_no;
	int		h_no;
	int		w_so;
	int		h_so;
	int		t;

	if (!(rc->text->text_no = mlx_xpm_file_to_image(rc->mlx, rc->p->no,
		(int *)&w_no, (int *)&h_no)))
		return (ERROR);
	if (!(rc->text->text_no_data = mlx_get_data_addr(rc->text->text_no,
		&t, &t, &t)))
		return (ERROR);
	if (!(rc->text->text_so = mlx_xpm_file_to_image(rc->mlx, rc->p->so,
		(int *)&w_so, (int *)&h_so)))
		return (ERROR);
	if (!(rc->text->text_so_data = mlx_get_data_addr(rc->text->text_so,
		&t, &t, &t)))
		return (ERROR);
	rc->text->w_no = w_no;
	rc->text->h_no = h_no;
	rc->text->w_so = w_so;
	rc->text->h_so = h_so;
	return (GOOD);
}

void			init_struct(t_rc *rc)
{
	rc->text = NULL;
	rc->frame = NULL;
	rc->player = NULL;
	rc->sprite_text = NULL;
}

void			init_img_text(t_rc *rc)
{
	rc->text->text_no = NULL;
	rc->text->text_so = NULL;
	rc->text->text_ea = NULL;
	rc->text->text_we = NULL;
}

void			init_img_sprite(t_rc *rc)
{
	rc->sprite_text->s1 = NULL;
	rc->sprite_text->s2 = NULL;
}
