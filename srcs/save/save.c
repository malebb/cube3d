/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:32:47 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/03 09:52:41 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

unsigned int		bitmap_info_header(int fd, t_rc *rc)
{
	unsigned int	error;

	error = add_nb_to_file(40, fd, 4);
	error = add_nb_to_file(rc->p->rx, fd, 4);
	error = add_nb_to_file(rc->p->ry, fd, 4);
	error = add_nb_to_file(1, fd, 2);
	error = add_nb_to_file(24, fd, 2);
	error = add_nb_to_file(0, fd, 4);
	error = add_nb_to_file(0, fd, 4);
	error = add_nb_to_file(0, fd, 4);
	error = add_nb_to_file(0, fd, 4);
	error = add_nb_to_file(0, fd, 4);
	error = add_nb_to_file(0, fd, 4);
	return (error);
}

void				fill_pixels_save(int *j, unsigned int *l,
					char *pixels, t_rc *rc)
{
	int				i;
	unsigned int	k;

	i = (rc->p->rx * 4 * *j) - (rc->p->rx * 4);
	k = 0;
	while (k < rc->p->rx * 4)
	{
		pixels[*l] = rc->frame->rays[i];
		*l = *l + 1;
		pixels[*l] = rc->frame->rays[i + 1];
		*l = *l + 1;
		pixels[*l] = rc->frame->rays[i + 2];
		*l = *l + 1;
		k += 4;
		i += 4;
	}
}

void				fill_offset(unsigned int *l, char *pixels,
					unsigned int offset)
{
	unsigned int	k;

	k = 0;
	while (k < offset)
	{
		pixels[*l] = 0;
		*l = *l + 1;
		k++;
	}
}

unsigned int		color_table(int fd, t_rc *rc)
{
	int				j;
	unsigned int	l;
	char			*pixels;
	unsigned int	offset;

	offset = (rc->p->rx * 3) % 4;
	if (!(pixels = malloc(sizeof(char) * (rc->p->ry * rc->p->rx * 3 +
		(offset * rc->p->ry) + 1))))
		return (FALSE);
	pixels[rc->p->ry * rc->p->rx * 3 + offset * rc->p->ry] = '\0';
	l = 0;
	j = rc->p->ry;
	while (j > 0)
	{
		fill_pixels_save(&j, &l, pixels, rc);
		fill_offset(&l, pixels, offset);
		j--;
	}
	write(fd, pixels, (rc->p->ry * rc->p->rx * 3 + offset * rc->p->ry));
	free(pixels);
	return (GOOD);
}

unsigned int		save(t_rc *rc)
{
	int		fd;

	if ((fd = open("img/save/save.bmp", O_WRONLY | O_CREAT, S_IRWXU |
		S_IRWXG | S_IRWXO)) == -1)
		return (ER_SAVE);
	if (!bitmap_file_header(fd, rc) || !bitmap_info_header(fd, rc)
		|| !color_table(fd, rc))
		return (ER_SAVE);
	return (GOOD);
}
