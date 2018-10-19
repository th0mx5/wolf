/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:41:09 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/19 17:34:24 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static void	put_pxl_to_img(t_app *a, int x, int y, int color)
{
	if (x < a->winsize.x && y < a->winsize.y)
	{
		color = mlx_get_color_value(a->mlx, color);
		ft_memcpy(a->img + 4 * a->winsize.y * y + x * 4,
			&color, sizeof(int));
	}
}

static void	draw_minimap_square(t_app *app, int x, int y)
{
	int		i;
	int		i2;
	int		clr;

	i = 0;
	app->px = 37;
	app->blocs = 7;
	clr = 0x116661;
	while (i != app->blocs)
	{
		i2 = 0;
		while (i2 < app->px)
		{
			put_pxl_to_img(app, x, y, clr);
			i2++;
		}
		i++;
	}
}

void		draw_minimap(t_app *app, int x, int y)
{
	// x  et y commencent a 10
	while (y < 270)
	{
		while (x < 270)
		{
			draw_minimap_square(app, x, y);
			x++;
		}
		y++;
	}
}