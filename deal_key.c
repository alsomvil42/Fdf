/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 23:36:59 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/25 15:35:56 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	printf("%d\n", key);
	if (key == 86 || key == 84 || key == 88 || key == 91)
	{
		ft_rotate(env, key);
		printf("%s\n", "OK");
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_image, 0, 0);
	}
	if (key == 53)
		exit(1);
	return (0);
}

