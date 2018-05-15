/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:31:58 by alsomvil          #+#    #+#             */
/*   Updated: 2018/04/26 04:19:18 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stdio.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct					s_window
{
	void *mlx_ptr;
	void *win_ptr;
	void *mlx_map_base;
	void *mlx_legend;
	void *mlx_image;
}						t_window;

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
	int	space;
	int	pos_x;
	int	pos_y;
}						t_trace;
