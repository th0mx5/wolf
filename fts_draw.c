/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/09/13 22:17:23 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_win_draw(t_app *app)
{
	t_coord	p;
	int		n[3];
	int		de;
	int		hm;
	int		hp;
	int		i_min;
	int		i_max;
	p.x = 0;
	p.y = 0;
	de = 277;
	hm = 64;
	hp = de * hm / 288;
	app->img = mlx_new_image(app->win, app->winsize.x, app->winsize.y);
	app->img_data = mlx_get_data_addr(app->img, &n[0], &n[1], &n[2]);;

	while (p.y < app->winsize.y)
	{
		i_min = 160 - hp / 2;
		i_max = 160 + hp / 2;
		p.x = 0;
		while (p.x < app->winsize.x)
		{
			if (p.y < i_min || p.y > i_max)
				ft_img_putpixel(app, p, 0xFFFFFF);
			else
				ft_img_putpixel(app, p, 0x00000);
			p.x++;
		}
		p.y++;
	}

	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
	mlx_destroy_image(app->mlx, app->img);
	mlx_do_sync(app->mlx);
}

void	ft_img_putpixel(t_app *app, t_coord p, int color)
{
	int i;

	i = (p.x + (p.y * app->winsize.x)) * 4;
	if (p.x > -1 && p.y > -1 && p.x < app->winsize.x && p.y < app->winsize.y)
	{
		app->img_data[i] = color;
	}
}

void	ft_calc_color(t_app *app, t_coord p)
{
	(void)app;
	(void)p;
}
