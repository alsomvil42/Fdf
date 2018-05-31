/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:50:00 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/31 12:29:33 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_y(t_env *env)
{
	int		x1;
	int		y1;
	int		z1;

	x1 = 0;
	y1 = 0;
	z1 = 0;
	env->map.a1 = env->map.a2;
	env->map.b1 = env->map.b2;
	x1 = env->map.space * env->map.pos_x + env->map.pos_x;
	y1 = env->map.space * env->map.pos_y + env->map.pos_y;
	z1 = env->map.tabint[env->map.pos_y][env->map.pos_x];
	env->map.a2 = x1 * 1;
	env->map.a2 = env->map.a2 * cos(env->map.degres_x * M_PI / 180) + z1 * sin(env->map.degres_x * M_PI /180);
	env->map.b2 = y1 * cos(env->map.degres_y * M_PI / 180)
		+ z1 * -sin(env->map.degres_y * M_PI / 180);
	env->map.b2 = env->map.b2 * 1;
}

int		ft_modif_point(t_env *env, int pos)
{
	int		x1;
	int		y1;
	int		z1;

	x1 = env->map.space * env->map.pos_x + env->map.pos_x;
	y1 = env->map.space * env->map.pos_y + env->map.pos_y;
	z1 = env->map.tabint[env->map.pos_y][env->map.pos_x];
	if (pos == 0)
	{
		x1 = x1 * 1;
		x1 = x1 * cos(env->map.degres_x * M_PI / 180) + z1 * sin(env->map.degres_x * M_PI / 180);
		return (x1);
	}
	else if (pos == 1)
	{
		y1 = (y1 * cos(env->map.degres_y * M_PI / 180) + z1 * -sin(env->map.degres_y * M_PI / 180));
		y1 = y1 * 1;
	}
	return (0);
}

void	ft_next_rotate(t_env *env)
{
	while (env->map.pos_x < env->map.len_x)
	{
		env->map.a2 = ft_modif_point(env, 0);
		env->map.b2 = ft_modif_point(env, 1);
		while (env->map.pos_y < env->map.len_y)
		{
			ft_rotate_y(env);
			ft_bresenham(env);
			env->map.pos_y++;
		}
		env->map.pos_x++;
		env->map.pos_y = 0;
	}
	env->map.pos_x = 0;
	env->map.pos_y = 0;
}

void	ft_rotate(t_env *env, int key)
{
	//if (key == 65430)
	if (key == 88)
		env->map.degres_x += 10;
	//else if (key == 65432)
	if (key == 86)
		env->map.degres_x -= 10;
	//else if (key == 65431)
	if (key == 84)
		env->map.degres_y += 10;
	//else if (key == 65433)
	if (key == 91)
		env->map.degres_y -= 10;
	if (key == 69)
		env->map.space += 10;
	if (key == 78)
	{
		env->map.space -= 10;
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
	while (env->map.pos_y < env->map.len_y)
	{
		env->map.a2 = ft_modif_point(env, 0);
		env->map.b2 = ft_modif_point(env, 1);
		while (env->map.pos_x < env->map.len_x)
		{
			ft_rotate_y(env);
			ft_bresenham(env);
			env->map.pos_x++;
		}
		env->map.pos_y++;
		env->map.pos_x = 0;
	}
	env->map.pos_x = 0;
	env->map.pos_y = 0;
	ft_next_rotate(env);
}
