/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/11/16 15:40:12 by maxisimo         ###   ########.fr       */
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

/*static void	ft_draw_sky(int x, int start, t_app *a)
{
	int		i;
	int		clr;
	t_color	c1;

	i = 0;
	a->alpha = acos(a->dirX);
	if (a->dirY < 0)
		a->alpha *= -1;
	a->skyX = a->alpha * 128 / (2 * M_PI);
	while (i <= start)
	{
		a->skyY = i * 128 / (WIN_H / 2);
		c1 = get_pixel_color(&a->textures[2], (int)a->skyX, (int)a->skyY);
		clr = ft_rgb_to_hex(c1);
		ft_memcpy(a->img_data + 4 * WIN_W * i + x * 4,
				&clr, sizeof(int));
		i++;
	}
}*/

static void ft_apply_shadow_to_color(t_color *c, double intensity)
{
	c->r = c->r * intensity;
	c->g = c->g * intensity;
	c->b = c->b * intensity;
}

static void	ft_put_pixel(int x, int start, t_app *a)
{
	int		clr;
	t_color	c1;

	if (a->t == 1)
	{
		if (a->side == 0 && a->rayDirX < 0)
			a->texnum = 2;
		if (a->side == 0 && a->rayDirX > 0)
			a->texnum = 3;
		if (a->side == 1 && a->rayDirY < 0)
			a->texnum = 4;
		if (a->side == 1 && a->rayDirY > 0)
			a->texnum = 5;
		c1 = get_pixel_color(&a->textures[a->texnum], a->texX, a->texY);
	}
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

void		draw_wall(int x, int start, int end, t_app *a)
{
	int		y;
	double	wallX;

	y = start;
	if (a->t == 1)
		a->texnum = a->map[(int)a->mapY][(int)a->mapX] - 1;
	if (a->side == 0)
		wallX = a->pos.x + a->dist_wall * a->rayDirY;
	else
		wallX = a->pos.y + a->dist_wall * a->rayDirX;
	wallX -= floor(wallX); 
	a->texX = (int)(wallX * 128);
	if (a->side == 0 && a->rayDirX > 0) 
		a->texX = 128 - a->texX - 1;
    if (a->side == 1 && a->rayDirY < 0) 
		a->texX = 128 - a->texX - 1;
	ft_floor_and_ceilling(x, start, 0, a);
	//(a->t == 0) ? ft_floor_and_ceilling(x, start, 0, a) : ft_draw_sky(x, start, a);
	while (++start <= end)
	{
		if (start >= 0 && start < WIN_H)
		{
			a->texY = (y - start + 1) * 128 / a->wall_size;
			ft_put_pixel(x, start, a);
		}
	}
}
