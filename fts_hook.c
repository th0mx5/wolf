/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:15:41 by maxisimo          #+#    #+#             */
/*   Updated: 2018/11/02 16:27:50 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_start_screen(t_app *a)
{
	t_color	c1;
	int		color;

	c1.r = 255;
	c1.g = 255;
	c1.b = 255;
	a->loop = (a->loop < 60) ? a->loop + 1 : 0;
	if (a->loop < 40 && a->startscreen == 0)
	{
		while (a->loop < 40)
			color = ft_rgb_to_hex(c1);
			mlx_string_put(a->mlx, a->win, 450, 300, color, START);
			c1.r -= 6;
			c1.g -= 6;
			c1.b -= 6;
	}
	else if (a->loop >= 40 && a->startscreen == 0)
		mlx_clear_window(a->mlx, a->win);
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
