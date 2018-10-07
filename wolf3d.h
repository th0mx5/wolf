/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:11:44 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/07 15:13:57 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

# define WIN_W 1280
# define WIN_H 720
# define FOV 60
# define PI 3.14159265359

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_coord_d
{
	double		x;
	double		y;
}				t_coord_d;

typedef struct	s_var
{
	int			x;
	int			y;
	int			**pix;
	char		*buf;
	double		p_x;
	double		p_y;
	int			wth;
	int			Xa;
	int			Ya;
	int			Ax;
	int			Ay;
	double		posx;
	double		posy;
	double		angle_ray;
	double		alpha;
	double		dist;
	int			min;
	double		s_dist;
	int			max;
	void		*mlx;
	void		*win;
	void		*img;
	char		*fname;
	t_coord		winsize;
	char		*img_data;
	t_coord		pos;
	t_coord		mouse;
	t_coord		map_size;
	int			***map;
}				t_var;

int				ft_keyhooked(int keycode, t_var *v);
int				ft_zoom(int keycode, t_var *v, int x, int y);
int				ft_mousehooked(int button, int x, int y, t_var *v);
int				ft_hook(int x, int y, t_var *v);

void			ft_win_draw(t_var *v);
void			ft_img_putpixel(t_var *v, int color);
void			ft_calc_color(t_var *v, t_coord p);

void			raycasting(t_var *v);

int				start(t_var *v);

void			ft_printcontrols(void);
void			ft_error(char *s);
void			ft_pickcolors(t_var *v, int *color, int i);

double			ft_abs_d(double nb);
int				ft_abs(int nb);
void			ft_free_strsplit(char **array);

#endif
