/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 23:43:45 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/17 23:45:51 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_createtab(t_map *map, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	map->tabint = ft_memalloc(sizeof(int *) * (map->len_x + 1));
	while (i < map->len_x)
	{
		map->tabint[i] = ft_memalloc(sizeof(int) * (map->len_y + 1));
		i++;
	}
	i = 0;
	while (tab[i])
	{
		while (tab[i][j] && tab[i][j] >= '0' && tab[i][j] <= '9')
		{
			map->tabint[i][k] = (tab[i][j] - 48);
			k++;
			j++;
			while (tab[i][j] && tab[i][j] == ' ')
				j++;
		}
		k = 0;
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (i < map->len_y)
	{
		while (j < map->len_x)
		{
			printf("%d ", map->tabint[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	printf("%s\n", "OK");
}

void	ft_stocktab(t_map *map, char *str)
{
	int	i;
	char	tmp[4096];
	char	*line;
	char	**tab;


	map->fd = open(str, O_RDONLY);
	i = 0;
	while (get_next_line(map->fd, &line) == 1)
	{
		map->len_x = 0;
		while (*line != '\0')
		{
			if (*line != ' ')
				map->len_x++;
			tmp[i++] = *line++;
		}
		map->len_y++;
		tmp[i++] = '\n';
	}
	tmp[i] = '\0';
	tab = ft_strsplit(tmp, '\n');
}
