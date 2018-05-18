/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:27:50 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/18 21:00:00 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trace_rotation_map(unsigned int *image, t_window *win)
{
	int	x3;
	int	y3;


	printf("pos_x = %d\n", win->trace->x1_base);
	printf("pos_y = %d\n", win->trace->y1_base);
	win->trace->x1 = win->trace->x1_base;
	win->trace->y1 = win->trace->y1_base;
	win->trace->x2 = win->trace->x1 + win->trace->space - win->trace->x1_base;
	win->trace->y2 = win->trace->y1 - win->trace->y1_base;
	x3 = win->trace->x2 + win->trace->space;
	y3 = win->trace->y2;
	win->trace->temp_x2 = win->trace->x2;
	//win->trace->x2 = win->trace->x1 + win->trace->space;
	//win->trace->y2 = win->trace->y1;
	printf("X1 = %d\n", win->trace->x1);
	printf("Y1 = %d\n", win->trace->y1);
	printf("X2 = %d\n", win->trace->x2);
	printf("Y2 = %d\n", win->trace->y2);
	//win->trace->x2 = 600;
	//win->trace->y2 = 410;
	//win->trace->x1 = win->trace->x1 * cos(90) - win->trace->y1 * sin(90);
	//win->trace->y1 = win->trace->temp_x1 * sin(90) + win->trace->y1 * cos(90);
	win->trace->x2 = (win->trace->x2 * cos(1.57079632679)) + (win->trace->y2 * sin(1.57079632679)) + win->trace->x1_base;
	win->trace->y2 = (-win->trace->temp_x2 * sin(1.57079632679)) + (win->trace->y2 * cos(1.57079632679)) + win->trace->y1_base;
	//win->trace->x2 -= 400;
	//win->trace->y2 -= 600;
	/*win->trace->x1 += 600;
	win->trace->x1 += 600;
	win->trace->y1 += 400;
	win->trace->x2 += 600;
	win->trace->y2 += 400;*/
	printf("%s\n", "-----------------------------------------------");
	printf("X2 = %d\n", win->trace->x2);
	printf("Y2 = %d\n", win->trace->y2);
	ft_setsegment_rotate(image, win);
	win->trace->x1 = win->trace->x2;
	win->trace->y1 = win->trace->y2;
	win->trace->x2 = x3;
	win->trace->y2 = y3;
	win->trace->temp_x2 = win->trace->x2;
	win->trace->x2 = (win->trace->x2 * cos(1.57079632679)) + (win->trace->y2 * sin(1.57079632679)) + win->trace->x1_base;
	win->trace->y2 = (-win->trace->temp_x2 * sin(1.57079632679)) + (win->trace->y2 * cos(1.57079632679)) + win->trace->y1_base;
	ft_setsegment_rotate(image, win);
	/*while (win->trace->pos_y <= win->map->len_y)
	{
		while (win->trace->pos_x < win->map->len_x)
		{
			win->trace->x2 = win->trace->x1 + win->trace->space;
			win->trace->y2 = win->trace->y1;
			win->trace->temp_x1 = win->trace->x2;
			win->trace->temp_y1 = win->trace->y2;
			win->trace->x1 = win->trace->x1 * cos(90) - win->trace->y1 * sin(90);
			win->trace->y1 = win->trace->x1 * sin(90) + win->trace->y1 * cos(90);
			ft_setsegment_rotate(image, win);
			win->trace->x1 = win->trace->temp_x1;
			win->trace->y1 = win->trace->temp_y1;
			win->trace->pos_x++;
		}
		win->trace->pos_x = 0;
		win->trace->x1 = win->trace->x1_base;
		win->trace->y1 = win->trace->y1 + win->trace->space;
		win->trace->pos_y++;
	}
	win->trace->pos_y = 0;
	win->trace->y1 = win->trace->y1_base;
	while (win->trace->pos_x <= win->map->len_x)
	{
		while (win->trace->pos_y < win->map->len_y)
		{
			win->trace->x2 = win->trace->x1;
			win->trace->y2 = win->trace->y1 + win->trace->space;
			win->trace->temp_x1 = win->trace->x2;
			win->trace->temp_y1 = win->trace->y2;
			win->trace->x1 = win->trace->x1 * cos(90) - win->trace->y1 * sin(90);
			win->trace->y1 = win->trace->x1 * sin(90) + win->trace->y1 * cos(90);
			ft_setsegment_rotate(image, win);
			win->trace->x1 = win->trace->temp_x1;
			win->trace->y1 = win->trace->temp_y1;
			win->trace->pos_y++;
		}
		win->trace->pos_y = 0;
		win->trace->x1 = win->trace->x1 + win->trace->space;
		win->trace->y1 = win->trace->y1_base;
		win->trace->pos_x++;
	}
	win->trace->pos_x = 0;*/
}

void	ft_trace_map(unsigned int *image, t_window *win)
{
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
		win->trace->x1 = win->trace->x1_base;
		win->trace->y1 = win->trace->y1 + win->trace->space;
		win->trace->pos_y++;
	}
	win->trace->pos_y = 0;
	win->trace->y1 = win->trace->y1_base;
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
		win->trace->y1 = win->trace->y1_base;
		win->trace->pos_x++;
	}
	win->trace->pos_x = 0;
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
	trace->x1_base = 600;
	trace->y1_base = 400;
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
