/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:27:50 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/11 18:59:41 by alsomvil         ###   ########.fr       */
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

int	deal_key(int key, void *param)
{
	t_window	*test;
	int			color;

	color = 0x071bFF;
	test = (t_window *)param;
	printf("%d\n", key);
	if (key == 99)
	{
		mlx_put_image_to_window(test->mlx_ptr, test->win_ptr, test->mlx_map_base, 600, 250);
		//ft_setwindows(test->mlx_ptr, test->win_ptr, color);
		mlx_destroy_image(test->mlx_ptr, test->mlx_map_base);
	}
	if (key == 65307)
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

void	ft_setsegment(unsigned int *str, t_map *map, t_trace *trace)
{
	int dx;
	int x1;
	int y1;
	int x2;
	int y2;
	int dy;
	int e;
	int		i;

	i = 0;
	x1 = trace->x1;
	y1 = trace->y1;
	x2 = trace->x2;
	y2 = trace->y2;
	if ((dx = x2 - x1) != 0)
	{
		if (dx > 0)
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = 0;
						dx = (e = dx) * 2;
						dy = dy * 2;
						while (1)
						{
							i = (700 * y1) + x1;
							str[i] = map->color_map;
							if ((x1 = x1 + 1) == x2)
								break ;
							if ((e = e - dy) < 0)
							{
								y1 = y1 + 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = 0;
						dy = (e = dy) * 2;
						dx = dx * 2;
						while (1)
						{
							i = (700 * y1) + x1;
							str[i] = map->color_map;
							if ((y1 = y1 + 1) == y2)
								break ;
							if ((e = e - dx) < 0)
							{
								x1 = x1 + 1;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						e = 0;
						dx = (e = dx) * 2;
						dy = dy * 2;
						while (1)
						{
							i = (700 * y1) + x1;
							str[i] = map->color_map;
							if ((x1 = x1 + 1) == x2)
								break ;
							if ((e = e - dy) < 0)
							{
								y1 = y1 - 1;
								e = e + dx;
							}
						}
						
					}
					else
					{
						e = 0;
						dy = (e = dy) * 2;
						dx = dx * 2;
						while (1)
						{
							i = (700 * y1) + x1;
							str[i] = map->color_map;
							if ((y1 = y1 - 1) == y2)
								break ;
							if ((e = e + dx) > 0)
							{
								x1 = x1 + 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while (x1 != x2)
				{
					i = (700 * y1) + x1;
					str[i] = map->color_map;
					x1 = x1 + 1;					
				}
			}
		}
		else
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = 0;
						dx = (e = dx) * 2;
						dy = dy * 2;
						while (1)
						{
							i = (700 * y1) + x1;
							str[i] = map->color_map;
							if ((x1 = x1 - 1) == x2)
								break ;
							if ((e = e + dy) >= 0)
							{
								y1 = y1 + 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = 0;
						dy = (e = dy) * 2;
						dx = dx * 2;
						while (1)
						{
							i = (700 * y1) + x1;
							str[i] = map->color_map;
							if ((y1 = y1 + 1) == y2)
								break ;
							if ((e = e + dx) <= 0)
							{
								x1 = x1 - 1;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = 0;
						dx = (e = dx) * 2;
						dy = dy * 2;
						while (1)
						{
							i = (700 * y1) + x1;
							str[i] = map->color_map;
							if ((x1 = x1 - 1) == x2)
								break ;
							if ((e = e - dy) >= 0)
							{
								y1 = y1 - 1;
								e = e + dx;
							}
						}
						
					}
					else
					{
						e = 0;
						dy = (e = dy) * 2;
						dx = dx * 2;
						while (1)
						{
							i = (700 * y1) + x1;
							str[i] = map->color_map;
							if ((y1 = y1 - 1) == y2)
								break ;
							if ((e = e - dx) >= 0)
							{
								x1 = x1 - 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while (x1 != x2)
				{
					i = (700 * y1) + x1;
					str[i] = map->color_map;
					x1 = x1 - 1;					
				}
			}
		}
	}
	else
	{
		if ((dy = y2 - y1) != 0)
		{
			if (dy > 0)
			{
				while (y1 != y2)
				{
					i = (700 * y1) + x1;
					str[i] = map->color_map;
					y1 = y1 + 1;					
				}
			}
			else
			{
				while (y1 != y2)
				{
					i = (700 * y1) + x1;
					str[i] = map->color_map;
					y1 = y1 - 1;					
				}
			}
		}
	}
	return ;
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
	/*i = 0;
	j = 0;
	while (i < 5)
	{
		while (j < 5)
		{
			printf("%d ", map->tabint[i][j]);
			j++;			
		}
		printf("\n");
		j = 0;
		i++;
	}*/
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
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->mlx_map_base = NULL;
	win->mlx_legend = NULL;
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

void	ft_trace_map(unsigned int *image, t_map *map, t_trace *trace)
{
	while (trace->pos_y <= map->len_y)
	{
		while (trace->pos_x < map->len_x)
		{
			trace->x2 = trace->x1 + trace->space;
			trace->y2 = trace->y1;
			ft_setsegment(image, map, trace);
			trace->x1 = trace->x2;
			trace->y1 = trace->y2;
			trace->pos_x++;
		}
		trace->pos_x = 0;
		trace->x1 = 0;
		trace->y1 = trace->y1 + trace->space;
		trace->pos_y++;
	}
	trace->pos_y = 0;
	trace->y1 = 0;
	while (trace->pos_x <= map->len_x)
	{
		while (trace->pos_y < map->len_y)
		{
			trace->x2 = trace->x1;
			trace->y2 = trace->y1 + trace->space;
			ft_setsegment(image, map, trace);
			trace->x1 = trace->x2;
			trace->y1 = trace->y2;
			trace->pos_y++;
		}
		trace->pos_y = 0;
		trace->x1 = trace->x1 + trace->space;
		trace->y1 = 0;
		trace->pos_x++;
	}
}


void	ft_createmap(t_window *win, t_map *map, t_trace *trace)
{
	unsigned int	*image;
	char		*str;
	unsigned int	color;
	int		bpb;
	int		s_line;
	int		endian;

	map->color_map = mlx_get_color_value(win->mlx_ptr, 0x0FFF30);
	win->mlx_map_base = mlx_new_image(win->mlx_ptr, 700, 200);
	str = mlx_get_data_addr(win->mlx_map_base, &bpb, &s_line, &endian);
	image = (unsigned int *)str;
	ft_trace_map(image, map, trace);
	//mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->mlx_map_base, 600, 250);
}

int	main(int ac, char **av)
{
	t_window	win;
	t_map		map;
	t_trace		trace;

	ft_set_struct(&win, &map, &trace);
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, 1250, 600, "hello");
	if (ac != 2)
	{
		ft_putstr("nombre de parametre incorrecte");
		return (0);
	}
	ft_stocktab(&map, av[1]);
	ft_createmap(&win, &map, &trace);
	mlx_key_hook(win.win_ptr, deal_key, (void *)&win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
