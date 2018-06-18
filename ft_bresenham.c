/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setsegment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 08:53:34 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/18 11:07:45 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_pixel(t_env *env)
{
	int		i;

	i = (env->size_image_x * env->map.y) + env->map.x
		+ env->mouve + env->mouve_vert;
	if (((i - (env->size_image_x * env->map.y + env->mouve_vert)) >= 0)
			&& ((i - (env->size_image_x * env->map.y
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

void	print_seg_down(t_env *env)
{
	int		cumul;
	int		i;

	cumul = env->map.dx / 2;
	i = 1;
	while (i <= env->map.dx)
	{
		env->map.x += env->map.xinc;
		cumul += env->map.dy;
		if (cumul >= env->map.dx)
		{
			cumul -= env->map.dx;
			env->map.y += env->map.yinc;
		}
		print_pixel(env);
		i++;
	}
}

void	print_seg_up(t_env *env)
{
	int		cumul;
	int		i;

	cumul = env->map.dy / 2;
	i = 1;
	while (i <= env->map.dy)
	{
		env->map.y += env->map.yinc;
		cumul += env->map.dx;
		if (cumul >= env->map.dy)
		{
			cumul -= env->map.dy;
			env->map.x += env->map.xinc;
		}
		print_pixel(env);
		i++;
	}
}

void	ft_bresenham(t_env *env)
{
	env->map.x = env->map.a1;
	env->map.y = env->map.b1;
	env->map.dx = env->map.a2 - env->map.a1;
	env->map.dy = env->map.b2 - env->map.b1;
	env->map.xinc = (env->map.dx > 0) ? 1 : -1;
	env->map.yinc = (env->map.dy > 0) ? 1 : -1;
	if (env->map.dx < 0)
		env->map.dx *= -1;
	if (env->map.dy < 0)
		env->map.dy *= -1;
	print_pixel(env);
	if (env->map.dx > env->map.dy)
		print_seg_down(env);
	else
		print_seg_up(env);
}
