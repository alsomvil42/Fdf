/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:38:37 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/14 18:44:03 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pasdplace(int *k, int *j, int *i)
{
	*k = 0;
	*j = 0;
	*i = *i + 1;
}

void	ft_fill_tab(t_env *env, char **tab)
{
	int		i;
	int		j;
	int		k;
	int		res;

	i = 0;
	j = 0;
	k = 0;
	while (tab[i])
	{
		res = 0;
		while (tab[i][k] && tab[i][k] == ' ')
			k++;
		if (tab[i][k] == '-' && ft_isdigit(tab[i][k + 1]) && tab[i][k++])
			env->neg = 1;
		while (tab[i][k] && ft_isdigit(tab[i][k]))
			res = (res * 10) + (tab[i][k++] - '0');
		if (env->neg == 1)
			res = -res;
		env->map.tabint[i][j++] = res;
		env->neg = 0;
		if (tab[i][k] == '\0')
			ft_pasdplace(&k, &j, &i);
	}
}

void	ft_createtab(t_env *env, char **tab)
{
	int		i;

	i = 0;
	env->map.tabint = ft_memalloc(sizeof(int *) * (env->map.len_y + 1));
	while (i < env->map.len_y)
		env->map.tabint[i++] = ft_memalloc(sizeof(int) * (env->map.len_x + 1));
	ft_fill_tab(env, tab);
}
