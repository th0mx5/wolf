/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:11:44 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/23 12:20:25 by maxisimo         ###   ########.fr       */
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

typedef struct	s_app
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*fname;
	char		*img_data;
	t_coord_d	pos;
	int			fov;
	int			player_size;
	t_coord		mouse;
	t_coord		map_size;
	int			**map;
	//-------------------------
	int			color;
	int			start;
	int			end;
	int			lineheight;
	int			stepX;
	int			stepY;
	int			mapX;
	int			mapY;
	int			side;
	int			hit;
	int			mv_up;
	int			mv_down;
	int			mv_left;
	int			mv_right;
	int			rt_right;
	int			rt_left;
	int			px;
	int			blocs;
	int			psy;
	int			speed;
	double		ms;
	double		oldDirX;
	double		deltaDistX;
	double		deltaDistY;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		rayPosX;
	double		rayPosY;
	double		camX;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		dist_wall;
	double		oldPlaneX;
}				t_app;

int				ft_close(t_app *app);
int				ft_key_press(int key, t_app *app);
int				ft_key_release(int key, t_app *app);
int				ft_move(t_app *a);

void			draw_minimap(t_app *a);
void			put_pxl_to_img(t_app *a, int x, int y, int color);

void			raycasting(t_app *app);

void			ft_app_init(t_app *app);
void			ft_app_countmap(t_app *app);
void			ft_app_allocmap(t_app *app);
void			ft_app_writemap(t_app *app);
void			ft_app_calcplayerpos(t_app *app);
void			ft_app_printmap(t_app *app);

void			ft_printcontrols(void);
void			ft_error(char *s);
void			ft_pickcolors(t_app *app, int *color, int i);

double			ft_abs_d(double nb);
int				ft_abs(int nb);
void			ft_free_strsplit(char **array);

int				ft_is_againstwall(t_app *app);

#endif
