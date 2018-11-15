/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:20:06 by maxisimo          #+#    #+#             */
/*   Updated: 2018/11/15 18:44:43 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static void	dda_init(t_app *app)
{
	app->deltaDistX = fabs(1 / app->rayDirX);
	app->deltaDistY = fabs(1 / app->rayDirY);
	if (app->rayDirX < 0)
	{
		app->stepX = -1;
		app->sideDistX = (app->rayPosX - app->mapX) * app->deltaDistX;
	}
	else
	{
		app->stepX = 1;
		app->sideDistX = (app->mapX + 1. - app->rayPosX) * app->deltaDistX;
	}
	if (app->rayDirY < 0)
	{
		app->stepY = -1;
		app->sideDistY = (app->rayPosY - app->mapY) * app->deltaDistY;
	}
	else
	{
		app->stepY = 1;
		app->sideDistY = (app->mapY + 1. - app->rayPosY) * app->deltaDistY;
	}
}

static void	dda(t_app *app)
{
	app->hit = 0;
	while (app->hit == 0)
	{
		if (app->sideDistX < app->sideDistY)
		{
			app->sideDistX += app->deltaDistX;
			app->mapX += app->stepX;
			app->side = 0;
			if (app->rayDirX < 0)
				app->NorthSouth = 1;
			else if (app->rayDirX > 0)
				app->NorthSouth = 0;
		}
		else
		{
			app->sideDistY += app->deltaDistY;
			app->mapY += app->stepY;
			app->side = 1;
			if (app->rayDirY < 0)
				app->EastWest = 1;
			else if (app->rayDirY > 0)
				app->EastWest = 0;
		}
		if (app->map[app->mapY][app->mapX] > 0)
			app->hit = 1;
	}
}

static void	raycasting_init(t_app *app, int x)
{
	app->camX = 2 * x / (double)WIN_W - 1;
	app->rayPosX = app->pos.y;
	app->rayPosY = app->pos.x;
	app->rayDirX = app->dirX + app->planeX * app->camX;
	app->rayDirY = app->dirY + app->planeY * app->camX;
	app->mapX = (int)app->rayPosX;
	app->mapY = (int)app->rayPosY;
	dda_init(app);
	dda(app);
	if (app->side == 0)
		app->dist_wall = (app->mapX - app->rayPosX + (1 - app->stepX) / 2) /
			app->rayDirX;
	else
		app->dist_wall = (app->mapY - app->rayPosY + (1 - app->stepY) / 2) /
			app->rayDirY;
}

void		raycasting(t_app *a)
{
	int		n[3];
	t_coord	p;

	p.x = 0;
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
	/*printf("dirX = %lf\n", a->rayDirX);
	printf("dirY = %lf\n", a->rayDirY);*/
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	mlx_destroy_image(a->mlx, a->img);
	mlx_do_sync(a->mlx);
}
