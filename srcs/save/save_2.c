/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:35:37 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 17:39:25 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

char			*ini_nb(int size_nb, char *nb_hexa)
{
	char				*nb;

	if (!(nb = malloc(sizeof(char) * 3)))
		return (ERROR);
	nb[2] = '\0';
	if (size_nb == 0)
	{
		nb[0] = '0';
		nb[1] = nb_hexa[0];
	}
	return (nb);
}

void			fill_nb(int size_nb, char *nb, char *nb_hexa)
{
	int				j;
	unsigned int	i;

	j = 1;
	i = 0;
	while (j >= 0)
	{
		nb[i] = nb_hexa[size_nb - j];
		i++;
		j--;
	}
}

unsigned int	add_to_file(char *nb_hexa, int fd, int size_nb)
{
	char				*nb;

	while (size_nb >= 0)
	{
		if (!(nb = ini_nb(size_nb, nb_hexa)))
		{
			free(nb);
			return (ERROR);
		}
		if (size_nb != 0)
			fill_nb(size_nb, nb, nb_hexa);
		ft_putchar_fd(atoi_hexa(nb), fd);
		size_nb -= 2;
		free(nb);
	}
	return (GOOD);
}

unsigned int	add_nb_to_file(unsigned long long int nb, int fd,
				unsigned int nb_byte)
{
	unsigned int	size;
	char			*nb_hexa;
	unsigned int	i;

	size = hexa_size(nb);
	if (!(nb_hexa = malloc(sizeof(char) * (size + 1))))
		return (FALSE);
	nb_hexa[size] = '\0';
	stock_hexa(nb, nb_hexa, "0123456789ABCDEF", size - 1);
	if (!add_to_file(nb_hexa, fd, size - 1))
	{
		free(nb_hexa);
		return (ERROR);
	}
	i = size;
	if (i % 2 != 0)
		i++;
	while (i < nb_byte * 2)
	{
		ft_putchar_fd(0, fd);
		i += 2;
	}
	free(nb_hexa);
	return (TRUE);
}

unsigned int	bitmap_file_header(int fd, t_rc *rc)
{
	unsigned int	error;

	ft_putchar_fd('B', fd);
	ft_putchar_fd('M', fd);
	error = add_nb_to_file((rc->p->rx * rc->p->ry * 3 + 54), fd, 4);
	error = add_nb_to_file(0, fd, 2);
	error = add_nb_to_file(0, fd, 2);
	error = add_nb_to_file(54, fd, 4);
	return (error);
}
