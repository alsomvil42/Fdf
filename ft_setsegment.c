/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setsegment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:53:34 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/18 04:55:33 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_setsegment(unsigned int *str, t_window *win)
{
	int dx;
	int dy;
	int		i;

	i = 0;
	if ((dx = win->trace->x2 - win->trace->x1) != 0)
	{
		if (dx > 0)
		{
			if ((dy = win->trace->y2 - win->trace->y1) == 0)
			{
				while (win->trace->x1 != win->trace->x2)
				{
					i = (1500 * win->trace->y1) + win->trace->x1;
					if (((i - (1500 * win->trace->y1)) > 0)
							&& ((i - (1500 * win->trace->y1)) < 1500)
							&& i >= 0)
						str[i] = win->map->color_map;
					win->trace->x1 = win->trace->x1 + 1;
				}
			}
		}
	}
	else
	{
		if ((dy = win->trace->y2 - win->trace->y1) != 0)
		{
			if (dy > 0)
			{
				while (win->trace->y1 != win->trace->y2)
				{
					i = (1500 * win->trace->y1) + win->trace->x1;
					if (((i - (1500 * win->trace->y1)) > 0)
							&& ((i - (1500 * win->trace->y1)) < 1500)
							&& i >= 0)
						str[i] = win->map->color_map;
					win->trace->y1 = win->trace->y1 + 1;
				}
			}
		}
	}
	return ;
}

