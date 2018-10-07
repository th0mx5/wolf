/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/07 16:35:52 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_var	*v;
	int		n[3];

	if (!(v = (t_var *)malloc(sizeof(t_var))))
		return (-1);
	if (ac == 2)
	{
		v->fname = av[1];
		v->mlx = mlx_init();
		v->win = mlx_new_window(v->mlx, WIN_W, WIN_H, "Wolf3D");
		v->img = mlx_new_image(v->win, WIN_W, WIN_H);
		v->img_data = mlx_get_data_addr(v->img, &n[0], &n[1], &n[2]);
		start(v);
		mlx_hook(v->win, 2, (1L << 0), ft_keyhooked, v);
		mlx_loop(v->mlx);
	}
	return (0);
}
