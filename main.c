/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/16 14:50:48 by maxisimo         ###   ########.fr       */
/*   Updated: 2018/10/16 14:34:52 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_close(t_app *app)
{
	free(app->fname);
	free(app->map);
	free(app);
	exit(0);
	return (0);
}

/*static int	ft_keyhooked(int keycode, t_app *app)
{
	t_coord_d old_pos;
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		app->pos.x = app->pos.x - 30;
	if (keycode == 124)
		app->pos.x = app->pos.x + 30;
	if (keycode == 125)
	old_pos = app->pos;
	if (keycode == 123)
		app->pos.y = app->pos.y - 0.1;
	if (keycode == 124)
		app->pos.y = app->pos.y + 0.1;
	if (keycode == 125)
		app->pos.x = app->pos.x + 0.1;
	if (keycode == 126)
		app->pos.x = app->pos.x - 0.1;
	printf("(%lf, %lf) %d\n", app->pos.x, app->pos.y, ft_is_againstwall(app));
	if (ft_is_againstwall(app))
		app->pos = old_pos;
	raycasting(app);
	return (0);
}*/

static int	ft_key_press(int key, t_app *app)
{
	if (key == 13)
		app->mv_up = 1;
	else if (key == 1)
		app->mv_down = 1;
	else if (key == 2)
		app->rt_right = 1;
	else if (key == 0)
		app->rt_left = 1;
	else if (key == 53)
		exit(0);
	return (0);
}

static int	ft_key_release(int key, t_app *app)
{
	if (key == 13)
		app->mv_up = 0;
	else if (key == 1)
		app->mv_down = 0;
	else if (key == 2)
		app->rt_right = 0;
	else if (key == 0)
		app->rt_left = 0;
	return (0);
}

static void	ft_move_side(t_app *a)
{
	if (a->rt_right == 1)
	{
		a->oldDirX = a->dirX;
		a->dirX = a->dirX * cos(-0.05) - a->dirY * sin(-0.05);
		a->dirY = a->oldDirX * sin(-0.05) + a->dirY * cos(-0.05);
		a->oldPlaneX = a->planeX;
		a->planeX = a->planeX * cos(-0.05) - a->planeY * sin(-0.05);
		a->planeY = a->oldPlaneX * sin(-0.05) + a->planeY * cos(-0.05);
	}
	if (a->rt_left == 1)
	{
		a->oldDirX = a->dirX;
		a->dirX = a->dirX * cos(0.05) - a->dirY * sin(0.05);
		a->dirY = a->oldDirX * sin(0.05) + a->dirY * cos(0.05);
		a->oldPlaneX = a->planeX;
		a->planeX = a->planeX * cos(0.05) - a->planeY * sin(0.05);
		a->planeY = a->oldPlaneX * sin(0.05) + a->planeY * cos(0.05);
	}
}

static int	ft_move(t_app *a)
{
	if (a->mv_up == 1)
	{
		if (a->map[(int)(a->pos.x + a->dirX * a->ms)][(int)(a->pos.y)] == 0)
			a->pos.x += a->dirX * a->ms;
		if (a->map[(int)(a->pos.x)][(int)(a->pos.y + a->dirY * a->ms)] == 0)
			a->pos.y += a->dirY * a->ms;
	}
	if (a->mv_down == 1)
	{
		if (a->map[(int)(a->pos.x - a->dirX * a->ms)][(int)(a->pos.y)] == 0)
			a->pos.x -= a->dirX * a->ms;
		if (a->map[(int)(a->pos.x)][(int)(a->pos.y - a->dirY * a->ms)] == 0)
			a->pos.y -= a->dirY * a->ms;
	}
	ft_move_side(a);
	raycasting(a);
	return (0);
}

int			main(int ac, char **av)
{
	t_app	app;

	(void)ac;
	app.fname = av[1];
	ft_app_init(&app);
	app.mlx = mlx_init();
	app.win = mlx_new_window(app.mlx, app.winsize.x, app.winsize.y, "Wolf3D");
	raycasting(&app);
	mlx_hook(app.win, 2, (1L << 0), ft_key_press, &app);
	mlx_hook(app.win, 3, (1L << 1), ft_key_release, &app);
	mlx_hook(app.win, 17, (1L << 17), ft_close, &app);
	mlx_loop_hook(app.mlx, ft_move, &app);
	mlx_loop(app.mlx);
	return (0);
}
