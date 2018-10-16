/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:11:44 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/12 21:24:12 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

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
	t_coord		winsize;
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
}				t_app;

int				ft_keyhooked(int keycode, t_app *app);
int				ft_zoom(int keycode, t_app *app, int x, int y);
int				ft_mousehooked(int button, int x, int y, t_app *app);
int				ft_hook(int x, int y, t_app *app);

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

#endif
