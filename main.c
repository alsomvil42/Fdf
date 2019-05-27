/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:27:50 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/25 14:35:47 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_struct2(t_env *env)
{
	env->mouve = 0;
	env->mouve_vert = 0;
	env->size_image_x = 1800;
	env->size_image_y = 1000;
	env->size_win_x = 1800;
	env->size_win_y = 1000;
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	env->bpb = 0;
	env->s_line = 0;
	env->endian = 0;
	env->str = NULL;
	env->mlx_image = NULL;
}

void	ft_init_struct(t_env *env)
{
	env->map.a1 = 0;
	env->map.b1 = 0;
	env->map.a2 = 0;
	env->map.b2 = 0;
	env->map.x = 0;
	env->map.y = 0;
	env->map.dx = 0;
	env->map.dy = 0;
	env->map.xinc = 0;
	env->map.yinc = 0;
	env->map.tabint = NULL;
	env->map.len_x = 0;
	env->map.len_y = 0;
	env->map.pos_x = 0;
	env->map.pos_y = 0;
	env->map.degres_x = 0;
	env->map.degres_y = 0;
	env->map.color = 0;
	env->map.space = 10;
	env->fd = 0;
	env->neg = 0;
	ft_init_struct2(env);
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
	{
		ft_putstr("nombre de parametre incorrecte");
		exit(0);
	}
	ft_init_struct(&env);
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, env.size_win_x,
			env.size_win_y, "Projet : FDF");
	ft_parcetab_int(&env, av[1]);
	mlx_key_hook(env.win_ptr, deal_key, (void *)&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
