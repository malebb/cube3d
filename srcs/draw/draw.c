/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 09:01:01 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 15:20:10 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	fill_pixel(char *img, t_pix *pixel, int height, int width)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (i < width * height * 4)
	{
		if (count == 0)
			img[i] = (char)pixel->b;
		else if (count == 1)
			img[i] = (char)pixel->g;
		else if (count == 2)
			img[i] = (unsigned char)pixel->r;
		else if (count == 3)
			count = -1;
		count++;
		i++;
	}
}

void	draw_ceil_rgb(t_rc *rc, unsigned int *count, unsigned int i)
{
	if (*count == 0)
		rc->frame->rays[i] = (unsigned char)rc->p->bc;
	else if (*count == 1)
		rc->frame->rays[i] = (unsigned char)rc->p->gc;
	else if (*count == 2)
		rc->frame->rays[i] = (unsigned char)rc->p->rc;
	else if (*count == 3)
		*count = -1;
	*count = *count + 1;
}

void	draw_floor_rgb(t_rc *rc, unsigned int *count, unsigned int i)
{
	if (*count == 0)
		rc->frame->rays[i] = (unsigned char)rc->p->bf;
	else if (*count == 1)
		rc->frame->rays[i] = (unsigned char)rc->p->gf;
	else if (*count == 2)
		rc->frame->rays[i] = (unsigned char)rc->p->rf;
	else if (*count == 3)
		*count = -1;
	*count = *count + 1;
}

void	clear_image(t_rc *rc)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (i < rc->p->rx * rc->p->ry * 4)
	{
		if (i < ((rc->p->rx * rc->p->ry * 4) / 2))
			draw_ceil_rgb(rc, &count, i);
		else
			draw_floor_rgb(rc, &count, i);
		i++;
	}
}
