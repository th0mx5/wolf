/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:41:09 by maxisimo          #+#    #+#             */
/*   Updated: 2018/11/16 13:09:39 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	put_pxl_to_img(t_app *a, int x, int y, int color)
{
	if (x < WIN_W && y < WIN_H)
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
	if (a->map[x][y] >= 1)
		return (ft_rgb_to_hex(c1));
	return (0);
}

void		draw_player(t_app *a)
{
	int		x;
	int		y;
	int		xc;
	int		yc;
	int		d;
	int		i = -1;
	t_color	c1;

	a->loop = a->loop + 0.05;
	c1.r = fabs(sin(a->loop)) * 255;
	c1.g = 0;
	c1.b = 0;
	while (++i < 5)
	{
		x = 0;
		y = i;
		d = 5 - 4 * i;
		xc = 131;
		yc = 131;
		while (x <= y)
		{
			put_pxl_to_img(a, xc + x, yc - y, 0xFF0000);
			put_pxl_to_img(a, xc - x, yc - y, 0xFF0000);
			put_pxl_to_img(a, xc + x, yc + y, 0xFF0000);
			put_pxl_to_img(a, xc - x, yc + y, 0xFF0000);
			put_pxl_to_img(a, xc + y, yc - x, 0xFF0000);
			put_pxl_to_img(a, xc - y, yc - x, 0xFF0000);
			put_pxl_to_img(a, xc + y, yc + x, 0xFF0000);
			put_pxl_to_img(a, xc - y, yc + x, 0xFF0000);
			if (d > 0)
			{
				y--;
				d -= 8 * y;
			}
			x++;
			d = d + 8 * x + 4;
		}
	}
}

void		draw_minimap(t_app *a)
{
	int		x;
	int		y;
	int		block;
	int		color;
	t_coord	tmp;

	x = 8;
	block = 37;
	while (++x < 271)
	{
		y = 8;
		while (++y < 271)
		{
			color = 0;
			tmp.x = (x / block) + a->pos.x - 3;
			tmp.y = (y / block) + a->pos.y - 3;
			if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < a->map_size.x
					&& tmp.y < a->map_size.y)
				color = check_map(a, tmp.x, tmp.y);
			put_pxl_to_img(a, x, y, color);
		}
	}
}