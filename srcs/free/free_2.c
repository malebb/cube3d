/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:13:04 by mlebrun           #+#    #+#             */
/*   Updated: 2020/12/24 14:13:49 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	free_sprite(t_rc *rc)
{
	if (rc->frame->b_h_sprite != NULL)
	{
		lst_clear(&rc->frame->b_h_sprite, del);
		rc->frame->b_h_sprite = NULL;
	}
	if (rc->frame->b_v_sprite != NULL)
	{
		lst_clear(&rc->frame->b_v_sprite, del);
		rc->frame->b_v_sprite = NULL;
	}
	if (rc->frame->b_sprite != NULL)
	{
		lst_clear(&rc->frame->b_sprite, del);
		rc->frame->b_sprite = NULL;
	}
}
