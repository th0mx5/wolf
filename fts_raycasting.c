/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:20:06 by maxisimo          #+#    #+#             */
/*   Updated: 2018/11/19 14:02:38 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static void	dda_init(t_app *app)
{
	app->deltadistx = fabs(1 / app->raydir_x);
	app->deltadisty = fabs(1 / app->raydir_y);
	if (app->raydir_x < 0)
	{
		app->stepx = -1;
		app->sidedistx = (app->rayposx - app->mapx) * app->deltadistx;
	}
	else
	{
		app->stepx = 1;
		app->sidedistx = (app->mapx + 1. - app->rayposx) * app->deltadistx;
	}
	if (app->raydir_y < 0)
	{
		app->stepy = -1;
		app->sidedisty = (app->rayposy - app->mapy) * app->deltadisty;
	}
	else
	{
		app->stepy = 1;
		app->sidedisty = (app->mapy + 1. - app->rayposy) * app->deltadisty;
	}
}

static void	dda(t_app *app)
{
	app->hit = 0;
	while (app->hit == 0)
	{
		if (app->sidedistx < app->sidedisty)
		{
			app->sidedistx += app->deltadistx;
			app->mapx += app->stepx;
			app->side = 0;
		}
		else
		{
			app->sidedisty += app->deltadisty;
			app->mapy += app->stepy;
			app->side = 1;
		}
		if (app->map[app->mapy][app->mapx] > 0)
			app->hit = 1;
	}
}

static void	raycasting_init(t_app *app, int x)
{
	app->camx = 2 * x / (double)WIN_W - 1;
	app->rayposx = app->pos.y;
	app->rayposy = app->pos.x;
	app->raydir_x = app->dir_x + app->plane_x * app->camx;
	app->raydir_y = app->dir_y + app->plane_y * app->camx;
	app->mapx = (int)app->rayposx;
	app->mapy = (int)app->rayposy;
	dda_init(app);
	dda(app);
	if (app->side == 0)
		app->dist_wall = (app->mapx - app->rayposx + (1 - app->stepx) / 2) /
			app->raydir_x;
	else
		app->dist_wall = (app->mapy - app->rayposy + (1 - app->stepy) / 2) /
			app->raydir_y;
}

void		raycasting(t_app *a)
{
	int		n[3];
	t_coord	p;

	p.x = -1;
	a->img = mlx_new_image(a->win, WIN_W, WIN_H);
	a->img_data = mlx_get_data_addr(a->img, &n[0], &n[1], &n[2]);
	while (++p.x < WIN_W)
	{
		raycasting_init(a, p.x);
		a->lineheight = (int)(WIN_H / a->dist_wall);
		a->start = -a->lineheight / 2 + a->lookud;
		a->end = a->lineheight / 2 + a->lookud;
		a->wall_size = a->start - a->end;
		a->clr_intensity = (a->dist_wall < 1) ? 1 : 1 / a->dist_wall;
		draw_wall(p.x, a->start, a->end, a);
	}
	draw_minimap(a);
	draw_player(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	mlx_destroy_image(a->mlx, a->img);
	mlx_do_sync(a->mlx);
}
