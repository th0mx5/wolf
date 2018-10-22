/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:41:09 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/22 17:01:45 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	put_pxl_to_img(t_app *a, int x, int y, int color)
{
	if (x < a->winsize.x && y < a->winsize.y)
	{
		ft_memcpy(a->img_data + 4 * a->winsize.x * y + x * 4,
			&color, sizeof(int));
	}
}

void		draw_minimap(t_app *app)
{
	int		x;
	int		y;

	y = 0;
	while (y < app->winsize.y)
	{
		x = 0;
		while (x < 281)
		{
			if ((x < 10 || x >= 271) && (y <= 10 || y >= 271))
				put_pxl_to_img(app, x, y, 0x7b4801);
			x++;
		}
		y++;
	}
}