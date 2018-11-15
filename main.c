/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/11/02 16:06:44 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int ac, char **av)
{
	t_app	app;

	if (ac == 2)
	{
		app.fname = av[1];
		ft_app_init(&app);
		app.mlx = mlx_init();
		app.win = mlx_new_window(app.mlx, WIN_W, WIN_H, "Wolf3D");
		load_bmp(&app.startscreen_logo, "textures/logo.bmp");
		mlx_hook(app.win, 2, (1L << 0), ft_key_press, &app);
		mlx_hook(app.win, 3, (1L << 1), ft_key_release, &app);
		mlx_hook(app.win, 17, (1L << 17), ft_close, &app);
		mlx_loop_hook(app.mlx, expose_hook, &app);
		mlx_loop(app.mlx);
	}
	return (0);
}
