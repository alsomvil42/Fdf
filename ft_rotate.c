/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:50:00 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/25 16:42:58 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_y(t_env *env)
{
	int		y1;
	int		z1;
	int		x1;

	x1 = env->map.space * env->map.pos_x + env->map.pos_x;
	y1 = env->map.space * env->map.pos_y + env->map.pos_y;
	z1 = env->map.tabint[env->map.pos_y][env->map.pos_x];
	printf("%d     ", x1);
	printf("%d     ", y1);
	printf("%d\n", z1);
	//env->map.a1 = y1 * cos(10 * M_PI / 180) + z1 * sin(10 * M_PI /180);
	//env->map.b1 = y1 * -sin(10 * M_PI / 180) + z1 * cos(10 * M_PI /180);
	//printf("%d    ", env->map.a2);
	//printf("%d\n", env->map.b2);
	//env->map.a1 = 10;
	//env->map.b1 = 20;
	//env->map.a2 = 50;
	//env->map.b2 = 20;
	//printf("%d    ", env->map.a1);
	//printf("%d\n", env->map.b1);
}

void	ft_rotate(t_env *env, int key)
{
	if (key == 88)
		env->map.degres_x += 10;
	else if (key == 86)
		env->map.degres_x -= 10;
	while (env->map.pos_y < env->map.len_y)
	{
		env->map.pos_x = 0;
		while (env->map.pos_x < env->map.len_x)
		{
			ft_rotate_y(env);
			ft_bresenham(env);
			env->map.pos_x++;
		}
		env->map.pos_y++;
	}
}
