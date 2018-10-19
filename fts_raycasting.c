/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:20:06 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/19 17:36:46 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_wall(int x, int start, int end, t_app *app)
{
	while (++start <= end)
	{
		if (x < app->winsize.x && start < app->winsize.y)
			ft_memcpy(app->img_data + 4 * app->winsize.x * start + x * 4,
					&app->color, sizeof(int));
	}
}

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
		}
		else
		{
			app->sideDistY += app->deltaDistY;
			app->mapY += app->stepY;
			app->side = 1;
		}
		if (app->map[app->mapX][app->mapY] == 1)
			app->hit = 1;
	}
}

static void	raycasting_init(t_app *app, int x)
{
	app->camX = 2 * x / (double)app->winsize.x - 1;
	app->rayPosX = app->pos.x;
	app->rayPosY = app->pos.y;
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

void	raycasting(t_app *app)
{
	t_coord	p;
	int		n[3];

	p.x = 279;
	app->img = mlx_new_image(app->win, app->winsize.x, app->winsize.y);
	app->img_data = mlx_get_data_addr(app->img, &n[0], &n[1], &n[2]);
	while (++p.x < app->winsize.x)
	{
		raycasting_init(app, p.x);
		app->lineheight = (int)(app->winsize.y / app->dist_wall);
		app->start = -app->lineheight / 2 + app->winsize.y / 2;
		if (app->start < 0)
			app->start = 0;
		app->end = app->lineheight / 2 + app->winsize.y / 2;
		if (app->end >= app->winsize.y)
			app->end = app->winsize.y - 1;
		if (app->side == 1)
			app->color = 0xdd8800;
		else
			app->color = 0x00FF00;
		draw_wall(p.x, app->start - 1, app->end, app);
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
	mlx_destroy_image(app->mlx, app->img);
	mlx_do_sync(app->mlx);
}
