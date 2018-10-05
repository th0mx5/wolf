/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/05 13:11:42 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_keyhooked(int keycode, t_var *v)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		v->pos.x = v->pos.x - 8;
	if (keycode == 124)
		v->pos.x = v->pos.x + 8;
	if (keycode == 125)
		v->pos.y = v->pos.y + 8;
	if (keycode == 126)
		v->pos.y = v->pos.y - 8;
	printf("pos : x = %d, y = %d\n", v->pos.x, v->pos.y);
	ft_win_draw(v);
	return (0);
}

int		ft_mousehooked(int button, int x, int y, t_var *v)
{
	(void)button;
	(void)x;
	(void)y;
	ft_win_draw(v);
	return (0);
}

int		ft_hook(int x, int y, t_var *v)
{
	(void)x;
	(void)y;
	ft_win_draw(v);
	return (0);
}

int		main(int ac, char **av)
{
	t_var	*v;

	if (!(v = (t_var *)malloc(sizeof(t_var))))
		return (-1);
	if (ac == 2)
	{
		v->fname = av[1];
		v->mlx = mlx_init();
		v->win = mlx_new_window(v->mlx, WIN_W, WIN_H, "Wolf3D");
		v->img = mlx_new_image(v->win, WIN_W, WIN_H);
		start(v);
		mlx_key_hook(v->win, ft_keyhooked, &v);
		mlx_mouse_hook(v->win, ft_mousehooked, &v);
		mlx_hook(v->win, 6, (1L << 6), ft_hook, &v);
		mlx_loop(v->mlx);
	}
	return (0);
}
