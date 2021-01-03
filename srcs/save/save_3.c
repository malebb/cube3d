/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:38:09 by mlebrun           #+#    #+#             */
/*   Updated: 2021/01/02 09:35:56 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void			save_img(t_rc *rc)
{
	unsigned int	error;

	error = cast_rays(rc);
	if (error == 0)
	{
		put_rc_error(error);
		free_mem(rc);
		exit(0);
	}
}

unsigned int	hexa_size(unsigned long long int nb)
{
	unsigned int	size;

	size = 1;
	while (nb >= 16)
	{
		nb /= 16;
		size++;
	}
	return (size);
}

void			stock_hexa(unsigned long long int nb, char *nb_hexa,
				char *hexa, int i)
{
	if (nb >= 16)
		stock_hexa(nb / 16, nb_hexa, hexa, i - 1);
	nb_hexa[i] = hexa[nb % 16];
}

int				eq_hexa(char *hexa, char c)
{
	int		i;

	i = 0;
	while (hexa[i] != '\0')
	{
		if (hexa[i] == c)
			return (i);
		i++;
	}
	return (FALSE);
}

int				atoi_hexa(char *nb_hexa)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (nb_hexa[i] != '\0')
	{
		nb *= 16;
		nb += eq_hexa("0123456789ABCDEF", nb_hexa[i]);
		i++;
	}
	return (nb);
}
