/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:27:50 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/16 14:20:21 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>

void	ft_setlegend(void *mlx_ptr, void *win_ptr)
{
	int		x;
	int		y;

	x = 70;
	y = 600;
	while (x < 300)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		x++;
	}
	while (y < 900)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		y++;
	}
	while (x > 70)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		x--;
	}
	while (y > 600)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
		y--;
	}
}

void	ft_setwindows(void *mlx_ptr, void *win_ptr, int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < 100)
	{
		x = 0;
		while (x < 1250)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x++;
		}
		y++;
	}
	mlx_string_put(mlx_ptr, win_ptr, 625, 50, 0xFFFFFF, "Projet : Fdf");
	y = 540;
	while (y < 600)
	{
		x = 0;
		while (x < 1250)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x++;
		}
		y++;
	}
	mlx_string_put(mlx_ptr, win_ptr, 1870, 1270, 0xFFFFFF, "SOMVILLE A.");
}

void	ft_create_map2(t_window *win)
{
	unsigned int	*image;
	char		*str;
	int		bpb;
	int		s_line;
	int		endian;

	win->mlx_map_base = mlx_new_image(win->mlx_ptr, 700, 200);
	str = mlx_get_data_addr(win->mlx_map_base, &bpb, &s_line, &endian);
	image = (unsigned int *)str;
	//ft_trace_map(image, map, trace);
	//mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->mlx_map_base, 600, 250);
}

void	ft_trace_map(unsigned int *image, t_window *win)
{
			/*printf("%d\n", win->trace->x1);
			printf("%d\n", win->trace->x2);
			printf("%d\n", win->trace->y1);
			printf("%d\n", win->trace->y2);*/
	while (win->trace->pos_y <= win->map->len_y)
	{
		while (win->trace->pos_x < win->map->len_x)
		{
			win->trace->x2 = win->trace->x1 + win->trace->space;
			win->trace->y2 = win->trace->y1;
			ft_setsegment(image, win);
			win->trace->x1 = win->trace->x2;
			win->trace->y1 = win->trace->y2;
			win->trace->pos_x++;
		}
		win->trace->pos_x = 0;
		win->trace->x1 = 0;
		win->trace->y1 = win->trace->y1 + win->trace->space;
		win->trace->pos_y++;
	}
	win->trace->pos_y = 0;
	win->trace->y1 = 0;
	while (win->trace->pos_x <= win->map->len_x)
	{
		while (win->trace->pos_y < win->map->len_y)
		{
			win->trace->x2 = win->trace->x1;
			win->trace->y2 = win->trace->y1 + win->trace->space;
			ft_setsegment(image, win);
			win->trace->x1 = win->trace->x2;
			win->trace->y1 = win->trace->y2;
			win->trace->pos_y++;
		}
		win->trace->pos_y = 0;
		win->trace->x1 = win->trace->x1 + win->trace->space;
		win->trace->y1 = 0;
		win->trace->pos_x++;
	}
}

int	deal_key(int key, void *param)
{
	t_window	*test;
	int			color;
	unsigned int	*image;
	char		*str;

	color = 0x071bFF;
	test = (t_window *)param;
	printf("%d\n", key);
	if (key == 2)
	{
		mlx_put_image_to_window(test->mlx_ptr, test->win_ptr, test->mlx_map_base, 0, 0);
		//ft_setwindows(test->mlx_ptr, test->win_ptr, color);
		mlx_destroy_image(test->mlx_ptr, test->mlx_map_base);
	}
	if (key == 69)
	{
		/*test->mlx_map_base = mlx_new_image(test->mlx_ptr, 1500, 900);
		str = mlx_get_data_addr(test->mlx_map_base, &test->bpb, &test->s_line, &test->endian);
		image = (unsigned int *)str;
		ft_trace_map(image, &test->map, &test->trace);
		mlx_put_image_to_window(test->mlx_ptr, test->win_ptr, test->mlx_map_base, (test->size_image_x + 20), test->size_image_y);
		mlx_destroy_image(test->mlx_ptr, test->mlx_map_base);*/
	}
	if (key == 53)
		exit(1);
	if (key == 114)
	{
		ft_create_map2(test);
		mlx_put_image_to_window(test->mlx_ptr, test->win_ptr, test->mlx_map_base, 600, 250);
		mlx_destroy_image(test->mlx_ptr, test->mlx_map_base);
	}
	if (key == 108)
		ft_setlegend(test->mlx_ptr, test->win_ptr);
	return (0);
}

void	ft_createtab(t_map *map, char **tab)
{
	int	i;
	int	j;
	int	k;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	map->tabint = malloc(sizeof(int *) * (map->len_x + 1));
	while (i < map->len_y)
	{
		map->tabint[i] = malloc(sizeof(int) * (map->len_y + 1));
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
	ft_createtab(map, tab);
}

void	ft_set_struct(t_window *win, t_map *map, t_trace *trace)
{
	win->map = map;
	win->trace= trace;
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->bpb = 0;
	win->s_line = 0;
	win->endian = 0;
	win->mlx_map_base = NULL;
	win->mlx_legend = NULL;
	win->size_image_x = 600;
	win->size_image_y = 250;
	win->mlx_image = NULL;
	map->len_x = 0;
	map->len_y = 0;
	map->color_map = 0;
	map->fd = 0;
	map->tabint = NULL;
	trace->x1 = 0;
	trace->y1 = 0;
	trace->x2 = 0;
	trace->y2 = 0;
	trace->pos_x = 0;
	trace->pos_y = 0;
	trace->space = 10;
}


void	ft_createmap(t_window *win)
{
	unsigned int	*image;
	char		*str;

	win->map->color_map = mlx_get_color_value(win->mlx_ptr, 0x0FFF30);
	win->mlx_map_base = mlx_new_image(win->mlx_ptr, 1500, 900);
	str = mlx_get_data_addr(win->mlx_map_base, &win->bpb, &win->s_line, &win->endian);
	image = (unsigned int *)str;
	ft_trace_map(image, win);
	//mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->mlx_map_base, 600, 250);
}

int	main(int ac, char **av)
{
	t_window	win;
	t_map		map;
	t_trace		trace;

	ft_set_struct(&win, &map, &trace);
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, 1500, 900, "hello");
	if (ac != 2)
	{
		ft_putstr("nombre de parametre incorrecte");
		return (0);
	}
	ft_stocktab(&map, av[1]);
	ft_createmap(&win);
	mlx_key_hook(win.win_ptr, deal_key, (void *)&win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
