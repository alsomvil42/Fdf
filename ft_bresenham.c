/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setsegment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:53:34 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/30 16:29:09 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_pixel(t_env *env, int i)
{
	if (((i - (env->size_image_x * env->map.b1)) >= 0) && ((i - (env->size_image_x * env->map.b1)) < env->size_image_x) && i >= 0)
		if (i < env->size_image_x * env->size_image_y)
			env->str[i] = env->map.color;
	
}

void	ft_bresenham(t_env *env)
{
	int		dx;
	int		dy;
	int		e;
	int		i;

	i = 0;
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
							print_pixel(env, i);
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
							print_pixel(env, i);
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
							print_pixel(env, i);
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
							print_pixel(env, i);
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
					print_pixel(env, i);
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
							print_pixel(env, i);
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
							print_pixel(env, i);
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
							print_pixel(env, i);
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
							print_pixel(env, i);
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
					print_pixel(env, i);
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
						print_pixel(env, i);
					env->map.b1 = env->map.b1 + 1;
				}
			}
			else
			{
				while (env->map.b1 != env->map.b2)
				{
					i = (env->size_image_x * env->map.b1) + env->map.a1;
					print_pixel(env, i);
					env->map.b1 = env->map.b1 - 1;
				}
			}
		}
	}
	return ;
}

