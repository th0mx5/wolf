/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/07 14:39:16 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_win_draw(t_var *v)
{
	int		n[3];
	/*int		de;
	int		hm;
	int		hp;
	int		i_min;
	int		i_max;
	p.x = 0;
	p.y = 0;
	de = 277;
	hm = 64;
	hp = de * hm / 288;*/

	v->img = mlx_new_image(v->win, v->winsize.x, v->winsize.y);
	v->img_data = mlx_get_data_addr(v->img, &n[0], &n[1], &n[2]);;

	

	/*while (p.y < app->winsize.y)
	{
		i_min = 100 - hp / 2;
		i_max = 100 + hp / 2;
		p.x = 0;
		while (p.x < app->winsize.x)
		{
			if (p.y < i_min || p.y > i_max)
				ft_img_putpixel(app, p, 0xFFFFFF);
			else
				ft_img_putpixel(app, p, 0x000000);
			p.x++;
		}
		p.y++;
	}*/

	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	mlx_destroy_image(v->mlx, v->img);
	mlx_do_sync(v->mlx);
}

/*void	ft_img_putpixel(t_var *v, t_coord p, int color)
{
	int i;

	i = (p.x + (p.y * v->winsize.x)) * 4;
	if (p.x > -1 && p.y > -1 && p.x < v->winsize.x && p.y < v->winsize.y)
	{
		v->img_data[i] = color;
	}
}*/

void	ft_calc_color(t_var *v, t_coord p)
{
	(void)v;
	(void)p;
}
