/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/30 13:37:04 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_floor_and_ceilling(int x, int start, int clr, t_app *a)
{
	int		i;

	i = -1;
	while (++i < start)
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
}

static void	ft_put_pixel(int x, int start, t_app *a)
{
	int		clr;
	t_color	color;

	if (a->t == 1 && x < WIN_W && start < WIN_H)
	{
		a->texY = abs((((start * 256 - WIN_H * 128 + a->lineheight * 128)
					* 64) / a->lineheight) / 256);
		color = get_pixel_color(&a->textures[0], a->texX, a->texY);
		clr = ft_rgb_to_hex(color);
		ft_memcpy(a->img_data + 4 * WIN_W * start + x * 4,
				&clr, sizeof(int));
	}
	else if (x < WIN_W && start < WIN_H)
		ft_memcpy(a->img_data + 4 * WIN_W * start + x * 4,
				&a->color, sizeof(int));
}

void		draw_wall(int x, int start, int end, t_app *a)
{
	ft_floor_and_ceilling(x, start, 0, a);
	if (a->t == 1)
	{
		if (a->side == 0)
			a->wallX = a->rayPosY + a->dist_wall * a->rayDirY;
		else
			a->wallX = a->rayPosX + a->dist_wall * a->rayDirX;
		a->texX = (int)(a->wallX * 64);
		if (a->side == 0 && a->rayDirX > 0)
			a->texX = 64 - a->texX - 1;
		if (a->side == 1 && a->rayDirY < 0)
			a->texX = 64 - a->texX - 1;
		a->texX = abs(a->texX);
	}
	while (++start <= end)
		ft_put_pixel(x, start, a);
}
