/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:27:28 by alsomvil          #+#    #+#             */
/*   Updated: 2018/06/20 14:28:29 by alsomvil         ###   ########.fr       */
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
		while (line[j])
		{
			j++;
			i++;
		}
		i++;
		j = 0;
		free(line);
	}
	tab = (char *)malloc(sizeof(char) * (i + 1));
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

char	*ft_fill_beforechar(t_env *env, char *tmp)
{
	int		j;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	env->map.len_y = 0;
	while (get_next_line(env->fd, &line) == 1)
	{
		env->map.len_x = 0;
		j = 0;
		while (line[j] != '\0')
		{
			if (line[j] && line[j] != ' ' && env->map.len_x++)
				while (line[j] && line[j] != ' ')
					tmp[i++] = line[j++];
			else
				tmp[i++] = line[j++];
		}
		env->map.len_y++;
		tmp[i++] = '\n';
		free(line);
	}
	tmp[--i] = '\0';
	return (tmp);
}

void	ft_parcetab_int(t_env *env, char *str)
{
	int		i;
	char	*beforechar;
	char	**tab;

	i = 0;
	if ((env->fd = open(str, O_RDONLY)) < 0)
		ft_error(0);
	beforechar = ft_checksize(env->fd);
	close(env->fd);
	env->fd = open(str, O_RDONLY);
	beforechar = ft_fill_beforechar(env, beforechar);
	if (ft_checktab(beforechar) == 0)
		ft_error(1);
	tab = ft_strsplit(beforechar, '\n');
	ft_createtab(env, tab);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free(beforechar);
}
