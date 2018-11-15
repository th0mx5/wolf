/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/11/15 13:58:37 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_floor_and_ceilling(int x, int start, int clr, t_app *a)
{
	int		i;

	i = -1;
	while (++i <= start)
	{
		clr = (a->t == 1) ? 0x0000FF : 0;
		if (x < WIN_W && i < WIN_H)
			ft_memcpy(a->img_data + 4 * WIN_W * i + x * 4,
					&clr, sizeof(int));
	}
	while (i++ < WIN_H)
	{
		clr = (a->t == 1) ? 0x555555 : 0;
		if (x < WIN_W && i < WIN_H)
			ft_memcpy(a->img_data + 4 * WIN_W * i + x * 4,
					&clr, sizeof(int));
	}
}

static void	ft_put_pixel(int x, int y, int start, int textX, t_app *a)
{
	int		clr;
	t_color	c1;

	if (a->side == 0)
		c1 = get_pixel_color(&a->textures[a->texnum], (textX / 2),
			(-start + y) * 128 / a->wall_size);
	else
		c1 = get_pixel_color(&a->textures[a->texnum + 1], (textX / 2),
			(-start + y) * 128 / a->wall_size);
	clr = ft_rgb_to_hex(c1);
	if (x < WIN_W && start < WIN_H && a->t == 1)
		ft_memcpy(a->img_data + 4 * WIN_W * start + x * 4,
				&clr, sizeof(int));
	else if (x < WIN_W && start < WIN_H)
		ft_memcpy(a->img_data + 4 * WIN_W * start + x * 4,
				&a->color, sizeof(int));
}

void		draw_wall(int x, int start, int end, t_app *a)
{
	int		y;
	int 	textX;
	double	wallX;

	y = start;
	if (a->t == 1)
		a->texnum = a->map[(int)a->mapY][(int)a->mapX] - 1;
	if (a->side == 0)
		wallX = a->pos.x + a->dist_wall * a->rayDirY;
	else
		wallX = a->pos.y + a->dist_wall * a->rayDirX;
	wallX -= floor(wallX); 
	textX = (int)(wallX * 128);
	if (a->side == 0 && a->rayDirX > 0) 
		textX = 128 - textX - 1;
    if (a->side == 1 && a->rayDirY < 0) 
		textX = 128 - textX - 1;

	ft_floor_and_ceilling(x, start, 0, a);
	while (++start <= end)
	{
		if (start > 0)
			ft_put_pixel(x, y, start, textX, a);
	}
}
