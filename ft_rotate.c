/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:50:00 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/03 01:20:53 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_rotate_y(t_env *env, int temp)
{
	int		x1;
	int		y1;
	int		z1;
	int		x1temp;

	x1temp = 0;
	x1 = env->map.space * env->map.pos_x;
	y1 = env->map.space * env->map.pos_y;
	z1 = env->map.tabint[env->map.pos_y][env->map.pos_x];
	if (temp == 0)
	{
		x1temp = x1;
		x1 = x1 * cos(env->map.degres_x * M_PI / 180)
			+ z1 * sin(env->map.degres_x * M_PI / 180);
		env->map.z1temp = x1temp * -sin(env->map.degres_x * M_PI / 180)
			+ z1 * cos(env->map.degres_x * M_PI / 180);
		return (x1);
	}
	if (temp == 1)
	{
		y1 = y1 * cos(env->map.degres_y * M_PI / 180)
			+ env->map.z1temp * -sin(env->map.degres_y * M_PI / 180);
		return (y1);
	}
	return (0);
}

void	ft_next_rotate_2(t_env *env)
{
	env->map.pos_x = 0;
	env->map.pos_y = 0;
	while (env->map.pos_x < env->map.len_x)
	{
		env->map.a1 = ft_rotate_y(env, 0);
		env->map.b1 = ft_rotate_y(env, 1);
		while (env->map.pos_y < env->map.len_y)
		{
			env->map.a2 = ft_rotate_y(env, 0);
			env->map.b2 = ft_rotate_y(env, 1);
			ft_bresenham(env);
			env->map.a1 = env->map.a2;
			env->map.b1 = env->map.b2;
			env->map.pos_y++;
		}
		env->map.pos_x++;
		env->map.pos_y = 0;
	}
}

void	ft_next_rotate(t_env *env)
{
	env->map.pos_x = 0;
	env->map.pos_y = 0;
	while (env->map.pos_y < env->map.len_y)
	{
		env->map.a1 = ft_rotate_y(env, 0);
		env->map.b1 = ft_rotate_y(env, 1);
		while (env->map.pos_x < env->map.len_x)
		{
			env->map.a2 = ft_rotate_y(env, 0);
			env->map.b2 = ft_rotate_y(env, 1);
			ft_bresenham(env);
			env->map.a1 = env->map.a2;
			env->map.b1 = env->map.b2;
			env->map.pos_x++;
		}
		env->map.pos_y++;
		env->map.pos_x = 0;
	}
	ft_next_rotate_2(env);
}

void	ft_rotate_2(t_env *env, int key)
{
	ft_pasdeplace(env, key);
	if (key == 69)
		env->map.space += 2;
	if (key == 78)
	{
		env->map.space -= 2;
		if (env->map.space < 0)
			env->map.space = 0;
	}
	if (key == 123)
		env->mouve -= 10;
	if (key == 124)
		env->mouve += 10;
	if (key == 126)
		env->mouve_vert -= env->size_image_x * 10;
	if (key == 125)
		env->mouve_vert += env->size_image_x * 10;
	env->map.pos_x = 0;
	env->map.pos_y = 0;
	env->map.z1temp = 0;
	ft_next_rotate(env);
}

void	ft_rotate(t_env *env, int key)
{
	if (key == 88)
	{
		if (env->map.degres_x >= 360)
			env->map.degres_x = 0;
		env->map.degres_x += 10;
	}
	if (key == 86)
	{
		if (env->map.degres_x < 10)
			env->map.degres_x = 360;
		env->map.degres_x -= 10;
	}
	if (key == 84)
	{
		if (env->map.degres_y >= 360)
			env->map.degres_y = 0;
		env->map.degres_y += 10;
	}
	if (key == 91)
	{
		if (env->map.degres_y < 10)
			env->map.degres_y = 360;
		env->map.degres_y -= 10;
	}
	ft_rotate_2(env, key);
}
