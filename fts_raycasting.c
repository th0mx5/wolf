/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 19:20:06 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/29 19:31:23 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static void	draw_wall(int x, int start, int end, t_app *a)
{
	int		i;
	int		clr;
	t_color	c1;
	t_color c2;;
	double		intensity;

	i = -1;
	intensity = (a->dist_wall < 1) ? 1 : 1 / a->dist_wall;
	//printf("%d\n", a->textures[0].cursor.x);
	c1.r = c1.r * intensity;
	c1.g = c1.g * intensity;
	c1.b = c1.b * intensity;
	c2.r = c2.r * intensity;
	c2.g = c2.g * intensity;
	c2.b = c2.b * intensity;
	if (a->side == 1)
	{
		if (a->h == 0)
			a->color = 0xdd8100;
		//else
			//a->color = ((c1.r & 0xff) << 16) + ((c1.g & 0xff) << 8) + (c1.b & 0xff);
	}
	else
	{
		if (a->h == 0)
			a->color = 0x7b4801;
		//else
			//a->color = ((c2.r & 0xff) << 16) + ((c2.g & 0xff) << 8) + (c2.b & 0xff);
	}
	while (++i < a->start)
	{
		clr = 0;
		if (x < WIN_W && i < WIN_H)
			ft_memcpy(a->img_data + 4 * WIN_W * i + x * 4,
					&clr, sizeof(int));
	}
	while (i++ < WIN_H)
	{
		clr = 0;
		if (x < WIN_W && i < WIN_H)
			ft_memcpy(a->img_data + 4 * WIN_W * i + x * 4,
					&clr, sizeof(int));
	}
	while (++start <= end)
	{
		if (x < WIN_W && start < WIN_H && a->h == 0)
			ft_memcpy(a->img_data + 4 * WIN_W * start + x * 4,
					&a->color, sizeof(int));
		else if (x < WIN_W && start < WIN_H && a->h == 1)
		{
			//printf("%d, %d, %d\n", c1.r, c1.g, c1.b);
			c1 = get_pixel_color(&a->textures[0], a->textures[0].cursor.x, a->textures[0].cursor.y  % 128);
			c2 = get_pixel_color(&a->textures[0], a->textures[0].cursor.x, a->textures[0].cursor.y  % 128);
			//a->textures[0].cursor.y++;
			if (a->side == 1)
				a->color = ft_rgb_to_hex(c1);
			else
				a->color = ft_rgb_to_hex(c2);
			ft_memcpy(a->img_data + 4 * WIN_W * start + x * 4,
					&a->color, sizeof(int));
		}
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

void	raycasting(t_app *a)
{
	t_coord	p;
	int		n[3];
	p.x = 279;
	a->img = mlx_new_image(a->win, WIN_W, WIN_H);
	a->img_data = mlx_get_data_addr(a->img, &n[0], &n[1], &n[2]);
	while (++p.x < WIN_W)
	{
		raycasting_init(a, p.x);
		a->lineheight = (int)(WIN_H / a->dist_wall);
		a->start = -a->lineheight / 2 + a->lookud;
		if (a->start < 0)
			a->start = 0;
		a->end = a->lineheight / 2 + a->lookud;
		if (a->end >= WIN_H)
			a->end = WIN_H - 1;
		draw_wall(p.x, a->start - 1, a->end, a);
	}
	//printf("%lf\n", a->dist_wall);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	mlx_destroy_image(a->mlx, a->img);
	mlx_do_sync(a->mlx);
}
