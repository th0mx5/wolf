/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:41:09 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/19 18:28:52 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static void	put_pxl_to_img(t_app *a, int x, int y, int color)
{
	//printf("lolilol\n");
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
	while (i != app->blocs && x < 270)
	{
		i2 = 0;
		while (i2 < app->px)
		{
			put_pxl_to_img(app, x, y, clr);
			i2++;
			x++;
			printf("%d  ", x);
		}
		i++;
	}
}

void		draw_minimap(t_app *app, int x, int y)
{
	printf("lol\n");
	// x  et y commencent a 10
	while (y < 270)
	{
		while (x < 270)
			draw_minimap_square(app, x, y);
		y++;
	}
}