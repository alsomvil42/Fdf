/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:31:58 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/19 11:32:26 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "get_next_line.h"
#include "stdio.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include "minilibx/mlx.h"

typedef struct					s_map
{
	int	len_y;
	int	len_x;
	int	fd;
	int	**tabint;
	unsigned int	color_map;
}						t_map;

typedef struct					s_trace
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int temp_x1;
	int temp_x2;
	int	space;
	int	pos_x;
	int	pos_y;
	int	x1_base;
	int	y1_base;
	int	degres;
}						t_trace;

typedef struct					s_window
{
	void *mlx_ptr;
	void *win_ptr;
	void *mlx_map_base;
	void *mlx_legend;
	void *mlx_image;
	int size_image_x;
	int size_image_y;
	int bpb;
	int s_line;
	int endian;
	t_map *map;
	t_trace *trace;
}						t_window;

void	ft_setsegment(unsigned int *str, t_window *win);
void	ft_trace_map(unsigned int *image, t_window *win);
int		deal_key(int key, void *param);
void	ft_stocktab(t_map *map, char *str);
void	ft_trace_rotation_map(unsigned int *image, t_window *win);
void	ft_setsegment_rotate(unsigned int *str, t_window *win);

#endif
