/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/16 14:34:52 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_keyhooked(int keycode, t_app *app)
{
	t_coord_d old_pos;
	if (keycode == 53)
		exit(0);
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
}

int	ft_mousehooked(int button, int x, int y, t_app *app)
{
	(void)button;
	(void)x;
	(void)y;
	raycasting(app);
	return (0);
}

int	ft_hook(int x, int y, t_app *app)
{
	(void)x;
	(void)y;
	raycasting(app);
	return (0);
}

int	main(int ac, char **av)
{
	t_app	app;

	(void)ac;
	app.fname = av[1];
	ft_app_init(&app);
	app.mlx = mlx_init();
	app.win = mlx_new_window(app.mlx, app.winsize.x, app.winsize.y, "Wolf3D");
	raycasting(&app);
	mlx_key_hook(app.win, ft_keyhooked, &app);
	//mlx_hook(app.win, 6, (1L << 6), ft_hook, &app);
	mlx_loop(app.mlx);
	return (0);
}
