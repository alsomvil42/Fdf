/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 23:36:59 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/01 15:07:07 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_image(t_env *env)
{
	char		*str;

	env->map.color = mlx_get_color_value(env->mlx_ptr, 0x0FFF30);
	env->mlx_image = mlx_new_image(env->mlx_ptr,
			env->size_image_x, env->size_image_y);
	str = mlx_get_data_addr(env->mlx_image, &env->bpb,
			&env->s_line, &env->endian);
	env->str = (unsigned int *)str;
}

int		deal_key(int key, void *param)
{
	t_env		*env;

	env = (t_env *)param;
	printf("%d\n", key);
	//if (key == 65430 || key == 65432 || key == 65431 || key == 65433)
	if (key)
	{
		ft_create_image(env);
		ft_rotate(env, key);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr,
				env->mlx_image, 0, 0);
		mlx_destroy_image(env->mlx_ptr, env->mlx_image);
	}
	//if (key == 65307)
	if (key == 53)
		exit(1);
	return (0);
}
