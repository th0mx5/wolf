/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:41:09 by maxisimo          #+#    #+#             */
/*   Updated: 2018/11/02 17:23:46 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	put_pxl_to_img(t_app *a, int x, int y, int color)
{
	if (x < WIN_W && y < WIN_H) // && a->mx < a->map_size.x && a->my < a->map_size.y)
	{
		ft_memcpy(a->img_data + 4 * WIN_W * y + x * 4,
			&color, sizeof(int));
	}
}

static int	check_map(t_app *a, int x, int y)
{
	t_color	c1;

	c1.r = 225;
	c1.g = 130;
	c1.b = 0;
	if (a->map[x][y] == 1)
		return (ft_rgb_to_hex(c1));
	return (0);
}

/*void		draw_minimap(t_app *app)
{
	int			x;
	int			y;
	int			color;

	app->mx = 0;
	x = 8;
	app->kx = 262.0 / app->map_size.x;
	app->ky = 262.0 / app->map_size.y;
	while (++x < 271)
	{
		app->my = 0;
		if ((x % (int)app->kx == 0) && (app->mx < app->map_size.x - 1))
		{
			color = check_map(app, app->mx, app->my);
			app->mx++;
		}
		y = 8;
		while (++y < 271)
		{
			if ((y % (int)app->ky == 0) && (app->my < app->map_size.y - 1))
			{
				color = check_map(app, app->mx, app->my);
				app->my++;
			}
			put_pxl_to_img(app, x, y, color);
		}
	}
}*/

void		draw_minimap(t_app *a)
{
	int		x;
	int		y;

	x = 8;
	while (++x < 271)
	{
		color = 0xFFFFFF;
		y = 8;
		while (++y < 271)
			put_pxl_to_img(a, x, y, color);
	}
}