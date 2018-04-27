/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:27:50 by alsomvil          #+#    #+#             */
/*   Updated: 2018/04/27 02:10:58 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
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
	while (y < 270)
	{
		x = 0;
		while (x < 2000)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x++;
		}
		y++;
	}
	mlx_string_put(mlx_ptr, win_ptr, 950, 120, 0xFFFFFF, "Projet : Fdf");
	y = 1260;
	while (y < 1300)
	{
		x = 0;
		while (x < 2000)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x++;
		}
		y++;
	}
	mlx_string_put(mlx_ptr, win_ptr, 1870, 1270, 0xFFFFFF, "SOMVILLE A.");
	//ft_setlegend(mlx_ptr, win_ptr);
}

int	deal_key(int key, void *param)
{
	t_window	*test;
	int			color;

	color = 0x071bFF;
	test = (t_window *)param;
	if (key == 37)
		ft_setwindows(test->mlx_ptr, test->win_ptr, color);
	if (key == 53)
		exit(1);
	ft_setlegend(test->mlx_ptr, test->win_ptr);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mlx_image;
	char	*str;
	unsigned int	color;
	unsigned int	*essai;
	int		test;
	int		bpb;
	int		s_line;
	int		endian;
	t_window	window;
	//color = 0X071BFF;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 1300, "hello");
	window.mlx_ptr = mlx_ptr;
	window.win_ptr = win_ptr;
	mlx_image = mlx_new_image(mlx_ptr, 300, 500);
	str = mlx_get_data_addr(mlx_image, &bpb, &s_line, &endian);
	color = mlx_get_color_value(mlx_ptr, 0x0FFF30);
	essai = (unsigned int *)str;
	essai[700] = color;
	essai[24] = color;
	essai[25] = color;
	essai[26] = color;
	essai[27] = color;
	essai[28] = color;
	//ft_setwindows(mlx_image, win_ptr, color);
	mlx_put_image_to_window(mlx_ptr, win_ptr, mlx_image, 0, 0);
	//ft_setwindows(mlx_ptr, win_ptr, color);
	//mlx_key_hook(win_ptr, deal_key, (void *)&window);
	mlx_loop(mlx_ptr);
	return (0);
}
