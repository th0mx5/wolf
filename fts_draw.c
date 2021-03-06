/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/12/11 12:20:43 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_draw_sky(int x, int start, t_app *a)
{
	int		i;
	int		clr;
	t_color	c1;

	i = 0;
	a->alpha = asin(a->dir_x);
	if (a->alpha != a->alpha)
		a->alpha = M_PI;
	if (a->dir_y < 0)
		a->alpha *= -1;
	a->alpha += M_PI;
	a->alpha += x * FOV_RAD / WIN_W - HFOV_RAD;
	a->alpha += (a->alpha < 0) ? 2 * M_PI : 0;
	a->alpha -= (a->alpha > 2 * M_PI) ? 2 * M_PI : 0;
	a->skyx = a->alpha * a->textures[8].width / (2 * M_PI);
	while (i <= start)
	{
		a->skyy = a->textures[8].height - i * a->textures[8].height / (WIN_H);
		c1 = get_pixel_color(&a->textures[8], (int)a->skyx, (int)a->skyy);
		clr = ft_rgb_to_hex(c1);
		ft_memcpy(a->img_data + 4 * WIN_W * i + x * 4,
				&clr, sizeof(int));
		i++;
	}
}

static void		ft_floor_and_ceilling(int x, int y, t_app *a)
{
	t_color	c1;

	y = a->end;
	ft_init_tex_fc(a);
	while (y < WIN_H)
	{
		a->curdist = WIN_H / (2.0 * y - WIN_H);
		a->weight = a->curdist / a->dist_wall;
		a->curfloor_x = a->weight * a->floor_x + (1.0 - a->weight) * a->pos.y;
		a->curfloor_y = a->weight * a->floor_y + (1.0 - a->weight) * a->pos.x;
		a->floortex_x = (int)(a->curfloor_x * TEXSIZE) % TEXSIZE;
		a->floortex_y = (int)(a->curfloor_y * TEXSIZE) % TEXSIZE;
		a->floortex_x = abs(a->floortex_x);
		a->floortex_y = abs(a->floortex_y);
		c1 = get_pixel_color(&a->textures[3], a->floortex_x, a->floortex_y);
		ft_apply_shadow_to_cf(&c1, y);
		ft_put_pxl_to_img(a, c1, x, (WIN_H - y));
		c1 = get_pixel_color(&a->textures[6], a->floortex_x, a->floortex_y);
		ft_apply_shadow_to_cf(&c1, y);
		ft_put_pxl_to_img(a, c1, x, y);
		y++;
	}
}

void			ft_choose_color(int x, int start, t_app *a)
{
	t_color c1;

	a->texnum = a->map[a->mapy][a->mapx] - 1;
	c1 = get_pixel_color(&a->textures[a->texnum], a->texx, a->texy);
	ft_apply_shadow_to_color(&c1, a->clr_intensity);
	ft_put_pxl_to_img(a, c1, x, start);
}

void			draw_wall(int x, int start, int end, t_app *a)
{
	int		y;

	y = start;
	if (a->side == 0)
		a->wallx = a->pos.x + a->dist_wall * a->raydir_y;
	else
		a->wallx = a->pos.y + a->dist_wall * a->raydir_x;
	a->wallx -= floor(a->wallx);
	a->texx = (int)(a->wallx * TEXSIZE);
	if (a->side == 0 && a->raydir_x > 0)
		a->texx = TEXSIZE - a->texx - 1;
	if (a->side == 1 && a->raydir_y < 0)
		a->texx = TEXSIZE - a->texx - 1;
	if (a->c == 0)
		ft_floor_and_ceilling(x, start, a);
	else if (a->c == 1)
		ft_draw_sky(x, start, a);
	while (++start <= end - 1)
	{
		a->texy = (start - WIN_H / 2 + a->lineheight / 2)
			* TEXSIZE / a->lineheight;
		a->texy = abs(a->texy);
		ft_choose_color(x, start, a);
	}
}

int				ft_draw(t_app *a)
{
	int		n[3];

	a->img = mlx_new_image(a->win, WIN_W, WIN_H);
	a->img_data = mlx_get_data_addr(a->img, &n[0], &n[1], &n[2]);
	if (a->startscreen == 0)
	{
		ft_pthread(a);
		enemies_draw(a);
		draw_minimap(a);
		draw_player(a);
		weapons_draw_weapon(a);
		ft_move(a);
		mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	}
	else
		startscreen_draw(a);
	mlx_destroy_image(a->mlx, a->img);
	mlx_do_sync(a->mlx);
	return (0);
}
