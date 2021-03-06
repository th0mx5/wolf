/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:11:44 by thbernar          #+#    #+#             */
/*   Updated: 2018/12/11 13:08:21 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

# define WIN_W 1280
# define WIN_H 720
# define START "PRESS ANY KEY TO START"
# define HFOV_RAD 30 * 2 * M_PI / 360
# define FOV_RAD 60 * 2 * M_PI / 360
# define WIN_HS WIN_H / 2 + 250
# define WIN_WS WIN_W / 2 - 120
# define TEXSIZE 64

typedef struct	s_coord
{
	int			x;
	int			xx;
	int			y;
}				t_coord;

typedef struct	s_coord_d
{
	double		x;
	double		y;
}				t_coord_d;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_bmp
{
	int			width;
	int			height;
	int			size;
	int			*data;
	double		dist;
	double		scale;
	t_coord_d	p;		
}				t_bmp;


typedef struct	s_weapon
{
	t_bmp		img;
	t_bmp		scope;
	int			is_fired;
	int			fire_count;
}				t_weapon;

typedef struct	s_circle
{
	int			x;
	int			y;
	int			xc;
	int			yc;
	int			d;
	int			i;
}				t_circle;

typedef struct	s_spr
{
	double		spr_x;
	double		spr_y;
	double		invdet;
	double		change_x;
	double		change_y;
	double		dist;
	int			screenx;
	int			height;
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	int			width;
	int			stripe;
	int			texx;
	int			texy;
	int			y;
	int			x;
	int			clr;
	t_coord_d	pos;
	t_bmp		*img;
}				t_spr;

typedef struct	s_enemy
{
	t_spr		sprite;
	t_coord_d	pos;
	int			life;
	int			state;
}				t_enemy;

typedef struct	s_app
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*fname;
	char		*img_data;
	int			**map;
	int			bpp;
	int			num;
	int			spr_num;
	int			p_count;
	int			start;
	int			end;
	int			lineheight;
	int			stepx;
	int			stepy;
	int			mapx;
	int			mapy;
	int			side;
	int			hit;
	int			mv_up;
	int			mv_down;
	int			mv_left;
	int			mv_right;
	int			rt_right;
	int			rt_left;
	int			speed;
	int			h;
	int			t;
	int			c;
	int			texx;
	int			texy;
	int			skyx;
	int			skyy;
	int			startscreen;
	int			texnum;
	int			floortex_x;
	int			floortex_y;
	int			current_thread;
	int			enemies_count;
	struct s_app *main_a;
	double		wallx;
	double		weight;
	double		curfloor_x;
	double		curfloor_y;
	double		distplayer;
	double		curdist;
	double		floor_x;
	double		floor_y;
	double		alpha;
	double		loop;
	double		ms;
	double		old_dir_x;
	double		deltadistx;
	double		deltadisty;
	double		raydir_x;
	double		raydir_y;
	double		sidedistx;
	double		sidedisty;
	double		rayposx;
	double		rayposy;
	double		camx;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		dist_wall;
	double		oldplane_x;
	double		clr_intensity;
	double		zbuffer[WIN_W];
	t_bmp		textures[10];
	t_bmp		logo;
	t_bmp		startscreentxt;
	t_coord		p;
	t_coord		map_size;
	t_coord_d	pos;
	t_bmp		sprites[10];
	int			is_weapon;
	t_weapon	weapon;
	int			hp;
	t_enemy		*enemies;
}				t_app;

void			ft_app_allocmap(t_app *app);
void			ft_app_writemap(t_app *app);
void			ft_app_init(t_app *app);

int				expose_hook(t_app *a);
int				ft_key_press(int key, t_app *app);
int				ft_key_press2(int key, t_app *app);
int				ft_key_release(int key, t_app *app);

int				ft_move(t_app *a);

void			ft_pthread(t_app *a);
void			*raycasting(void *tab);

void			ft_apply_shadow_to_cf(t_color *c, int y);
void			draw_wall(int x, int start, int end, t_app *a);
int				ft_draw(t_app *a);

t_color			ft_choose_tex(t_app *a);
void			ft_choose_color(int x, int start, t_app *a);

void			draw_minimap(t_app *a);
void			put_pxl_to_img(t_app *a, int x, int y, int color);
void			draw_player(t_app *a);

int				ft_rgb_to_hex(t_color c);
void			ft_put_pxl_to_img(t_app *a, t_color c, int x, int y);
void			ft_put_circle_to_img(t_app *a, t_circle *c);
void			ft_import_textures(t_app *a);
void			ft_put_bmp_to_img(t_app *a, t_bmp bmp, int x, int y);

int				ft_close(t_app *app);
void			ft_error(char *s);
void			ft_free_strsplit(char **array);
void			ft_init_tex_fc(t_app *a);
void			ft_apply_shadow_to_color(t_color *c, double intensity);
void			ft_apply_shadow_to_spr(t_color *c, int y);

void			bmp_loadfile(t_bmp *bmp, char *fname);
t_color			get_pixel_color(t_bmp *img, int x, int y);

void			weapons_draw_weapon(t_app *a);

void    		sprites_load(t_app *a);
void    		sprites_draw(t_app *a, t_spr s, t_coord_d pos);
void			sprites_get_pos(t_app *a);

void    		textures_load(t_app *a);

void			startscreen_draw(t_app *a);

void			enemies_init(t_app *a);
void			enemies_draw(t_app *a);
#endif
