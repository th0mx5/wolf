/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:39:39 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/07 16:41:59 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_wall(t_var *v, int dpp)
{
	int		proj_slice_height;
	int		clr;
	int		mp;

	v->y = 0;
	proj_slice_height = 64 / v->dist * dpp;
	mp = WIN_H / 2 - (proj_slice_height / 2);
	clr = 0x804d17;
	while (++v->y < WIN_H)
	{
		if (v->y >= mp && v->y <= mp + proj_slice_height)
			ft_img_putpixel(v, 0x804d17);
		else
			ft_img_putpixel(v, 0x000000);
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	mlx_destroy_image(v->mlx, v->img);
	mlx_do_sync(v->mlx);
}

void		ft_img_putpixel(t_var *v, int color)
{
	int		i;

	i = (v->x + (v->y * WIN_W)) * 4;
	if (v->x > -1 && v->y > -1 && v->x < WIN_W && v->y < WIN_H)
	{
		v->img_data[i] = color;
	}
}

static void	calc_dist(t_var *v, double tx, double ty)
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

	/*
	 * a partir de la c'est la merde
	*/

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
	v->posx = v->p_x;
	v->posy = v->p_y;
	v->x = 279;
	printf("posx %lf\n", v->posx);
	printf("posy %lf\n", v->posy);
	while (++v->x < WIN_W)
		calc_dist(v, v->posx, v->posy);
}