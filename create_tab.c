/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:27:28 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/18 12:02:04 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		if (tab[i] != ' ' && tab[i] != '-'
				&& tab[i] != '\n' && !ft_isdigit(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(int error)
{
	if (error == 0)
	{
		ft_putstr("argument incorrect");
		exit(0);
	}
	if (error == 1)
	{
		ft_putstr("Le fichier n'est pas une map");
		exit(0);
	}
}

void	ft_fill_tab_int(t_env *env, char *tmp)
{
	int		j;
	int		i;
	char	*line;

	j = 0;
	i = 0;
	line = NULL;
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
}

void	ft_parcetab_int(t_env *env, char *str)
{
	char	*tmp;
	char	**tab;

	if ((env->fd = open(str, O_RDONLY)) < 0)
		ft_error(0);
	tmp = ft_checksize(env->fd);
	close(env->fd);
	env->fd = open(str, O_RDONLY);
	env->map.len_x = 0;
	ft_fill_tab_int(env, tmp);
	if (ft_checktab(tmp) == 0)
		ft_error(1);
	tab = ft_strsplit(tmp, '\n');
	ft_createtab(env, tab);
}
