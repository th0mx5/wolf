/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:39:39 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/02 13:59:50 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_wall(t_var *v, int dpp)
{
	int		proj_slice_height;

	proj_slice_height = 64 / v->dist * dpp;
	/*
	 * proj_slice_height : taille percue du mur, t'as juste a afficher le mur
	 * et mettre le reste en noir pour voir si ca marche, regarde le lien que
	 * je t'ai envoye sur messenger.
	*/
}

static void	calc_dist(t_var *v, int x, double tx, double ty)
{
	int		dist_pp;

	dist_pp = (WIN_W / 2) / atan(30); //pas sur si on met atan ou tan;
	v->angle_ray = FOV / (WIN_W - 280);
	v->Xa = 64 / tan(FOV);
	if (v->alpha != 0. && v->alpha != PI)
	{
		v->Ya = (v->alpha > 0. && v->alpha < PI) ? -64 : 64;
		v->Ay = (ty / 64) * 64 - 1;
	}
	else
		v->Ya = 0;
	v->Ax = tx + (ty - v->Ay) / atan(v->alpha); //pas sur si on met atan ou tan
	while (v->map[(int)(ty)][(int)(tx)][0] != 1)
	{
		tx += v->Xa;
		ty += v->Ya;
	}
	v->dist = (sqrt(pow((tx - v->posx), 2.) + pow((ty - v->posy), 2.)) *
			cos(v->angle_ray * (PI / 180.)));
	draw_wall(v, dist_pp);
}

void		raycasting(t_var *v)
{
	v->x = 279;
	while (++v->x < WIN_W)
		calc_dist(v, v->x, v->posx, v->posy);
}
