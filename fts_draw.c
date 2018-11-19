/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/11/19 14:07:24 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_floor_and_ceilling(int x, int start, int clr, t_app *a)
{
	int		i;

	i = -1;
	while (++i <= start)
	{
		clr = 0x2A2A2A;
		if (x < WIN_W && i < WIN_H)
			ft_memcpy(a->img_data + 4 * WIN_W * i + x * 4,
					&clr, sizeof(int));
	}
	while (i++ < WIN_H)
	{
		clr = 0x424242;
		if (x < WIN_W && i < WIN_H)
			ft_memcpy(a->img_data + 4 * WIN_W * i + x * 4,
					&clr, sizeof(int));
	}
}

static void		ft_apply_shadow_to_color(t_color *c, double intensity)
{
	c->r = c->r * intensity;
	c->g = c->g * intensity;
	c->b = c->b * intensity;
}

static t_color	ft_choose_tex(t_app *a)
{
	if (a->side == 0 && a->raydir_x < 0)
		a->texnum = 2;
	if (a->side == 0 && a->raydir_x > 0)
		a->texnum = 3;
	if (a->side == 1 && a->raydir_y < 0)
		a->texnum = 4;
	if (a->side == 1 && a->raydir_y > 0)
		a->texnum = 5;
	return (get_pixel_color(&a->textures[a->texnum], a->texx, a->texy));
}

static void		ft_put_pixel(int x, int start, t_app *a)
{
	int		clr;
	t_color c1;

	if (a->t == 1)
		c1 = ft_choose_tex(a);
	else
	{
		if (a->side == 1)
		{
			c1.r = 221;
			c1.g = 129;
			c1.b = 0;
		}
		else
		{
			c1.r = 86;
			c1.g = 65;
			c1.b = 0;
		}
	}
	if (a->h)
		ft_apply_shadow_to_color(&c1, a->clr_intensity);
	clr = ft_rgb_to_hex(c1);
	ft_memcpy(a->img_data + 4 * WIN_W * start + x * 4, &clr, sizeof(int));
}

void			draw_wall(int x, int start, int end, t_app *a)
{
	int		y;
	double	wallx;

	y = start;
	if (a->t == 1)
		a->texnum = a->map[(int)a->mapy][(int)a->mapx] - 1;
	if (a->side == 0)
		wallx = a->pos.x + a->dist_wall * a->raydir_y;
	else
		wallx = a->pos.y + a->dist_wall * a->raydir_x;
	wallx -= floor(wallx);
	a->texx = (int)(wallx * 128);
	if (a->side == 0 && a->raydir_x > 0)
		a->texx = 128 - a->texx - 1;
	if (a->side == 1 && a->raydir_y < 0)
		a->texx = 128 - a->texx - 1;
	if (a->h != 1)
		ft_floor_and_ceilling(x, start, 0, a);
	while (++start <= end)
	{
		if (start >= 0 && start < WIN_H)
		{
			a->texy = (y - start + 1) * 128 / a->wall_size;
			ft_put_pixel(x, start, a);
		}
	}
}
