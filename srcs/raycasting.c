/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:09:59 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 16:54:08 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			update_dir(t_rc *rc)
{
	double		angle_player;

	angle_player = rc->player->rot;
	angle_player = adjust_angle(angle_player);
	rc->frame->no_dir = 0;
	rc->frame->ne_dir = 0;
	rc->frame->se_dir = 0;
	rc->frame->so_dir = 0;
	if (angle_player < PI / 2)
		rc->frame->ne_dir = 1;
	else if (angle_player < PI)
		rc->frame->no_dir = 1;
	else if (angle_player < PI + PI / 2)
		rc->frame->so_dir = 1;
	else
		rc->frame->se_dir = 1;
}

void			update_img(t_rc *rc)
{
	if (rc->save == 0)
	{
		turn(rc);
		move(rc);
		update_dir(rc);
		if (rc->map)
			update_map(rc);
	}
}

int				update(t_rc *rc)
{
	unsigned int	error;

	error = 0;
	if (rc->esc == 1 && rc->save == 0)
	{
		free_mem(rc);
		exit(0);
	}
	error = cast_rays(rc);
	if (error == 1)
		update_img(rc);
	else
	{
		put_rc_error(error);
		free_mem(rc);
		exit(0);
	}
	return (GOOD);
}

void			free_img(t_rc *rc)
{
	free_map(rc);
	free_path(rc);
	if (rc->text->text_no != NULL)
		mlx_destroy_image(rc->mlx, rc->text->text_no);
	if (rc->text->text_so != NULL)
		mlx_destroy_image(rc->mlx, rc->text->text_so);
	if (rc->text->text_ea != NULL)
		mlx_destroy_image(rc->mlx, rc->text->text_ea);
	if (rc->text->text_we != NULL)
		mlx_destroy_image(rc->mlx, rc->text->text_we);
	if (rc->sprite_text->s1 != NULL)
		mlx_destroy_image(rc->mlx, rc->sprite_text->s1);
	if (rc->sprite_text->s2 != NULL)
		mlx_destroy_image(rc->mlx, rc->sprite_text->s2);
	free(rc->frame);
	free(rc->p);
	free(rc->player);
	free(rc->sprite_text);
	mlx_destroy_display(rc->mlx);
	free(rc->mlx);
	free(rc->text);
	free(rc);
}

unsigned int	start_graphic(t_rc *rc)
{
	rc->mlx = mlx_init();
	check_resolution(rc);
	if (!init_rc(rc))
	{
		free_img(rc);
		return (ERROR);
	}
	if (rc->save == 0)
	{
		rc->win = mlx_new_window(rc->mlx, rc->p->rx, rc->p->ry, "Cub3d");
		mlx_hook(rc->win, 2, 1L << 0, keypressed, rc);
		mlx_hook(rc->win, 3, 1L << 1, keyrelease, rc);
		mlx_hook(rc->win, 33, 1L << 13, redcross, rc);
	}
	else
		save_img(rc);
	mlx_loop_hook(rc->mlx, update, rc);
	mlx_loop(rc->mlx);
	return (GOOD);
}
