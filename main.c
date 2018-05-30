/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:27:50 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/30 16:28:30 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_struct(t_env *env)
{
	env->map.tabint = NULL;
	env->map.len_x = 0;
	env->map.len_y = 0;
	env->map.pos_x = 0;
	env->map.pos_y = 0;
	env->map.degres_x = 0;
	env->map.degres_y = 0;
	env->map.color = 0;
	env->map.space = 40;
	env->fd = 0;
	env->size_image_x = 800;
	env->size_image_y = 500;
	env->size_win_x = 800;
	env->size_win_y = 500;
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	env->bpb = 0;
	env->s_line = 0;
	env->endian = 0;
}

int		main(int ac, char **av)
{
	t_env	env;

	ft_init_struct(&env);
	env.mlx_ptr = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx_ptr, env.size_win_x,
			env.size_win_y, "On est les boss");
	if (ac != 2)
	{
		ft_putstr("nombre de parametre incorrecte");
		return (0);
	}
	ft_parcetab_int(&env, av[1]);
	mlx_key_hook(env.win_ptr, deal_key, (void *)&env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
