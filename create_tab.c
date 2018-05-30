/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:27:28 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/30 16:27:58 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		while (tab[i][k] && ft_isdigit(tab[i][k]))
			res = (res * 10) + (tab[i][k++] - '0');
		env->map.tabint[i][j++] = res;
		if (tab[i][k] == '\0')
		{
			k = 0;
			j = 0;
			i++;
		}
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

void	ft_parcetab_int(t_env *env, char *str)
{
	int		i;
	int		j;
	char	tmp[4096];
	char	*line;
	char	**tab;

	env->fd = open(str, O_RDONLY);
	i = 0;
	env->map.len_x = 0;
	while (get_next_line(env->fd, &line) == 1)
	{
		env->map.len_x = 0;
		j = 0;
		while (line[j] != '\0')
			if (line[j] && line[j] != ' ' && env->map.len_x++)
				while (line[j] && line[j] != ' ')
					tmp[i++] = line[j++];
			else
				tmp[i++] = line[j++];
		env->map.len_y++;
		tmp[i++] = '\n';
	}
	tmp[i] = '\0';
	tab = ft_strsplit(tmp, '\n');
	ft_createtab(env, tab);
}
