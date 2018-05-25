/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setsegment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:53:34 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/25 16:35:51 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham(t_env *env)
{
	int dx;
	int dy;
	int e;
	int		i;
	int		temp;

	i = 0;
	temp = env->map.b1;
	env->map.a1 = env->map.b1;
	env->map.b1 = temp;
	if ((dx = env->map.a2 - env->map.a1) != 0)
	{
		if (dx > 0)
		{
			if ((dy = env->map.b2 - env->map.b1) != 0)
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
							i = (env->size_image_x * env->map.b1) + env->map.a1;
							env->str[i] = env->map.color;
							if ((env->map.a1 = env->map.a1 + 1) == env->map.a2)
								break ;
							if ((e = e - dy) < 0)
							{
								env->map.b1 = env->map.b1 + 1;
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
							i = (env->size_image_x * env->map.b1) + env->map.a1;
							env->str[i] = env->map.color;
							if ((env->map.b1 = env->map.b1 + 1) == env->map.b2)
								break ;
							if ((e = e - dx) < 0)
							{
								env->map.a1 = env->map.a1 + 1;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
//
						e = 0;
						dx = (e = dx) * 2;
						dy = dy * 2;
						while (1)
						{
							i = (env->size_image_x * env->map.b1) + env->map.a1;
							env->str[i] = env->map.color;
							if ((env->map.a1 = env->map.a1 + 1) == env->map.a2)
								break ;
							if ((e = e + dy) < 0)
							{
								env->map.b1 = env->map.b1 - 1;
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
							i = (env->size_image_x * env->map.b1) + env->map.a1;
							env->str[i] = env->map.color;
							if ((env->map.b1 = env->map.b1 - 1) == env->map.b2)
								break ;
							if ((e = e + dx) > 0)
							{
								env->map.a1 = env->map.a1 + 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while (env->map.a1 != env->map.a2)
				{
					i = (env->size_image_x * env->map.b1) + env->map.a1;
					env->str[i] = env->map.color;
					env->map.a1 = env->map.a1 + 1;
				}
			}
		}
		else
		{
			if ((dy = env->map.b2 - env->map.b1) != 0)
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
							i = (env->size_image_x * env->map.b1) + env->map.a1;
							env->str[i] = env->map.color;
							if ((env->map.a1 = env->map.a1 - 1) == env->map.a2)
								break ;
							if ((e = e + dy) >= 0)
							{
								env->map.b1 = env->map.b1 + 1;
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
							i = (env->size_image_x * env->map.b1) + env->map.a1;
							env->str[i] = env->map.color;
							if ((env->map.b1 = env->map.b1 + 1) == env->map.b2)
								break ;
							if ((e = e + dx) <= 0)
							{
								env->map.a1 = env->map.a1 - 1;
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
							i = (env->size_image_x * env->map.b1) + env->map.a1;
							env->str[i] = env->map.color;
							if ((env->map.a1 = env->map.a1 - 1) == env->map.a2)
								break ;
							if ((e = e - dy) >= 0)
							{
								env->map.b1 = env->map.b1 - 1;
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
							i = (env->size_image_x * env->map.b1) + env->map.a1;
							env->str[i] = env->map.color;
							if ((env->map.b1 = env->map.b1 - 1) == env->map.b2)
								break ;
							if ((e = e - dx) >= 0)
							{
								env->map.a1 = env->map.a1 - 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while (env->map.a1 != env->map.a2)
				{
					i = (env->size_image_x * env->map.b1) + env->map.a1;
					env->str[i] = env->map.color;
					env->map.a1 = env->map.a1 - 1;
				}
			}
		}
	}
	else
	{
		if ((dy = env->map.b2 - env->map.b1) != 0)
		{
			if (dy > 0)
			{
				while (env->map.b1 != env->map.b2)
				{
					i = (env->size_image_x * env->map.b1) + env->map.a1;
					env->str[i] = env->map.color;
					env->map.b1 = env->map.b1 + 1;
				}
			}
			else
			{
				while (env->map.b1 != env->map.b2)
				{
					i = (env->size_image_x * env->map.b1) + env->map.a1;
					env->str[i] = env->map.color;
					env->map.b1 = env->map.b1 - 1;
				}
			}
		}
	}
	return ;
}

