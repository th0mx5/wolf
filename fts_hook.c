/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:15:41 by maxisimo          #+#    #+#             */
/*   Updated: 2018/11/26 22:09:08 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_start_screen(t_app *a)
{
	t_color	c1;
	t_coord tmp;
	int		n[3];
	double	sin_factor;

	a->img = mlx_new_image(a->win, WIN_W, WIN_H);
	a->img_data = mlx_get_data_addr(a->img, &n[0], &n[1], &n[2]);
	a->loop = a->loop + 0.02;
	sin_factor = fabs(sin(a->loop));
	c1.r = sin_factor * 255;
	c1.g = sin_factor * 255;
	c1.b = sin_factor * 255;
	a->logo.scale = 2 * (sin_factor + 1);
	tmp.x = WIN_W / 2 - a->logo.width / 2 * a->logo.scale;
	tmp.y = WIN_H / 2 - a->logo.height / 2 * a->logo.scale;
	ft_put_bmp_to_img(a, a->logo, tmp.x, tmp.y);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	mlx_string_put(a->mlx, a->win, WIN_WS, WIN_HS, ft_rgb_to_hex(c1), START);
	mlx_destroy_image(a->mlx, a->img);
	mlx_do_sync(a->mlx);
}

int			expose_hook(t_app *a)
{
	if (a->startscreen == 0)
		ft_start_screen(a);
	else
		ft_move(a);
	return (0);
}

int			ft_key_press(int key, t_app *app)
{
	++app->startscreen;
	if (key == 13)
		app->mv_up = 1;
	else if (key == 1)
		app->mv_down = 1;
	else if (key == 2)
		app->mv_right = 1;
	else if (key == 0)
		app->mv_left = 1;
	else if (key == 123)
		app->rt_left = 1;
	else if (key == 124)
		app->rt_right = 1;
	else if (key == 126)
	{
		app->weapon.fire_count = 0;
		app->weapon.is_fired = 1;
	}
	else if (key == 4)
		app->h = (app->h == 1) ? 0 : 1;
	ft_key_press2(key, app);
	return (0);
}

int			ft_key_press2(int key, t_app *app)
{
	if (key == 125)
		app->rt_dw = 1;
	else if (key == 126)
		app->rt_up = 1;
	else if (key == 17)
		app->t = (app->t == 1) ? 0 : 1;
	else if (key == 8)
		app->c = (app->c == 1) ? 0 : 1;
	else if (key == 18)
		app->is_weapon = 1;
	else if (key == 19)
		app->is_weapon = 0;
	else if (key == 257)
		app->speed = 1;
	else if (key == 53)
		exit(0);
	return (0);
}

int			ft_key_release(int key, t_app *app)
{
	if (key == 13)
		app->mv_up = 0;
	else if (key == 1)
		app->mv_down = 0;
	else if (key == 2)
		app->mv_right = 0;
	else if (key == 0)
		app->mv_left = 0;
	else if (key == 123)
		app->rt_left = 0;
	else if (key == 124)
		app->rt_right = 0;
	else if (key == 125)
		app->rt_dw = 0;
	else if (key == 126)
	{
		app->rt_up = 0;
		app->weapon.is_fired = 0;
	}
	else if (key == 257)
		app->speed = 0;
	return (0);
}
