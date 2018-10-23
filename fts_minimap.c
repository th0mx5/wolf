/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:41:09 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/23 13:30:41 by maxisimo         ###   ########.fr       */
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

void		draw_minimap(t_app *app)
{
	int		x;
	int		y;
	double		labx;
	double		laby;
	int		clr;

	x = -1;
	while (++x <  150)
	{
		y = -1;
		while (++y < 150)
		{
			labx = (x * app->map_size.x) / 150.;
			laby = ((150 - y) * app->map_size.y) / 150.;
			clr = (app->map[(int)labx][(int)laby] != 0 ? 0 : 0xFFFFFF);
			put_pxl_to_img(app, x, 150 - y, clr);
		}
	}
}