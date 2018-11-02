/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:41:09 by maxisimo          #+#    #+#             */
/*   Updated: 2018/11/02 18:55:12 by maxisimo         ###   ########.fr       */
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
	if (a->map[x][y] == 1)
		return (ft_rgb_to_hex(c1));
	return (0);
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
			color = 0xFFFFFF;
			tmp.x = (x / block) + a->pos.x - 3;
			tmp.y = (y / block) + a->pos.y - 3;
			if (tmp.x >= 0 && tmp.y >= 0 && tmp.x < a->map_size.x
					&& tmp.y < a->map_size.y)
				color = check_map(a, tmp.x, tmp.y);
			put_pxl_to_img(a, x, y, color);
			tmp.x = 131 - block;
			tmp.y = 131 - block;
			/*while (tmp.x < 131 + block)
			{
				tmp.y = 131 - block;
				while (tmp.y < 131 + block)
				{
					put_pxl_to_img(a, tmp.x, tmp.y, 0xF1F1F1);
					tmp.y++;
				}
				tmp.x++;
			}*/
			put_pxl_to_img(a, 131, 131, 0xF1F1F1);
			
		}
	}
}