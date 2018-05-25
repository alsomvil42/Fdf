/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:31:58 by alsomvil          #+#    #+#             */
/*   Updated: 2018/05/25 15:27:20 by alsomvil         ###   ########.fr       */
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
	int	**tabint;
	int	len_x;
	int	len_y;
	int	pos_x;
	int	pos_y;
	int	degres_x;
	int	degres_y;
	int	a1;
	int	b1;
	int	a2;
	int	b2;
	int	space;
	unsigned int	color;
}								t_map;

typedef struct					s_env
{
	unsigned int	*str;
	int	fd;
	int size_image_x;
	int size_image_y;
	int size_win_x;
	int size_win_y;
	void *mlx_ptr;
	void *win_ptr;
	void *mlx_image;
	int bpb;
	int s_line;
	int endian;
	t_map map;
}								t_env;

//void	ft_setsegment(unsigned int *str, t_window *win);
//void	ft_trace_map(unsigned int *image, t_window *win);
int		deal_key(int key, void *param);
void	ft_parcetab_int(t_env *env, char *str);
void	ft_rotate(t_env *env, int key);
void	ft_bresenham(t_env *env);
//void	ft_setsegment_rotate(unsigned int *str, t_window *win);

#endif
