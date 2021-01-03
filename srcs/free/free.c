/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:05:51 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 19:40:30 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	free_map(t_rc *rc)
{
	unsigned int		i;

	i = 0;
	while (i < rc->p->h_map)
	{
		free(rc->p->map[i]);
		i++;
	}
	free(rc->p->map);
}

void	destroy_images(t_rc *rc)
{
	mlx_destroy_image(rc->mlx, rc->text->text_no);
	mlx_destroy_image(rc->mlx, rc->text->text_so);
	mlx_destroy_image(rc->mlx, rc->text->text_ea);
	mlx_destroy_image(rc->mlx, rc->text->text_we);
	mlx_destroy_image(rc->mlx, rc->sprite_text->s1);
	mlx_destroy_image(rc->mlx, rc->sprite_text->s2);
	mlx_destroy_image(rc->mlx, rc->frame->rect);
	mlx_destroy_image(rc->mlx, rc->p_map);
	mlx_destroy_image(rc->mlx, rc->m_bg);
	mlx_destroy_image(rc->mlx, rc->m_map);
}

void	free_mem(t_rc *rc)
{
	free_map(rc);
	free_path(rc);
	destroy_images(rc);
	if (rc->save == 0)
	{
		mlx_clear_window(rc->mlx, rc->win);
		mlx_destroy_window(rc->mlx, rc->win);
	}
	free(rc->frame);
	free(rc->p);
	free(rc->player);
	free(rc->sprite_text);
	mlx_destroy_display(rc->mlx);
	free(rc->mlx);
	free(rc->text);
	free(rc);
}

void	free_path(t_rc *rc)
{
	free(rc->p->no);
	free(rc->p->so);
	free(rc->p->ea);
	free(rc->p->we);
	free(rc->p->s);
	free(rc->p->s2);
}

void	del(void *content)
{
	free(content);
}
