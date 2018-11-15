/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:15:41 by maxisimo          #+#    #+#             */
/*   Updated: 2018/11/02 17:26:19 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_start_screen(t_app *a)
{
	t_color c;
	int		clr;
	t_color	c1;
	t_coord p;
	int		n[3];
	double	sin_factor;

	p.x = 0;
	a->img = mlx_new_image(a->win, WIN_W, WIN_H);
	a->img_data = mlx_get_data_addr(a->img, &n[0], &n[1], &n[2]);
	a->loop = a->loop + 0.02;
	sin_factor = fabs(sin(a->loop));
	c1.r = sin_factor * 255;
	c1.g = sin_factor * 255;
	c1.b = sin_factor * 255;
	p.y = 1;
	while (p.y < a->startscreen_logo.height * 3)
	{
		p.x = 1;
		while (p.x < a->startscreen_logo.width * 3)
		{
			c = get_pixel_color(&a->startscreen_logo, p.x / 3, p.y / 3);
			clr = ft_rgb_to_hex(c);
			ft_memcpy(a->img_data + 4 * WIN_W * (p.y + WIN_H / 2 - (a->startscreen_logo.height * 3)) + (p.x * 4 + (WIN_W + a->startscreen_logo.width * 3)), &clr, sizeof(int));
			p.x++;
		}
		p.y++;
	}
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	mlx_string_put(a->mlx, a->win, WIN_W / 2 - 150, WIN_H / 2 + 100, ft_rgb_to_hex(c1), START);
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
	else if (key == 125)
		app->rt_dw = 1;
	else if (key == 126)
		app->rt_up = 1;
	else if (key == 4)
	{
		if (app->h == 1)
			app->h = 0;
		else
			app->h = 1;
	}
	ft_key_press2(key, app);
	return (0);
}

int			ft_key_press2(int key, t_app *app)
{
	if (key == 17)
	{
		if (app->t == 1)
			app->t = 0;
		else
			app->t = 1;
	}
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
		app->rt_up = 0;
	else if (key == 257)
		app->speed = 0;
	return (0);
}
