/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pasdeplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 13:58:50 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/21 14:00:12 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_pasdeplace(t_env *env, int key)
{
	if (key == 15)
	{
		env->map.space = 10;
		env->mouve = 0;
		env->mouve_vert = 0;
		env->map.degres_x = 0;
		env->map.degres_y = 0;
	}
}
