/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 23:43:45 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/23 13:17:10 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_createtab(t_map *map, char **tab)
{
	int		i;
	int		j;
	int		k;
	int		res;

	i = 0;
	j = 0;
	k = 0;
	res = 0;
	map->tabint = ft_memalloc(sizeof(int *) * (map->len_x + 1));
	while (i < map->len_x)
	{
		map->tabint[i] = ft_memalloc(sizeof(int) * (map->len_y + 1));
		i++;
	}
	i = 0;
	while (tab[i])
	{
		res = 0;
		while (tab[i][k] && tab[i][k] == ' ')
			k++;
		while (tab[i][k] && ft_isdigit(tab[i][k]))
			res = (res * 10) + (tab[i][k++] - '0');
		map->tabint[i][j++] = res;
		if (tab[i][k] == '\0')
		{
			k = 0;
			j = 0;
			i++;
		}
	}
	map->len_x -= 1;
	map->len_y -= 1;
}

void	ft_stocktab(t_map *map, char *str)
{
	int	i;
	int	j;
	char	tmp[4096];
	char	*line;
	char	**tab;


	map->fd = open(str, O_RDONLY);
	i = 0;
	j = 0;
	while (get_next_line(map->fd, &line) == 1)
	{
		map->len_x = 0;
		while (line[j] != '\0')
		{
			if (line[j] && line[j] != ' ')
			{
				map->len_x++;
				while (line[j] && line[j] != ' ')
				{
					tmp[i++] = line[j];
					j++;
				}
			}
			else
				tmp[i++] = line[j++];
		}
		j = 0;
		map->len_y++;
		tmp[i++] = '\n';
	}
	tmp[i] = '\0';
	tab = ft_strsplit(tmp, '\n');
	ft_createtab(map, tab);
}
