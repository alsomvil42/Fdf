/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 23:36:59 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/18 02:41:25 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, void *param)
{
	t_window	*test;
	int			color;
	unsigned int	*image;
	char		*str;

	color = 0x071bFF;
	test = (t_window *)param;
	printf("%d\n", key);
	if (key == 2) //touche D
	{
		test->trace->x1 = test->trace->x1_base;
		test->trace->y1 = test->trace->y1_base;
		test->trace->pos_x = 0;
		test->trace->pos_y = 0;
		test->mlx_map_base = mlx_new_image(test->mlx_ptr, 1500, 900);
		str = mlx_get_data_addr(test->mlx_map_base, &test->bpb, &test->s_line, &test->endian);
		image = (unsigned int *)str;
		ft_trace_map(image, test);
		mlx_put_image_to_window(test->mlx_ptr, test->win_ptr, test->mlx_map_base, 0, 0);
		mlx_destroy_image(test->mlx_ptr, test->mlx_map_base);
	}
	if (key == 69) // ZOOM
	{
		test->trace->x1_base = test->trace->x1_base - 15;
		test->trace->y1_base = test->trace->y1_base - 15;
		test->trace->space = test->trace->space + 10;
		test->trace->x1 = test->trace->x1_base;
		test->trace->y1 = test->trace->y1_base;
		test->trace->pos_x = 0;
		test->trace->pos_y = 0;
		test->mlx_map_base = mlx_new_image(test->mlx_ptr, 1500, 900);
		str = mlx_get_data_addr(test->mlx_map_base, &test->bpb, &test->s_line, &test->endian);
		image = (unsigned int *)str;
		ft_trace_map(image, test);
		mlx_put_image_to_window(test->mlx_ptr, test->win_ptr, test->mlx_map_base, 0, 0);
		mlx_destroy_image(test->mlx_ptr, test->mlx_map_base);
	}
	if (key == 78 && test->trace->space >= 10) // DEZOOM
	{
		test->trace->x1_base = test->trace->x1_base + 15;
		test->trace->y1_base = test->trace->y1_base + 15;
		test->trace->space = test->trace->space - 10;
		test->trace->x1 = test->trace->x1_base;
		test->trace->y1 = test->trace->y1_base;
		test->trace->pos_x = 0;
		test->trace->pos_y = 0;
		test->mlx_map_base = mlx_new_image(test->mlx_ptr, 1500, 900);
		str = mlx_get_data_addr(test->mlx_map_base, &test->bpb, &test->s_line, &test->endian);
		image = (unsigned int *)str;
		ft_trace_map(image, test);
		mlx_put_image_to_window(test->mlx_ptr, test->win_ptr, test->mlx_map_base, 0, 0);
		mlx_destroy_image(test->mlx_ptr, test->mlx_map_base);
	}
	if (key == 124)
	{
		test->trace->x1_base = test->trace->x1_base + 10;
		test->trace->x1 = test->trace->x1_base;
		test->trace->y1 = test->trace->y1_base;
		test->trace->pos_x = 0;
		test->trace->pos_y = 0;
		test->mlx_map_base = mlx_new_image(test->mlx_ptr, 1500, 900);
		str = mlx_get_data_addr(test->mlx_map_base, &test->bpb, &test->s_line, &test->endian);
		image = (unsigned int *)str;
		ft_trace_map(image, test);
		mlx_put_image_to_window(test->mlx_ptr, test->win_ptr, test->mlx_map_base, 0, 0);
		mlx_destroy_image(test->mlx_ptr, test->mlx_map_base);
	}
	if (key == 123)
	{
		test->trace->x1_base = test->trace->x1_base - 10;
		test->trace->x1 = test->trace->x1_base;
		test->trace->y1 = test->trace->y1_base;
		test->trace->pos_x = 0;
		test->trace->pos_y = 0;
		test->mlx_map_base = mlx_new_image(test->mlx_ptr, 1500, 900);
		str = mlx_get_data_addr(test->mlx_map_base, &test->bpb, &test->s_line, &test->endian);
		image = (unsigned int *)str;
		ft_trace_map(image, test);
		mlx_put_image_to_window(test->mlx_ptr, test->win_ptr, test->mlx_map_base, 0, 0);
		mlx_destroy_image(test->mlx_ptr, test->mlx_map_base);
	}
	if (key == 125)
	{
		test->trace->y1_base = test->trace->y1_base + 10;
		test->trace->x1 = test->trace->x1_base;
		test->trace->y1 = test->trace->y1_base;
		test->trace->pos_x = 0;
		test->trace->pos_y = 0;
		test->mlx_map_base = mlx_new_image(test->mlx_ptr, 1500, 900);
		str = mlx_get_data_addr(test->mlx_map_base, &test->bpb, &test->s_line, &test->endian);
		image = (unsigned int *)str;
		ft_trace_map(image, test);
		mlx_put_image_to_window(test->mlx_ptr, test->win_ptr, test->mlx_map_base, 0, 0);
		mlx_destroy_image(test->mlx_ptr, test->mlx_map_base);
	}
	if (key == 126)
	{
		test->trace->y1_base = test->trace->y1_base - 10;
		test->trace->x1 = test->trace->x1_base;
		test->trace->y1 = test->trace->y1_base;
		test->trace->pos_x = 0;
		test->trace->pos_y = 0;
		test->mlx_map_base = mlx_new_image(test->mlx_ptr, 1500, 900);
		str = mlx_get_data_addr(test->mlx_map_base, &test->bpb, &test->s_line, &test->endian);
		image = (unsigned int *)str;
		ft_trace_map(image, test);
		mlx_put_image_to_window(test->mlx_ptr, test->win_ptr, test->mlx_map_base, 0, 0);
		mlx_destroy_image(test->mlx_ptr, test->mlx_map_base);
	}
	if (key == 15)
	{
		test->trace->x1 = test->trace->x1_base;
		test->trace->y1 = test->trace->y1_base;
		test->trace->pos_x = 0;
		test->trace->pos_y = 0;
		test->mlx_map_base = mlx_new_image(test->mlx_ptr, 1500, 900);
		str = mlx_get_data_addr(test->mlx_map_base, &test->bpb, &test->s_line, &test->endian);
		image = (unsigned int *)str;
		printf("%s\n", "TEST");
		ft_trace_rotation_map(image, test);
		printf("%s\n", "TEST3");
		mlx_put_image_to_window(test->mlx_ptr, test->win_ptr, test->mlx_map_base, 0, 0);
		mlx_destroy_image(test->mlx_ptr, test->mlx_map_base);
	}
	if (key == 53)
		exit(1);
	return (0);
}

