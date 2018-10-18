/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:41:09 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/18 17:53:41 by maxisimo         ###   ########.fr       */
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

static int	check_minimap_point(t_app *a, int x, int y)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = 0;
	j = 3;
	while (i < 4)
	{
		if (a->map[x][y] == '1')
			c = !c;
		j = i++;
	}
	printf("%d\n", c);
	return (c);
}

static void	draw_minimap_square(t_app *a, int x, int y)
{
	int		clr;

	clr = 0x3D3D3D;
	y = 25;
	while (++y <= 187 && (x = 25) == 25)
		while (++x <= 187)
			if (check_minimap_point(a, x, y) == 1)
				put_pxl_to_img(a, x, y, clr);
}

void		draw_mm(t_app *a, int x, int y)
{
	int		clr;
	int		end_x;
	int		end_y;
	int		i;

	i = ((a->pos.x) >= 0) ? (int)(a->pos.x) : 0;
	end_x = (a->pos.x >= a->map_size.x) ? a->map_size.x : (int)a->pos.x;
	y = (a->pos.y >= 0) ? (int)(a->pos.y) : 0;
	end_y = (a->pos.y >= a->map_size.y) ? a->map_size.y : (int)a->pos.y;
	while (++y < end_y && (x = i) == i)
		while (++x < end_x)
			if (a->map[x][y] != '1')
				draw_minimap_square(a, x, y);
	clr = 0x2686D9;
}
