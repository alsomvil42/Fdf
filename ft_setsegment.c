/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setsegment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:53:34 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/16 14:20:06 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_setsegment(unsigned int *str, t_window *win)
{
	int dx;
	int dy;
	int e;
	int		i;

	i = 0;
	if ((dx = win->trace->x2 - win->trace->x1) != 0)
	{
		if (dx > 0)
		{
			if ((dy = win->trace->y2 - win->trace->y1) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = 0;
						dx = (e = dx) * 2;
						dy = dy * 2;
						while (1)
						{
							i = (1500 * win->trace->y1) + win->trace->x1;
							str[i] = win->map->color_map;
							if ((win->trace->x1 = win->trace->x1 + 1) == win->trace->x2)
								break ;
							if ((e = e - dy) < 0)
							{
								win->trace->y1 = win->trace->y1 + 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = 0;
						dy = (e = dy) * 2;
						dx = dx * 2;
						while (1)
						{
							i = (1500 * win->trace->y1) + win->trace->x1;
							str[i] = win->map->color_map;
							if ((win->trace->y1 = win->trace->y1 + 1) == win->trace->y2)
								break ;
							if ((e = e - dx) < 0)
							{
								win->trace->x1 = win->trace->x1 + 1;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						e = 0;
						dx = (e = dx) * 2;
						dy = dy * 2;
						while (1)
						{
							i = (1500 * win->trace->y1) + win->trace->x1;
							str[i] = win->map->color_map;
							if ((win->trace->x1 = win->trace->x1 + 1) == win->trace->x2)
								break ;
							if ((e = e - dy) < 0)
							{
								win->trace->y1 = win->trace->y1 - 1;
								e = e + dx;
							}
						}
						
					}
					else
					{
						e = 0;
						dy = (e = dy) * 2;
						dx = dx * 2;
						while (1)
						{
							i = (1500 * win->trace->y1) + win->trace->x1;
							str[i] = win->map->color_map;
							if ((win->trace->y1 = win->trace->y1 - 1) == win->trace->y2)
								break ;
							if ((e = e + dx) > 0)
							{
								win->trace->x1 = win->trace->x1 + 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while (win->trace->x1 != win->trace->x2)
				{
					i = (1500 * win->trace->y1) + win->trace->x1;
					str[i] = win->map->color_map;
					win->trace->x1 = win->trace->x1 + 1;
				}
			}
		}
		else
		{
			if ((dy = win->trace->y2 - win->trace->y1) != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = 0;
						dx = (e = dx) * 2;
						dy = dy * 2;
						while (1)
						{
							i = (1500 * win->trace->y1) + win->trace->x1;
							str[i] = win->map->color_map;
							if ((win->trace->x1 = win->trace->x1 - 1) == win->trace->x2)
								break ;
							if ((e = e + dy) >= 0)
							{
								win->trace->y1 = win->trace->y1 + 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = 0;
						dy = (e = dy) * 2;
						dx = dx * 2;
						while (1)
						{
							i = (1500 * win->trace->y1) + win->trace->x1;
							str[i] = win->map->color_map;
							if ((win->trace->y1 = win->trace->y1 + 1) == win->trace->y2)
								break ;
							if ((e = e + dx) <= 0)
							{
								win->trace->x1 = win->trace->x1 - 1;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = 0;
						dx = (e = dx) * 2;
						dy = dy * 2;
						while (1)
						{
							i = (1500 * win->trace->y1) + win->trace->x1;
							str[i] = win->map->color_map;
							if ((win->trace->x1 = win->trace->x1 - 1) == win->trace->x2)
								break ;
							if ((e = e - dy) >= 0)
							{
								win->trace->y1 = win->trace->y1 - 1;
								e = e + dx;
							}
						}
						
					}
					else
					{
						e = 0;
						dy = (e = dy) * 2;
						dx = dx * 2;
						while (1)
						{
							i = (1500 * win->trace->y1) + win->trace->x1;
							str[i] = win->map->color_map;
							if ((win->trace->y1 = win->trace->y1 - 1) == win->trace->y2)
								break ;
							if ((e = e - dx) >= 0)
							{
								win->trace->x1 = win->trace->x1 - 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while (win->trace->x1 != win->trace->x2)
				{
					i = (1500 * win->trace->y1) + win->trace->x1;
					str[i] = win->map->color_map;
					win->trace->x1 = win->trace->x1 - 1;
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
					str[i] = win->map->color_map;
					win->trace->y1 = win->trace->y1 + 1;
				}
			}
			else
			{
				while (win->trace->y1 != win->trace->y2)
				{
					i = (1500 * win->trace->y1) + win->trace->x1;
					str[i] = win->map->color_map;
					win->trace->y1 = win->trace->y1 - 1;
				}
			}
		}
	}
	return ;
}

