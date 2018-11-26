/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_weapons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/11/26 10:16:47 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	weapons_draw_weapon(t_app *a)
{
	t_coord	tmp;
	t_coord tmp2;

	if (a->weapon == 1)
	{
		tmp.x = WIN_W - a->sprites[0].width;
		tmp.y = WIN_H - a->sprites[0].height;
		tmp2.x = WIN_W / 2 - a->sprites[1].width / 2;
		tmp2.y = WIN_H / 2 - a->sprites[1].height / 2;
		ft_put_bmp_to_img(a, a->sprites[0], tmp.x, tmp.y);
		ft_put_bmp_to_img(a, a->sprites[1], tmp2.x, tmp2.y);
	}
}
