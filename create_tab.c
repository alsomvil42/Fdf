/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:27:28 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/01 13:10:14 by alsomvil         ###   ########.fr       */
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
		if (tab[i][k] && tab[i][k] == '-' && ft_isdigit(tab[i][k + 1]))
		{
			k++;
			env->neg = 1;
		}
		while (tab[i][k] && ft_isdigit(tab[i][k]))
			res = (res * 10) + (tab[i][k++] - '0');
		if (env->neg == 1)
			res = -res;
		env->map.tabint[i][j++] = res;
		env->neg = 0;
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

char	*ft_checksize(int fd)
{
	int		i;
	int		j;
	char	*tab;
	char	*line;

	i = 0;
	j = 0;
	tab = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		while (line[j])
		{
			j++;
			i++;
		}
	}
	tab = (char *)malloc(sizeof(char) * i);
	return (tab);
}

int		ft_checktab(char *tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] != ' ' && tab[i] != '-' && tab[i] != '\n' && !ft_isdigit(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_parcetab_int(t_env *env, char *str)
{
	int		i;
	int		j;
	char	*tmp;
	char	*line;
	char	**tab;

	if ((env->fd = open(str, O_RDONLY)) < 0)
	{
		ft_putstr("argument incorrect");
		exit(0);
	}
	tmp = ft_checksize(env->fd);
	close(env->fd);
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
	if (ft_checktab(tmp) == 0)
	{
		ft_putstr("Le fichier n'est pas une map");
		exit(0);
	}
	tab = ft_strsplit(tmp, '\n');
	ft_createtab(env, tab);
}
