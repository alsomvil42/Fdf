/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:31:58 by alsomvil          #+#    #+#             */
/*   Updated: 2018/07/03 01:22:19 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "unistd.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct			s_map
{
	int				**tabint;
	int				len_x;
	int				len_y;
	int				pos_x;
	int				pos_y;
	int				degres_x;
	int				degres_y;
	int				a1;
	int				b1;
	int				a2;
	int				b2;
	int				x;
	int				z1temp;;
	int				y;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				space;
	unsigned int	color;
}						t_map;

typedef struct			s_env
{
	unsigned int	*str;
	int				fd;
	int				neg;
	int				mouve;
	int				mouve_vert;
	int				size_image_x;
	int				size_image_y;
	int				size_win_x;
	int				size_win_y;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_image;
	int				bpb;
	int				s_line;
	int				endian;
	int				temp;
	t_map			map;
}						t_env;

int						deal_key(int key, void *param);
void					ft_createtab(t_env *env, char **tab);
void					ft_parcetab_int(t_env *env, char *str);
void					ft_rotate(t_env *env, int key);
void					ft_bresenham(t_env *env);
void					ft_pasdeplace(t_env *env, int key);

#endif
