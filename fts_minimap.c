/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:41:09 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/30 18:11:18 by maxisimo         ###   ########.fr       */
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
	if (a->map[x][y] == 1)
		return (0xdd8100);
	return (0);
}

void		draw_minimap(t_app *app)
{
	int			x;
	int			y;
	int			mx;
	int			m_y;
	int			color;

	mx = 0;
	x = 8;
	app->kx = 262.0 / app->map_size.x;
	app->ky = 262.0 / app->map_size.y;
	while (++x < 271)
	{
		m_y = 0;
		if ((x % (int)app->kx == 0) && (mx <= app->map_size.x - 1))
		{
			color = check_map(app, mx, m_y);
			mx++;
		}
		y = 9;
		while (++y < 271)
		{
			if ((y % (int)app->ky == 0) && (m_y <= app->map_size.y))
			{
				color = check_map(app, mx, m_y);
				m_y++;
			}
			put_pxl_to_img(app, x, y, color);
		}
	}
}