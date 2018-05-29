/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:50:00 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/29 19:40:08 by alsomvil         ###   ########.fr       */
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
	//printf("BASE %d     ", x1);
	//printf("%d\n", y1);
	//env->map.a2 = x1 * cos(env->map.degres_x * M_PI / 180) + z1 * sin(env->map.degres_x * M_PI /180) + x1 * 1;
	//env->map.b2 = y1 * 1;
	env->map.a2 = x1 * 1;
	env->map.b2 = y1 * cos(env->map.degres_y * M_PI / 180) + z1 * -sin(env->map.degres_y * M_PI /180);
	//printf("MODIF %d     ", env->map.a2);
	//printf("%d\n", env->map.b2);
}

void	ft_rotate(t_env *env, int key)
{
	int		i;

	i = 0;
	if (key == 88)
		env->map.degres_x += 10;
	else if (key == 86)
		env->map.degres_x -= 10;
	else if (key == 84)
		env->map.degres_y += 10;
	else if (key == 91)
		env->map.degres_y -= 10;
	while (env->map.pos_y < env->map.len_y)
	{
		env->map.a1 = 0;
		env->map.b1 = env->map.pos_y * env->map.space + env->map.pos_y;
		while (env->map.pos_x < env->map.len_x)
		{
			env->map.a2 = env->map.a1 + env->map.a1 * env->map.space;
			env->map.b2 = env->map.b1;
			ft_rotate_y(env);
			ft_bresenham(env);
			env->map.pos_x++;
		}
		env->map.pos_y++;
		env->map.pos_x = 0;
	}
	env->map.pos_x = 0;
	env->map.pos_y = 0;
	printf("LEN Y %d     ", env->map.len_y);
	printf("LEN X %d\n     ", env->map.len_x);
	while (env->map.pos_x < env->map.len_x)
	{
		env->map.a2 = env->map.pos_x * env->map.space + env->map.pos_x;
		env->map.b2 = 0;
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
