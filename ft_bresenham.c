/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setsegment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:53:34 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/14 19:05:20 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_pixel(t_env *env)
{
	int		i;

	i = (env->size_image_x * env->map.b1) + env->map.a1
		+ env->mouve + env->mouve_vert;
	if (((i - (env->size_image_x * env->map.b1 + env->mouve_vert)) >= 0)
			&& ((i - (env->size_image_x * env->map.b1
						+ env->mouve_vert)) < env->size_image_x) && i >= 0)
		if (i < env->size_image_x * env->size_image_y)
		{
			if (env->map.tabint[env->map.pos_y][env->map.pos_x] <= 0)
				env->map.color = mlx_get_color_value(env->mlx_ptr, 0xE1E1E1);
			else if (env->map.tabint[env->map.pos_y][env->map.pos_x] > 0)
				env->map.color = mlx_get_color_value(env->mlx_ptr, 0x0FFF30);
			env->str[i] = env->map.color;
		}
}

void	ft_bresenham(t_env *env)
{
	int		dx;
	int		dy;
	int		e;

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
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (1)
						{
							print_pixel(env);
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
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while (1)
						{
							print_pixel(env);
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
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (1)
						{
							print_pixel(env);
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
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while (1)
						{
							print_pixel(env);
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
					print_pixel(env);
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
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (1)
						{
							print_pixel(env);
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
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while (1)
						{
							print_pixel(env);
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
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (1)
						{
							print_pixel(env);
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
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while (1)
						{
							print_pixel(env);
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
					print_pixel(env);
					env->map.a1 = env->map.a1 - 1;
				}
			}
		}
	}
	else if ((dy = env->map.b2 - env->map.b1) != 0)
	{
		if (dy > 0)
		{
			while (env->map.b1 != env->map.b2)
			{
				print_pixel(env);
				env->map.b1 = env->map.b1 + 1;
			}
		}
		else
		{
			while (env->map.b1 != env->map.b2)
			{
				print_pixel(env);
				env->map.b1 = env->map.b1 - 1;
			}
		}
	}
	return ;
}
